/*!******************************************************************************
 * Name            : CandidateList.h
 * Project         : Voting System
 * Description     : Header file for CandidateList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

 /*******************************************************************************
  * Includes
  ******************************************************************************/
 #include <cmath>
 #include <iostream>
 #include <vector>
 #include <string>

 #include "Candidate.h"
 #include "BallotList.h"

 /*******************************************************************************
  * Class Definitions
  ******************************************************************************/

class CandidateList {
public:
  CandidateList();
  void Add(Candidate c);
  Candidate Remove(std::string name);
  Candidate ReturnLoser();
  int ListSize();

  std::vector<Candidate> get_candidate_list(){return candidate_list;}
  void set_candidate_list(std::vector<Candidate> cl) {candidate_list = cl;}
private:
  std::vector<Candidate> candidate_list;
};
