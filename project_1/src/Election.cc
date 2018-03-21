/*!******************************************************************************
 * Name            : BallotList.cc
 * Project         : Voting System
 * Description     : Implementation file for BallotList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "../include/Election.h"

using namespace std;

// Default constructor
Election::Election() {
	num_seats=0;
	num_candidates=0;
	num_ballots=0;
}

// Constructor to set the number of seats, candidates, and ballots
Election::Election(int total_seats, int total_candidates, int total_ballots){
	this->num_seats=total_seats;
	this->num_candidates=total_candidates;
	this->num_ballots=total_ballots;
}

// Moves a ballot from a source ballot list to a destination ballot list
void Election::MoveBallot(int bal_no, BallotList& src, BallotList& dst) {
	Ballot temp=src.RemoveBallot(bal_no);
	dst.AddBallot(temp);
	// std::cout << "SIZE OF DST IS NOW " <<dst.get_ballot_list().size()<< '\n';
}

// Reads through the first line of the csv (the name of the candidates) and adds
// each candidate to the list by their name.
void Election::ReadNames(string filename) {
	ifstream infile;
	infile.open(filename.c_str());
	string data;
	getline(infile,data,'\n');
	istringstream ss(data);
	string token;
	int count=1;

	while(std::getline(ss, token, ',')) {
			Candidate temp;
			if (count==num_candidates){
				std::cout << "R is at "<<  token.find('\r') << '\n';
				names.push_back(token.substr(0,token.find('\r')));
				temp.set_name(token.substr(0,token.find('\r')));
			}
			else {
				names.push_back(token);
				temp.set_name(token);
			}
	    candidates.Add(temp);
			count++;
	}

	std::cout << "Candidate size is " << candidates.ListSize() << '\n';

	infile.close();
}
