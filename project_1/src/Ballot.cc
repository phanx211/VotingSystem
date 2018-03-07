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
	vote_type = "";
}

Ballot::Ballot(int num, std::string type, std::vector<int> vote) {
	this->ballot_no = num;
	this->vote_type = type;
	this->votes = vote;

}
