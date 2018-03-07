#include <string>
#include "include/Ballot.h"

Ballot::Ballot() {
	ballot_no = NULL;
	vote_type = NULL;
	votes = NULL;
}

Ballot::Ballot(int ballot, std::string type, int<> vote) {
	this->ballot_no = ballot;
	this->vote_type = type;
	this->votes = vote;
}
