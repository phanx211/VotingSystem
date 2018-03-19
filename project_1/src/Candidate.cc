/*!******************************************************************************
 * Name            : Candidate.cc
 * Project         : Voting System
 * Description     : Header file for Candidate
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include "../include/Candidate.h"
#include "../include/BallotList.h"
#include "../include/Ballot.h"

Candidate::Candidate() {
	name = "";
	num_ballots = 0;
	BallotList votes;
}

Candidate::Candidate(std::string name, int num_ballots) {
	this->name = name;
	this->num_ballots = num_ballots;
	// this->votes = votes;
	BallotList votes;
}
