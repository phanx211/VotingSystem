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

/*!******************************************************************************
 * Class Definitions
 ******************************************************************************/

class Election {
	public:
		//Constructors
		Election();
		Election(int num_seats, int num_candidates, int num_ballots);

		//Getters/Setters
		int get_num_seats() {return num_seats;}
		void set_ballot_no(int s) {num_seats = s;}

		int get_num_candidates() {return num_candidates;}
		void set_num_candidates(int c) {num_candidates = c;}

		int get_num_ballots() {return num_ballots;}
		void set_num_ballots(int b) {num_ballots = b;}

		CandidateList get_candidates() {return candidates;}
		void set_votes(CandidateList cs) {candidates = cs;}

		BallotList get_ballots() {return ballots;}
		void set_ballots(BallotList bs) {ballots = bs;}

		//Pushes a string to a log file
		void Log();

		// Shows Result of Election
		void DisplayResults();

		// Moves ballot from one place to another
		void MoveBallot(int bal_no, BallotList& src, BallotList& dst);

		void ReadFile(string filename);

	public:
		int num_seats;
		int num_candidates;
		int num_ballots;
		CandidateList candidates;
		CandidateList elected;
		CandidateList non_elected;
		BallotList ballots;
};

#endif  // PROJECT_INCLUDE_ELECTION_H_
