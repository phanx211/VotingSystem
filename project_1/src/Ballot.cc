#include <string>
#include "include/Ballot.h"

Ballot::Ballot() {
	ballot_no = NULL;
	vote_type = NULL;
	votes = NULL;
}

Ballot::Ballot(int ballot, std::string type, int<> votes) {
	ballot_no = ballot;
	vote_type = type;
	votes = votes;
}
