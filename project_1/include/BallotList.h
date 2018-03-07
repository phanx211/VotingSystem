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
#include "include/Ballot.h"

/*!******************************************************************************
 * Class Definition
 ******************************************************************************/

class BallotList {
	public:
		//Constructors
		BallotList();
		BallotList(Ballot<> ballots);

		//Getters/Setters
		Ballot<> get_ballot_list() {return ballot_list;}
		void set_ballot_list(Ballot<> ballots) {ballot_list = ballots;}

		//Methods
		void ShuffleBallots();
		Ballot RemoveBallot(int voter_no);
		void AddBallot(int ballot_no);
		int Size();

	private:
		Ballot<> ballot_list;
};
