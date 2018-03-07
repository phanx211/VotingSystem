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
		Ballot(int ballot_no, std::string vote_type, int<> votes);

		//Getters/Setters
		int get_ballot_no() {return ballot_no;}
		void set_ballot_no(int ballot_no) {ballot_no = ballot_no;}

		std::string get_vote_type() {return vote_type;}
		void set_vote_type(std::string vote_type) {vote_type = vote_type;}

		int<> get_votes() {return votes;}
		void set_votes(int<> votes) {votes = votes;}
		
	private:
		int ballot_no;
		std::string vote_type;
		int<> votes;
};
