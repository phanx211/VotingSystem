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


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief An object containing the voting ballots
*    - The Ballot class will be the main structure to instantiate each voting ballot.
*    - The Ballot class stores the ballot number, the voting type pertaining to the ballot, and the votes for that ballot candidates
*/
class Ballot {
	
	public:
		//Constructor
		Ballot();

		/**
		* @brief Creates a ballot that contains the ballot number and the voters corresponding votes.
		*
		* @param num Takes in the ballot number.
		*
		* @param vote Stores a single instance of the ballot number votes.
		*/
		Ballot(int num, std::vector<int> vote);

		//Getters/Setters

		/**
		* @brief Gets the ballot number from the class
		*/
		int get_ballot_no() {return ballot_no;}

		int get_current() {return current;}

		void set_current(int c) {current = c;}

		/**
		* @brief Sets the ballot number (b_no) to the local variable (ballot_no) to store the ballot number
		*
		* @param b_no Store the ballot number.
		*/
		void set_ballot_no(int b_no) {ballot_no = b_no;}

		std::vector<int> get_votes() {return votes;}

		/**
		* @brief Sets the "vote" vector that contains all the ballot votes to the class variable "votes" vector
		*
		* @param vote Contains all the voters votes for that ballot
		*/
		void set_votes(std::vector<int> vote) {votes = vote;}

	private:
		int ballot_no;
		std::vector<int> votes;
		int current;
};

#endif  // PROJECT_INCLUDE_BALLOT_H_
