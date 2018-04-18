/*!******************************************************************************
 * Name            : STV.cc
 * Project         : Voting System
 * Description     : Implementation file for STV
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

STV::STV(int num_seats, int num_candidates, int num_ballots)
    : Election(num_seats, num_candidates, num_ballots) {
  CalculateDroop();
}

// This function returns the index of a number in an integer vector.
int STV::get_index(vector<int> v, int n) {
  int index = -1;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == n) {
      index = i;
      break;
    }
  }
  return index;
}

// This function returns the name of a candidate that a ballot should
// go to.
string STV::ReturnNameOfVote(Ballot b) {
  int n = 1;
  string name = "NONE";
  // Iterate through the vector representing the votes
  int index = get_index(b.get_votes(), n);
  while (name == "NONE") {
    // If index is -1, that means the ballot has less than the max # of rankings
    // In this case, we return a string to indicate the disposal of that ballot
    if (index == -1) {
      return "DELETE";
    }
    // If the current highest vote belongs to a candidate in the elected or
    // non-elected list,
    // look at the next highest vote
    else if (!get_candidates().ThereExists(get_names()[index])) {
      n++;
      index = get_index(b.get_votes(), n);
    }
    // This last case means that the highest vote belongs to a candidate in
    // neither
    // list thus we return the name of that candidate.
    else {
      name = get_names()[index];
    }
  }
  return name;
}

// Moves a candidate from a source list to a destination list.
void STV::MoveCandidate(string can_name, CandidateList& src,
                        CandidateList& dst) {
  Candidate temp = src.Remove(can_name);
  dst.Add(temp);
  ;
}

void STV::CalculateDroop() {
  droop = floor(get_num_ballots() / (get_num_seats() + 1)) + 1;
}

void STV::Algorithm() {
  int rnd = 1;
  int bal_no;
  string highest_name;
  int itr = get_num_ballots();
  std::cout << "Validating Ballots: " << '\n';

  int half;
  // If odd
  if (get_num_candidates()%2) {
    half=(get_num_candidates()/2)+1;
  }
  else {
    half=(get_num_candidates()/2);
  }
  get_ballots().ValidateBallots(half);
  // Sets num_ballots to new value
  set_num_ballots(get_ballots().get_ballot_list().size());
  // Recalculate Droop
  CalculateDroop();




  // Shuffle ballots before running election
  get_ballots().ShuffleBallots();




  // While seats are not filled
  while (get_elected().ListSize() != get_num_seats()) {
    if (get_candidates().ListSize() == 0) {
      break;
    }
    std::cout << "Round " << rnd << '\n';

    // This for loop handles all the ballots in the unassigned pile. It
    // iterates until all ballots have been distributed to some candidate.
    for (unsigned i = 0; i < itr; i++) {
      // Gets the highest preference
      highest_name = ReturnNameOfVote(get_ballots().get_ballot_list()[0]);
      if (highest_name == "DELETE") {
        get_ballots().RemoveBallot(
            get_ballots().get_ballot_list()[0].get_ballot_no());
      } else {
        std::cout << "Distributing Ballot "
                  << get_ballots().get_ballot_list()[0].get_ballot_no();
        std::cout << " to " << highest_name << '\n';

        // Gets ballot no of current ballot
        bal_no = get_ballots().get_ballot_list()[0].get_ballot_no();

        Candidate& receiver = get_candidates().ReturnCandidate(highest_name);
        // Moves Ballot from 'ballots' to candidate using the ballot no in
        // 'bal_no'
        MoveBallot(bal_no, get_ballots(), receiver.get_votes());

        // CHECK IF REACHES DROOP
        if (receiver.get_votes().ListSize() == droop) {
          std::cout << receiver.get_name() << " reached Droop!!!" << '\n';
          MoveCandidate(highest_name, get_candidates(), get_elected());
        }
      }
    }

    // Elliminate all candidates who don't have any votes for them.
    for (unsigned i = 0; i < get_candidates().get_candidate_list().size();
         i++) {
      if (get_candidates().get_candidate_list()[i].get_num_ballots() == 0) {
        MoveCandidate(get_candidates().get_candidate_list()[i].get_name(),
                      get_candidates(), get_non_elected());
        i--;
      }
    }

    // HANDLING OF LOSER IF THERE IS ONE
    if (get_candidates().ListSize() > 0) {
      string losername = get_candidates().ReturnLoser().get_name();
      std::cout << "LOSER IS " << losername;
      std::cout << " with size "
                << get_candidates().ReturnLoser().get_votes().ListSize()
                << '\n';

      // Move ballots from loser pile, back to STV ballot pile
      int LoserSize = get_candidates().ReturnLoser().get_votes().ListSize();
      for (unsigned i = 0; i < LoserSize; i++) {
        MoveBallot(get_candidates().ReturnLoser().get_votes().get_ballot_list()
                       [0].get_ballot_no(),
                   get_candidates().ReturnLoser().get_votes(), get_ballots());
      }

      MoveCandidate(losername, get_candidates(), get_non_elected());
    }
    itr = get_ballots().ListSize();

    // DEBUGGING PRINTS
    std::cout << "Candidate size is "
              << get_candidates().get_candidate_list().size() << '\n';
    std::cout << "###STILL IN THE RUN###" << '\n';
    for (unsigned i = 0; i < get_candidates().get_candidate_list().size();
         i++) {
      cout << get_candidates().get_candidate_list()[i].get_name();
      cout << " Votes: "
           << get_candidates().get_candidate_list()[i].get_votes().ListSize()
           << endl;
    }
    std::cout << "###ELECTED###" << '\n';
    for (unsigned i = 0; i < get_elected().get_candidate_list().size(); i++) {
      cout << get_elected().get_candidate_list()[i].get_name();
      cout << " Votes: "
           << get_elected().get_candidate_list()[i].get_votes().ListSize()
           << endl;
    }

    std::cout << "###NON ELECTED###" << '\n';
    for (unsigned i = 0; i < get_non_elected().get_candidate_list().size();
         i++) {
      cout << get_non_elected().get_candidate_list()[i].get_name();
      cout << " Votes: "
           << get_non_elected().get_candidate_list()[i].get_votes().ListSize()
           << endl;
    }
    std::cout << "UNACCOUNTED VOTES IN THE MIX: " << get_ballots().ListSize()
              << '\n';

    rnd++;
  }

  // This section writes to the log file.
  cout << "Droop: " << droop << endl;
  if (get_num_seats() > 1) {
    cout << "THE WINNERS ARE: ";
  } else {
    cout << "THE WINNER IS: ";
  }
  for (unsigned i = 0; i < get_elected().ListSize(); i++) {
    cout << get_elected().get_candidate_list()[i].get_name();
    if (i < get_elected().ListSize() - 1) {
      cout << ", ";
    }
  }
  cout << endl;

  freopen("/dev/tty", "a", stdout); // This command redirects print
                                    // statements to the console
                                    // so the following section is displayed.
  cout << endl << "##########################################" << endl;
  if (get_num_seats() > 1) {
    cout << "THE WINNERS ARE: ";
  } else {
    cout << "THE WINNER IS: ";
  }
  for (unsigned i = 0; i < get_elected().ListSize(); i++) {
    cout << get_elected().get_candidate_list()[i].get_name();
    if (i < get_elected().ListSize() - 1) {
      cout << ", ";
    }
  }
  cout << endl << "##########################################" << endl;
  cout << endl;
}
