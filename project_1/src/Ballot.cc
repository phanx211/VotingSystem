/*!******************************************************************************
 * Name            : Ballot.cc
 * Project         : Voting System
 * Description     : Implementation file for Ballot
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <string>
#include "include/Ballot.h"

Ballot::Ballot() {
	ballot_no = 0;
	vote_type = NULL;
	votes = NULL;
}

Ballot::Ballot(std::string type, int<> vote) {
	this->ballot_no = 0;
	this->vote_type = type;
	this->votes = vote;
}
