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
#include "../include/STV.h"

using namespace std;

STV::STV() : Election() {}

STV::STV(int num_seats, int num_candidates, int num_ballots) : Election(num_seats, num_candidates, num_ballots) {
  CalculateDroop();
}

string STV::ReturnNameOfVote(Ballot b, int n) {

  // This happens when a voter has no more preference
  if (n>b.get_preferences()) {
    return "DELETE";
  }

  // Technically we can just look for 1 but This might be useful for STV
  // Finds the index where the higehest vote exists
  for (unsigned i=0; i<b.get_votes().size(); i++) {
    if (b.get_votes()[i]==n) {
      // If that candidate is in the winners list already, search for next preference
      if (get_elected().ThereExists(get_names()[i]) || get_non_elected().ThereExists(get_names()[i])) {
        ReturnNameOfVote(b, n+1);
      }
      else {
        return get_names()[i];
      }
    }
  }
  // If reaches here, then we did not find that vote in the ballot
  return "Not supposed to show up";
}

string STV::ReturnNameOfHighest(Ballot b) {

  int min=99;
  int min_index=0;

  // Technically we can just look for 1 but This might be useful for STV
  // Finds the index where the higehest vote exists
  for (unsigned i=0; i<b.get_votes().size(); i++) {
    if (b.get_votes()[i]!=0 && b.get_votes()[i]<min) {
      min=b.get_votes()[i];
      min_index=i;
      // If that candidate is in the winners list already, search for next preference
      if (get_elected().ThereExists(get_names()[i]) || get_non_elected().ThereExists(get_names()[i])) {
        b.get_votes()[i]=99;
      }
    }
  }
  int temp=min_index;
  b.get_votes()[temp]=99;
  return get_names()[min_index];
  // If reaches here, then we did not find that vote in the ballot


}

void STV::MoveCandidate(string can_name, CandidateList& src, CandidateList& dst) {
	Candidate temp=src.Remove(can_name);
	dst.Add(temp);
}

void STV::CalculateDroop() {
  droop = floor(get_num_ballots()/(get_num_seats()+1)) + 1;

}
void STV::Algorithm() {
  int rnd=1;
  int bal_no;
  string highest_name;
  int itr=get_num_ballots();

  // While there is no winner
  while (get_elected().ListSize()!=get_num_seats()) {
    std::cout << "Round "<< rnd << '\n';
    // std::cout << "Ballot size is " << '\n';
    for (unsigned i = 0; i < itr; i++) {
      std::cout << "iteration of " << rnd << '\n';
      // Gets the highest vote index in a given ballot from 'ballots'
      if (rnd == 3) {
        highest_name=ReturnNameOfVote(get_ballots().get_ballot_list()[0],2);
      }
      else {
        highest_name=ReturnNameOfVote(get_ballots().get_ballot_list()[0],rnd);
      }
      std::cout << "Distributing Ballot " <<get_ballots().get_ballot_list()[0].get_ballot_no();
      std::cout << " to " << highest_name << '\n';

      // Gets ballot no of current ballot
      bal_no=get_ballots().get_ballot_list()[0].get_ballot_no();

      Candidate& receiver = get_candidates().ReturnCandidate(highest_name);
      // Moves Ballot from 'ballots' to candidate using the ballot no in 'bal_no'
      MoveBallot(bal_no, get_ballots(), receiver.get_votes());

      // CHECK IF REACHES DROOP
      if (receiver.get_votes().ListSize()==droop) {
        std::cout << "Droop is " << receiver.get_name() << '\n';
        std::cout << "REACHED DROOP!!" << '\n';
        MoveCandidate(highest_name, get_candidates(),get_elected());
      }
    }

    // REMOVE ALL WITH ZERO VOTES
    for (unsigned i = 0; i < get_candidates().get_candidate_list().size(); i++) {
      if (get_candidates().get_candidate_list()[i].get_num_ballots()==0) {
        MoveCandidate(get_candidates().get_candidate_list()[i].get_name(), get_candidates(),get_non_elected());
        i--;
      }

    }

    // HANDLING OF LOSER
    std::cout << "LOSER IS "<<get_candidates().ReturnLoser().get_name() << '\n';
    for (unsigned i = 0; i < get_candidates().ReturnLoser().get_votes().ListSize(); i++) {
      MoveBallot(get_candidates().ReturnLoser().get_votes().get_ballot_list()[i].get_ballot_no(),get_candidates().ReturnLoser().get_votes(),get_ballots());
    }
    MoveCandidate(get_candidates().ReturnLoser().get_name(), get_candidates(),get_non_elected());
    itr=get_ballots().ListSize();


    // DEBUGGING PRINTS
    std::cout << "Candidate size is " <<get_candidates().get_candidate_list().size() << '\n';
    std::cout << "###STILL IN THE RUN###" << '\n';
    for (unsigned i = 0; i < get_candidates().get_candidate_list().size(); i++) {
      cout << get_candidates().get_candidate_list()[i].get_name();
      cout << " Votes: " << get_candidates().get_candidate_list()[i].get_votes().ListSize() << endl;
    }
    std::cout << "###ELECTED###" << '\n';
    for (unsigned i = 0; i < get_elected().get_candidate_list().size(); i++) {
      cout << get_elected().get_candidate_list()[i].get_name();
      cout << " Votes: " << get_elected().get_candidate_list()[i].get_votes().ListSize() << endl;
    }

    std::cout << "###NON ELECTED###" << '\n';
    for (unsigned i = 0; i < get_non_elected().get_candidate_list().size(); i++) {
      cout << get_non_elected().get_candidate_list()[i].get_name();
      cout << " Votes: " << get_non_elected().get_candidate_list()[i].get_votes().ListSize() << endl;
    }
    std::cout << "UNACCOUNTED VOTES IN THE MIX: " << get_ballots().ListSize() << '\n';

    rnd++;
  }


  // Run the ReturnWinners function from candidate_list which will fill a winner
  // vector with the candidates that won the seats
  std::cout << "TRUE WINNER IS " << get_elected().get_candidate_list()[0].get_name();
  std::cout << " WITH " <<  get_elected().get_candidate_list()[0].get_votes().ListSize() << " VOTES" <<'\n';
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
