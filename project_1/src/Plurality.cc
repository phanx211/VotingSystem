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
  int min=999;
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
// The plurality algorithm reads the ballots and distributes them to the respective candidates.
// It then calls ReturnWinners which will return the winners of the seats
void Plurality::Algorithm() {
  int bal_no;
  int highest_index;

  // The following loop goes through the original list of ballots and distributes
  // the ballots to the respective candidate based on the rankings on the ballot
  int ballots = get_num_ballots();
  for (int i = 0; i < ballots; i++) {
    // Gets the highest vote index in a given ballot from 'ballots'
    highest_index=ReturnHighestVoteIndex(get_ballots().get_ballot_list()[0]);

    // Gets ballot no of current ballot
    bal_no=get_ballots().get_ballot_list()[0].get_ballot_no();

    // Moves Ballot from 'ballots' to candidate using the ballot no in 'bal_no'
    MoveBallot(bal_no, get_ballots(), get_candidates().get_candidate_list()[highest_index].get_votes());
  }

  for (unsigned i = 0; i < get_candidates().get_candidate_list().size(); i++) {
    cout << "Candidate: " << i << " Votes: " << get_candidates().get_candidate_list()[i].get_votes().ListSize() << endl;
  }

  // Run the ReturnWinners function from candidate_list which will fill a winner
  // vector with the candidates that won the seats
  vector<Candidate> winners = get_candidates().ReturnWinners(get_num_seats());
  if (get_num_seats() > 1) {
	cout << "THE WINNERS ARE: ";
  }
  else {
  	  cout << "THE WINNER IS: ";
  }
  for (unsigned i = 0; i<winners.size(); i++) {
    cout << winners[i].get_name();
  	if (i<winners.size()-1) {
  		cout << ", ";
  	}
  }
  cout << endl;

}
