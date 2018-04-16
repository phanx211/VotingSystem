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
#include "BallotList.h"
#include "Ballot.h"
/**
 * @brief An object representing a Candidate
 */
class Candidate {
	
	public:
		//Constructors
		Candidate();

		Candidate(std::string name);

		// Getters/Setters
		/**
		* @brief Returns the name of the candidate
		*/
		std::string get_name() {return name;}
		/**
		* @brief Returns the amount of votes the candidate has
		*/
		int get_num_ballots() {return votes.ListSize();}
		/**
		* @brief Returns the votes that the candidate has.
		*/
		BallotList& get_votes() {return votes;}

		void set_name(std::string name) {this->name = name;}

		void set_votes(BallotList votes) {this->votes = votes;}

	private:
		std::string name;
		BallotList votes;
};
