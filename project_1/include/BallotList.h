/*******************************************************************************
 * Name            : BallotList.h
 * Project         : Voting System
 * Description     : Header file for BallotList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#ifndef PROJECT_INCLUDE_BALLOTLIST_H_
#define PROJECT_INCLUDE_BALLOTLIST_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Ballot.h"

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
 /**
  * @brief An object containing a list of Ballots.
	*
  *    The BallotList class purpose is to attain every voter’s ballot from the
	* Ballot class and store it in an array. It then has options to shuffle, add,
	* and remove the Ballots from the this array.
  */
class BallotList {
	public:
		//Constructors
		BallotList();
		/**
	  * @brief Constructor for BallotList
		* @param ballots The vector containing all the ballots
		* @param num_ballots the number of ballots
	  */
		BallotList(std::vector<Ballot> ballots, int num_ballots);

		/**
	  * @brief Returns the ballot vector
	  */
		std::vector<Ballot>& get_ballot_list() {return ballot_list;}
		/**
	  * @brief Returns the number of ballots.
	  */
		int get_num_ballots() {return num_ballots;}
		/**
	  * @brief Sets the ballot list (a vector)
		* @param ballots The ballot vector to set.
	  */
		void set_ballot_list(std::vector<Ballot> ballots) {ballot_list = ballots;}
		/**
	  * @brief Sets the number of ballots.
		* @param num The int to set num_ballots to.
	  */
		void set_num_ballots(int num) { num_ballots = num;}

		/**
	  * @brief Shuffles the order of ballots.
	  */
		void ShuffleBallots();
		/**
		* @brief Remove ballot from list.
		* @param voter_no The number of the ballot to remove.
		*/
		Ballot RemoveBallot(int voter_no);
		/**
		* @brief Add ballot to list.
		*
		* @param voter_no The ballot to add to list.
		*/
		void AddBallot(Ballot ballot);
		/**
		* @brief Returns the size of the current list
		*
		*/
		int ListSize();
		/**
		* @brief Takes a line of the csv file (a single ballot), creates a ballot object, and translates
		* the line of commas/numbers to a vector representing the votes on the ballot
		*
		* @param data A line from the csv file
		*/
		void MakeBallot(std::string data);
		/**
		* @brief Reads through the csv file containing the ballots and runs MakeBallot on
		* each line that is a ballot
		*
		* @param filename Name of file to read.
		* @param num_ballots the number of ballots to read.
		*/
		void ReadFile(std::string filename, int num_ballots);

	private:
		int num_ballots;
		std::vector<Ballot> ballot_list;
};


#endif  // PROJECT_INCLUDE_BALLOTLIST_H_
