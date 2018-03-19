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
  cout << "Number of seats: " << get_num_seats() << endl;
  cout << "Ballot list size: " << get_ballots().ListSize() << endl;
  // 'ballots' refer to intial ballots from csv file

  for (int i = 0; i < get_ballots().ListSize(); i++) {
    // Gets the highest vote index in a given ballot from 'ballots'
    highest_index=ReturnHighestVoteIndex(get_ballots().get_ballot_list()[i]);

    // Gets ballot no of current ballot
    bal_no=get_ballots().get_ballot_list()[i].get_ballot_no();

    // Moves Ballot from 'ballots' to candidate using the ballot no in 'bal_no'
    MoveBallot(bal_no, get_ballots(), get_candidates().get_candidate_list()[highest_index].get_votes());
  }

  for (int i = 0; i < get_candidates().get_candidate_list().size(); i++) {
    cout << "Candidate: " << i << " Votes: " << get_candidates().get_candidate_list()[i].get_votes().ListSize() << endl;
  }
  cout << "WINNER IS " << get_candidates().ReturnWinner().get_name() << '\n';


}
