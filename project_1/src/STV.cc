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

int STV::get_index(vector<int> v, int n) {
  int index = -1;
  for (int i=0; i<v.size();i++) {
    if (v[i] == n) {
      index = i;
      break;
    }
  }
  return index;
}

string STV::ReturnNameOfVote(Ballot b) {

  int n=1;
  string name = "NONE";
  // Iterate through the vector representing the votes
  int index = get_index(b.get_votes(),n);
  while (name == "NONE") {
    // If index is -1, that means the ballot has less than the max # of rankings
    // In this case, we return a string to indicate the disposal of that ballot
    if (index == -1) {
      return "DELETE";
    }
    // If the current highest vote belongs to a candidate in the elected or non-elected list,
    // look at the next highest vote
    else if (!get_candidates().ThereExists(get_names()[index])) {
      n++;
      index = get_index(b.get_votes(),n);
    }
    // This last case means that the highest vote belongs to a candidate in neither
    // list thus we return the name of that candidate.
    else {
      name = get_names()[index];
    }
  }
  // for (unsigned i=0; i<b.get_votes().size(); i++) {
  //   if (b.get_votes()[i]==n) {
  //     // If that candidate is in the winners list already, search for next preference
  //     if (get_elected().ThereExists(get_names()[i]) || get_non_elected().ThereExists(get_names()[i])) {
  //       ReturnNameOfVote(b, n);
  //     }
  //     else {
  //       return get_names()[i];
  //     }
  //   }
  // }
  // If reaches here, then we did not find that vote in the ballot
  return name;
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
	dst.Add(temp);;
}

void STV::CalculateDroop() {
  droop = floor(get_num_ballots()/(get_num_seats()+1)) + 1;

}
void STV::Algorithm() {
  int rnd=1;
  int bal_no;
  string highest_name;
  int itr=get_num_ballots();

  // While seats are not filled
  while (get_elected().ListSize()!=get_num_seats()) {
    if (get_candidates().ListSize() == 0) {
      break;
    }
    std::cout << "Round "<< rnd << '\n';
    // std::cout << "Ballot size is " << '\n';
    for (unsigned i = 0; i < itr; i++) {
      // Gets the highest preference
      highest_name=ReturnNameOfVote(get_ballots().get_ballot_list()[0]);
      if (highest_name == "DELETE") {
        get_ballots().RemoveBallot(get_ballots().get_ballot_list()[0].get_ballot_no());
      }
      else {

        std::cout << "Distributing Ballot " <<get_ballots().get_ballot_list()[0].get_ballot_no();
        std::cout << " to " << highest_name << '\n';

        // Gets ballot no of current ballot
        bal_no=get_ballots().get_ballot_list()[0].get_ballot_no();

        Candidate& receiver = get_candidates().ReturnCandidate(highest_name);
        // Moves Ballot from 'ballots' to candidate using the ballot no in 'bal_no'
        MoveBallot(bal_no, get_ballots(), receiver.get_votes());

        // CHECK IF REACHES DROOP
        if (receiver.get_votes().ListSize()==droop) {
          std::cout << receiver.get_name() << " reached Droop!!!" << '\n';
          MoveCandidate(highest_name, get_candidates(),get_elected());
        }
      }
    }

    // REMOVE ALL WITH ZERO VOTES
    for (unsigned i = 0; i < get_candidates().get_candidate_list().size(); i++) {
      if (get_candidates().get_candidate_list()[i].get_num_ballots()==0) {
        MoveCandidate(get_candidates().get_candidate_list()[i].get_name(), get_candidates(),get_non_elected());
        i--;
      }

    }

    // HANDLING OF LOSER IF THERE IS ONE
    if (get_candidates().ListSize() > 0) {
      string losername=get_candidates().ReturnLoser().get_name();
      std::cout << "LOSER IS "<<losername;
      std::cout << " with size " << get_candidates().ReturnLoser().get_votes().ListSize() <<'\n';

      // Move ballots from loser pile, back to STV ballot pile
      int LoserSize=get_candidates().ReturnLoser().get_votes().ListSize();
      for (unsigned i = 0; i < LoserSize; i++) {
        MoveBallot(get_candidates().ReturnLoser().get_votes().get_ballot_list()[0].get_ballot_no(), get_candidates().ReturnLoser().get_votes(), get_ballots());
      }

      MoveCandidate(losername, get_candidates(),get_non_elected());
    }
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
  // std::cout << "TRUE WINNER IS " << get_elected().get_candidate_list()[0].get_name();
  // std::cout << " WITH " <<  get_elected().get_candidate_list()[0].get_votes().ListSize() << " VOTES" <<'\n';
  // vector<Candidate> winners = get_candidates().ReturnWinners(get_num_seats());
  cout << "Droop: " << droop << endl;
  if (get_num_seats() > 1) {
	cout << "THE WINNERS ARE: ";
  }
  else {
  	  cout << "THE WINNER IS: ";
  }
  for (unsigned i = 0; i<get_elected().ListSize(); i++) {
    cout << get_elected().get_candidate_list()[i].get_name();
	if (i<get_elected().ListSize()-1) {
		cout << ", ";
	}
  }
  cout << endl;




}
