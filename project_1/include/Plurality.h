/*!******************************************************************************
 * Name            : Ballot.h
 * Project         : Voting System
 * Description     : Header file for Ballot
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#ifndef PROJECT_INCLUDE_PLURALITY_H_
#define PROJECT_INCLUDE_PLURALITY_H_

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
class Plurality: public Election {

public:
  /**
   * @brief Default constructor for Plurality.
   */
  Plurality();
  /**
  * @brief Constructor for Plurality
  * @param num_seats Number of available seats in election
  * @param num_candidates Number of total candidates in election
  * @param num_ballots Number of total ballots in election
  */
  Plurality(int num_seats, int num_candidates, int num_ballots);

  // std::vector<int> get_vote_count() {return vote_count};

  /**
  * @brief Main driver of the Plurality voting
  */
  void Algorithm();
  /**
  * @brief Returns the index of the highest vote in a ballot
  * @param b Ballot to read through.
  */
  int ReturnHighestVoteIndex(Ballot b);

private:

  // Stores the current amount of votes
  // std::vector<int> vote_count;
};

#endif  // PROJECT_INCLUDE_PLURALITY_H_
