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

class Plurality: public Election {

public:
  Plurality();

  Plurality(int num_seats, int num_candidates, int num_ballots);

  // std::vector<int> get_vote_count() {return vote_count};

  // Main Algorithm that runs plurality voting
  void Algorithm();

  int ReturnHighestVoteIndex(Ballot b);

private:

  // Stores the current amount of votes
  // std::vector<int> vote_count;
};

#endif  // PROJECT_INCLUDE_PLURALITY_H_
