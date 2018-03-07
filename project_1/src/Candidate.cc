/*!******************************************************************************
 * Name            : Candidate.cc
 * Project         : Voting System
 * Description     : Header file for Candidate
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include "include/Candidate.h"
#include "include/BallotList.h"
#include "include/Ballot.h"

Candidate::Candidate() {
	name = NULL;
	num_ballots = 0;
	votes = NULL;
}

Candidate::Candidate(std::string name, int num_ballots, BallotList votes) {
	this->name = name;
	this->num_ballots = num_ballots;
	this->votes = votes;
}


