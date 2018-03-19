/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

#include "../include/CandidateList.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

using namespace std;

CandidateList::CandidateList() {
}

// Adds a candidate to the vector of candidates
void CandidateList::Add(Candidate c) {
  candidate_list.push_back(c);
}

// Removes a candidate from the vector by their name and returns that candidate
Candidate CandidateList::Remove(std::string name) {
	Candidate temp;
	for (int i = 0; i<candidate_list.size();i++ ) {
		if (candidate_list.at(i).get_name() == name) {
			temp = candidate_list.at(i);
			candidate_list.erase(candidate_list.begin()+i);
			break;
		}
	}
	return temp;
}

// Returns a single candidate with the lowest amount of votes
Candidate CandidateList::ReturnLoser() {
  Candidate lowest=candidate_list.front();
  for (int i = 0; i<candidate_list.size();i++) {
    if (candidate_list.at(i).get_num_ballots()<lowest.get_num_ballots()) {
      lowest=candidate_list.at(i);
    }
    else if (candidate_list.at(i).get_num_ballots()==lowest.get_num_ballots()) {
      if (candidate_list.at(i).get_votes().get_ballot_list().back().get_ballot_no()<lowest.get_votes().get_ballot_list().back().get_ballot_no()) {
        lowest=candidate_list.at(i);
      }
    }
  }
  return lowest;
}

// Returns a single candidate with the most votes
Candidate CandidateList::ReturnWinner() {
  Candidate highest=candidate_list[0];
  for (int i=0;i<candidate_list.size();i++) {
    if (candidate_list.at(i).get_num_ballots()>highest.get_num_ballots()) {
      highest=candidate_list.at(i);
    }
  }
  return highest;
}

// Returns a vector of candidates. The number of candidates in the vector is the
// number of seats in the election. This method handles randomizing winners in the case
// of tie votes by randomizing the order of the candidates prior to distributing
// votes. This is done because if two candidates have the same number of votes,
// the first one that is checked is the one that gets priority.
vector<Candidate> CandidateList::ReturnWinners(int no_seats) {
  vector<Candidate> winners;

  // Randomizes the order of the list of candidates
  int random = rand() % candidate_list.size();
  for (int k = 0; k < random; k++) {
    random_shuffle(candidate_list.begin(),candidate_list.end());
  }

  // highest is used to store the candidate with the most number of votes
  Candidate highest=candidate_list[0];
  // Loop runs for the number of seats
  for (int j = 0; j<no_seats; j++) {
    // Loops through all the candidates currently in the list of candidates
    // and finds the one with the most votes
    for (int i=0;i<candidate_list.size();i++) {
      if (candidate_list.at(i).get_num_ballots()>highest.get_num_ballots()) {
        highest=candidate_list.at(i);
      }
    }
    // Removes the candidate with the most votes from the original candidate list
    // and adds them to a winners list
    winners.push_back(this->Remove(highest.get_name()));

    // Reset the candidate with the most votes to the first one in the updated
    // candidate list
    highest = candidate_list[0];
  }
  return winners;
}


int CandidateList::ListSize(){
  return candidate_list.size();
}
