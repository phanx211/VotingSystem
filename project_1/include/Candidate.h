/*!******************************************************************************
 * Name            : Candidate.h
 * Project         : Voting System
 * Description     : Header file for Candidate
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

/*******************************************************************************
* Includes
******************************************************************************/
#include <string>
#include <iostream>
#include "include/BallotList.h"
#include "include/Ballot.h"

class Candidate {
	public:
		//Constructors
		Candidate();
		Candidate(std::string name, int num_ballots, BallotList votes);

		// Getters/Setters
		std::string get_name() {return name;}
		int get_num_ballots() {return num_ballots;}
		BallotList get_votes() {return votes;}

		void set_name(std::string name) {name = name;}
		void set_num_ballots(int num) {num_ballots = num;}
		void set_votes(BallotList votes) {votes = votes;}
	private:
		std::string name;
		int num_ballots;
		BallotList votes; 		
}