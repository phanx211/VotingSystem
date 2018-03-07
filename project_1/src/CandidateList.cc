/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

#include "CandidateList.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

CandidateList::CandidateList() {
  candidate_list = NULL;
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
  candidate_list.erase(myvector.begin()+i);

}

Candidate CandidateList::ReturnLoser(std::string name){

}

int CandidateList::ListSize(){
  return candidate_list.size();
}
