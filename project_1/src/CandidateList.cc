/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

#include "include/CandidateList.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

CandidateList::CandidateList() {
  candidate_list = new std::vector<> ;
}

void CandidateList::Add(Candidate c) {
  candidate_list.push_back(c);
}

Candidate CandidateList::Remove(std::string name) {
  int i=0;
  for (Candidate c:candidate_list) {
    if (c.get_name()!=name) {
      i++;
    }
    else {
      break;
    }
  }
  Candidate temp = candidate_list.at(i);
  candidate_list.erase(candidate_list.begin()+i);
  return temp;

}

Candidate CandidateList::ReturnLoser(std::string name) {
  Candidate lowest=candidate_list.front();
  for (Candidate c:candidate_list) {
    if (c.get_num_ballots()<lowest.get_num_ballots()) {
      lowest=c;
    }
    else if (c.get_num_ballots()==lowest.get_num_ballots()) {
      if (c.get_votes().front().get_ballot_no()<lowest.get_votes().front().get_ballot_no()) {
        lowest=c;
      }
    }
  }
  return c;
}


int CandidateList::ListSize(){
  return candidate_list.size();
}
