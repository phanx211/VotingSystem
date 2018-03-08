/*!******************************************************************************
 * Name            : Ballot.h
 * Project         : Voting System
 * Description     : Header file for Ballot
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#ifndef PROJECT_INCLUDE_BALLOT_H_
#define PROJECT_INCLUDE_BALLOT_H_

/*!******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>


/*!******************************************************************************
 * Class Definitions
 ******************************************************************************/

class Ballot {
	public:
		//Constructors
		Ballot();
		Ballot(int num, std::vector<int> vote);

		//Getters/Setters
		int get_ballot_no() {return ballot_no;}
		void set_ballot_no(int b_no) {ballot_no = b_no;}

		std::vector<int> get_votes() {return votes;}
		void set_votes(std::vector<int> vote) {votes = vote;}

	private:
		int ballot_no;
		std::vector<int> votes;
};

#endif  // PROJECT_INCLUDE_BALLOT_H_
