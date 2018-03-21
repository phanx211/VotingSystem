/*!******************************************************************************
 * Name            : Ballot.h
 * Project         : Voting System
 * Description     : Header file for Ballot
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#ifndef PROJECT_INCLUDE_STV_H_
#define PROJECT_INCLUDE_STV_H_

/*!******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Election.h"


/*!******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The Plurality class inherits from the Election class.
  * The class implements the Plurality algorithm to identify the winning candidates.
  */
class STV: public Election {

public:
  /**
   * @brief Default constructor for STV.
   */
  STV();
  /**
  * @brief Constructor for STV
  * @param num_seats Number of available seats in election
  * @param num_candidates Number of total candidates in election
  * @param num_ballots Number of total ballots in election
  */
  STV(int num_seats, int num_candidates, int num_ballots);

  // std::vector<int> get_vote_count() {return vote_count};

  /**
  * @brief Returns the index of the highest vote in a ballot
  * @param b Ballot to read through.
  */
  string ReturnNameOfVote(Ballot b);
  string ReturnNameOfHighest(Ballot b);

  /**
  * @brief Main driver of the STV voting
  */
  void Algorithm();
  /**
  * @brief Calculates the Droop number for STV.
  */
  void CalculateDroop();

  void MoveCandidate(string can_name, CandidateList& src, CandidateList& dst);

  int get_droop() {return droop;}

  void set_droop(int d) {droop = d;}

  int get_index(vector<int> v, int n);

private:

  int droop;
  // Votes, Elected and Non Elected are inherited from Election class

};

#endif  // PROJECT_INCLUDE_STV_H_
