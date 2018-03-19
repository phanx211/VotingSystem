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

  /* Go through ballots in Ballot List, find highest vote
  and move that Ballot from votes into the respective Candidate
  */
  // Candidate a("a", 0);
  // Candidate b("b", 0);
  // Candidate c("c", 0);
  // Candidate d("d", 0);
  // Candidate e("e", 0);
  // Candidate f("f", 0);
  // Candidate g("g", 0);
  // Candidate h("h", 0);
  // Candidate i("i", 0);
  //
  // candidates.Add(a);
  // candidates.Add(b);
  // candidates.Add(c);
  // candidates.Add(d);
  // candidates.Add(e);
  // candidates.Add(f);
  // candidates.Add(g);
  // candidates.Add(h);
  // candidates.Add(i);

  int temp;
  int highest;

  // 'ballots' refer to intial ballots from csv file
  for (int i = 0; i < ballots.ListSize(); i++) {
    // Gets the highest vote index in a given ballot from 'ballots'
    highest=ReturnHighestVoteIndex(ballots.get_ballot_list()[i]);

    // Uses that index to get the ballot no of the highest vote
    temp=ballots.get_ballot_list()[i].get_ballot_no();

    // Moves Ballot from 'ballots' to candidate using the ballot no in 'temp'
    MoveBallot(temp, ballots, candidates.get_candidate_list()[highest].get_votes());
  }


  std::cout << "WINNER IS " << candidates.ReturnWinner().get_name() << '\n';


}
