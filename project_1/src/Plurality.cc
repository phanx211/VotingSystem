/*!******************************************************************************
 * Name            : BallotList.cc
 * Project         : Voting System
 * Description     : Implementation file for BallotList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../include/Plurality.h"

using namespace std;

Plurality::Plurality() : Election() {}

Plurality::Plurality(int num_seats, int num_candidates, int num_ballots) : Election(num_seats, num_candidates, num_ballots) {}

int Plurality::ReturnHighestVoteIndex(Ballot b) {
  int min=b.get_votes()[0];
  int min_index=0;

  // Technically we can just look for 1 but This might be useful for STV
  // Finds the index where the higehest vote exists
  for (unsigned i=0; i<b.get_votes().size(); i++){
    if (b.get_votes()[i]!=0 && b.get_votes()[i]<min) {
      min=b.get_votes()[i];
      min_index=i;
    }
  }
  return min_index;
}

void Plurality::Algorithm() {
  int bal_no;
  int highest_index;

  // The following loop goes through the original list of ballots and distributes
  // the ballots to the respective candidate based on the rankings on the ballot
  for (int i = 0; i < get_num_ballots(); i++) {
    // Gets the highest vote index in a given ballot from 'ballots'
    highest_index=ReturnHighestVoteIndex(get_ballots().get_ballot_list()[0]);

    // Gets ballot no of current ballot
    bal_no=get_ballots().get_ballot_list()[0].get_ballot_no();

    // Moves Ballot from 'ballots' to candidate using the ballot no in 'bal_no'
    MoveBallot(bal_no, get_ballots(), get_candidates().get_candidate_list()[highest_index].get_votes());
  }

  for (int i = 0; i < get_candidates().get_candidate_list().size(); i++) {
    cout << "Candidate: " << i << " Votes: " << get_candidates().get_candidate_list()[i].get_votes().ListSize() << endl;
  }

  // Run the ReturnWinners function from candidate_list which will fill a winner
  // vector with the candidates that won the seats
  vector<Candidate> winners = get_candidates().ReturnWinners(get_num_seats());
  cout << "WINNER[S] ARE: ";
  for (int i = 0; i<winners.size(); i++) {
    cout << winners[i].get_name() << ", ";
  }
  cout << endl;

}
