/*!******************************************************************************
 * Name            : Ballot.cc
 * Project         : Voting System
 * Description     : Implementation file for Ballot
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <string>
#include "../include/Ballot.h"



Ballot::Ballot() {
	this->ballot_no = 0;
}

Ballot::Ballot(int num, std::vector<int> vote) {
	this->ballot_no = num;
	this->votes = vote;

}
