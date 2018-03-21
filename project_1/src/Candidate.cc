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

// Default constructor
Candidate::Candidate() {
	name = "";
	num_ballots = 0;
	BallotList votes;
}

// Constructor that takes in the candidates name and number of ballots (number of votes)
Candidate::Candidate(std::string name) {
	this->name = name;
	BallotList votes;
}
