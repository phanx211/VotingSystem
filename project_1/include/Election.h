/*!******************************************************************************
 * Name            : Ballot.h
 * Project         : Voting System
 * Description     : Header file for Ballot
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#ifndef PROJECT_INCLUDE_ELECTION_H_
#define PROJECT_INCLUDE_ELECTION_H_

/*!******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include "BallotList.h"
#include "CandidateList.h"
#include "Ballot.h"

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief An object that receives information about the number of seats, candidates, and ballots. Likewise, the class will store objects of CandidateList and BallotList
*/

class Election {
	public:
		//Constructors
		Election();

		/**
		* @brief Creates an Election instance that gets the number of seats available, number of cadidates running and number of ballots.
		*
		* @param num_seats Gets the inputted value of number of seats available for the election.
		*
		* @param num_cadidates Gets the value of number of candidates running.
		*
		*@param num_ballots Gets the number of ballots there are in voting.
		*/
		Election(int num_seats, int num_candidates, int num_ballots);

		//Getters/Setters

		/**
		* @brief Gets the number of seats available
		*/
		int get_num_seats() {return num_seats;}

		/**
		* @brief Sets the number of seats available (s) to the local variable (num_seats) to store the value of the number of seats available
		*
		* @param s Store the number of seats available.
		*/
		void set_ballot_no(int s) {num_seats = s;}

		/**
		* @brief Gets the number of candidates running
		*/
		int get_num_candidates() {return num_candidates;}

		/**
		* @brief Sets the number of candidates (c) to the local variable (num_candidates) to store the value of the number of candidates
		*
		* @param c Store the number of canidates
		*/
		void set_num_candidates(int c) {num_candidates = c;}

		/**
		* @brief Gets the number of ballots
		*/
		int get_num_ballots() {return num_ballots;}

		/**
		* @brief Sets the number of ballots (b) to the local variable (num_ballots) to store the value of the number of ballots for the election
		*
		* @param b Store the number of ballots
		*/
		void set_num_ballots(int b) {num_ballots = b;}

		/**
		* ASK RONNY
		*/
		CandidateList& get_candidates() {return candidates;}

		/**
		* @brief sets the candidatess to equal to the votes from the CandidateList Class
		*
		* @param cs Variable to get the votes from the CandidateList
		*/
		void set_votes(CandidateList cs) {candidates = cs;}

		/**
		* ASK RONNY
		*/
		BallotList& get_ballots() {return ballots;}

		/**
		* @brief sets the ballots to equal to the ballots obtained from the BallotList (bs)
		*
		* @param bs Variable to get the ballots from the BallotList
		*/
		void set_ballots(BallotList bs) {ballots = bs;}


		/**
		* @brief Pushes a string to a log file
		*/
		void Log();

		/**
		* @brief Shows Result of Election
		*/
		void DisplayResults();

		/**
		* @brief Moves ballot from one place to another
		*
		* @param bal_no Variable to store the ballot number
		*
		* @param src The BallotList object passed in
		*
		* @param dst The BallotList object that the src will be stored in
		*/
		void MoveBallot(int bal_no, BallotList& src, BallotList& dst);

		/**
		* @brief RONNY !!! Reads the names from the filename 
		*/
		void ReadNames(string filename);

	private:
		int num_seats;
		int num_candidates;
		int num_ballots;
		CandidateList candidates;
		CandidateList elected;
		CandidateList non_elected;
		BallotList ballots;
};

#endif  // PROJECT_INCLUDE_ELECTION_H_
