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

void CandidateList::Add(Candidate c) {
  candidate_list.push_back(c);
}

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

Candidate CandidateList::ReturnWinner() {
  Candidate highest=candidate_list[0];
  for (int i=0;i<candidate_list.size();i++) {
    if (candidate_list.at(i).get_num_ballots()>highest.get_num_ballots()) {
      highest=candidate_list.at(i);
    }
  }
  return highest;
}

vector<Candidate> CandidateList::ReturnWinners(int no_seats) {
  vector<Candidate> winners;
  int random = rand() % candidate_list.size();
  random = rand() % candidate_list.size();
  for (int k = 0; k < random; k++) {
    random_shuffle(candidate_list.begin(),candidate_list.end());
  }
  Candidate highest=candidate_list[0];
  for (int j = 0; j<no_seats; j++) {
    for (int i=0;i<candidate_list.size();i++) {
      if (candidate_list.at(i).get_num_ballots()>highest.get_num_ballots()) {
        highest=candidate_list.at(i);
      }
    }
    winners.push_back(this->Remove(highest.get_name()));
    highest = candidate_list[0];
  }
  return winners;
}


int CandidateList::ListSize(){
  return candidate_list.size();
}
