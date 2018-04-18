/*!******************************************************************************
 * Name            : Ballot.cc
 * Project         : Voting System
 * Description     : Implementation file for Ballot
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <string>
#include "../include/Ballot.h"


// Default constructor, sets number of ballots to 0.
Ballot::Ballot() {
	this->ballot_no = 0;
}

// Constructor to create a ballot object with ballot number and a vector
// representing the votes
Ballot::Ballot(int num, std::vector<int> vote) {
	this->ballot_no = num;
	this->votes = vote;
	this->current = 1;

}

int Ballot::CountVotes() {
	int count=0;
	for (int i=0; i<votes.size(); i++) {
		if (votes[i] != 0) {
			count++;
		}
	}
	return count;
}
