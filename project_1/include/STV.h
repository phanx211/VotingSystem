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
  * @brief The STV class inherits from the Election class.
  * The class implements the STV algorithm to identify the winning candidates.
  */
class STV: public Election {

public:
  /**
   * @brief Default constructor for STV./**
  * @brief Calculates the Droop number for STV.
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
  * @brief Returns the name of candidate with the highest vote in a ballot
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

  /**
  * @brief Moves the candidate from one source location to the desitnation location
    * @param can_name The Candidate name
    * @param src The source of the CandidateList
    * @param dst The destination of the CandidateList when re-distributing votes
  */
  void MoveCandidate(string can_name, CandidateList& src, CandidateList& dst);

  /**
  * @brief Retrieves the droop value
  */
  int get_droop() {return droop;}

  /**
  * @brief Returns the droop value
  */
  void set_droop(int d) {droop = d;}

  /**
  * @brief Gets the index of the vector
  * @param v The vector list
  * @param n The value of the index trying to look for
  */
  int get_index(vector<int> v, int n);

private:

  int droop;
  // Votes, Elected and Non Elected are inherited from Election class

};

#endif  // PROJECT_INCLUDE_STV_H_
