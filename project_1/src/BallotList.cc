/*!******************************************************************************
 * Name            : BallotList.cc
 * Project         : Voting System
 * Description     : Implementation file for BallotList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "include/BallotList.h"
#include "include/Ballot.h"

BallotList::BallotList() {
	std::vector<Ballot> temp{};
	this->ballot_list = temp;
}

BallotList::BallotList(Ballot<> ballots) {
	this->ballot_list = ballots;
}

BallotList::ShuffleBallots() {
	std::random_shuffle(ballot_list.begin(), ballot_list.end());
	int i=1;
	for (Ballot b:ballot_list) {
		b.set_ballot_no(i);
		i++;
	}
}

BallotList::RemoveBallot(int ballot_no) {
	int i=0;
	Ballot temp=NULL;
	for (Ballot b:ballot_list) {
		if (b.get_ballot_no() == ballot_no) {
			temp = ballot_list.at(i);
			ballot_list.erase(ballot_list.begin()+i);
			break;
		}
		i++;
	}
	return temp;
}


