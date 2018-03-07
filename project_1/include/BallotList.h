/*!******************************************************************************
 * Name            : BallotList.h
 * Project         : Voting System
 * Description     : Header file for BallotList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#ifndef PROJECT_INCLUDE_BALLOTLIST_H_
#define PROJECT_INCLUDE_BALLOTLIST_H_

/*!******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Ballot.h"

/*!******************************************************************************
 * Class Definition
 ******************************************************************************/

class BallotList {
	public:
		//Constructors
		BallotList();
		BallotList(std::vector<Ballot> ballots);

		//Getters/Setters
		std::vector<Ballot> get_ballot_list() {return ballot_list;}
		void set_ballot_list(std::vector<Ballot> ballots) {ballot_list = ballots;}

		//Methods
		void ShuffleBallots();
		Ballot RemoveBallot(int voter_no);
		void AddBallot(Ballot ballot);
		int ListSize();
    int myrandom (int i);

	private:
		std::vector<Ballot> ballot_list;
};


#endif  // PROJECT_INCLUDE_BALLOTLIST_H_
