/*******************************************************************************
 *
 * Name            : CandidateList.h
 * Project         : Voting System
 * Description     : Header file for CandidateList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 * s
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

using namespace std;
/**
 * @brief An object containing a list of candidates
 *    - The CandidaeList class will be the main structure in which Ballots are stored.
 *    - The CandidateList stores an array of Candidate classes. It then has options to
 *    add, and remove the Ballots from this array
 *    - It also has a function that will return the Candidate who has the lowest Ballots.
 */
class CandidateList {
public:
  /**
  * @brief Constructor for CandidateList
  *
  */
  CandidateList();
  /**
  * @brief Adds candidate to the list.
  *
  * @param c The candidate to add.
  */
  void Add(Candidate c);
  /**
  * @brief Removes candidate form list.
  *
  * @param name The name of the candidate to remove.
  */
  Candidate Remove(std::string name);
  /**
  * @brief Returns the candidate with the lowest votes.
  */
  Candidate& ReturnLoser();
  /**
  * @brief Returns the candidate with the highest votes.
  */
  Candidate ReturnWinner();
  /**
  * @brief Returns a vector of candidates with highest vote.
  * @param num_seats The number of candidates to return
  */
  std::vector<Candidate> ReturnWinners(int num_seats);
  /**
  * @brief Returns the size of the list
  */
  int ListSize();
  /**
  * @brief Returns the vector of candidates.
  *
  */
  std::vector<Candidate>& get_candidate_list(){return candidate_list;}
  /**
  * @brief Sets candidate_list (a vector).
  *
  * @param cl Vector to set candidate_list to.
  */
  void set_candidate_list(std::vector<Candidate> cl) {candidate_list = cl;}

  Candidate& ReturnCandidate(string s);

  bool ThereExists(string s);

private:
  std::vector<Candidate> candidate_list;
};
