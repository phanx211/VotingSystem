/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

#include "../include/CandidateList.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

CandidateList::CandidateList() {
}

void CandidateList::Add(Candidate c) {
  candidate_list.push_back(c);
}

Candidate CandidateList::Remove(std::string name) {
  int i=0;
	Candidate temp;
	for (Candidate c:candidate_list) {
		if (c.get_name() == name) {
			temp = candidate_list.at(i);
			candidate_list.erase(candidate_list.begin()+i);
			break;
		}
		i++;
	}
	return temp;
}

Candidate CandidateList::ReturnLoser() {
  Candidate lowest=candidate_list.front();
  for (Candidate c:candidate_list) {
    if (c.get_num_ballots()<lowest.get_num_ballots()) {
      lowest=c;
    }
    else if (c.get_num_ballots()==lowest.get_num_ballots()) {
      if (c.get_votes().get_ballot_list().back().get_ballot_no()<lowest.get_votes().get_ballot_list().back().get_ballot_no()) {
        lowest=c;
      }
    }
  }
  return lowest;
}


int CandidateList::ListSize(){
  return candidate_list.size();
}

int main(){
  return 0;
}
