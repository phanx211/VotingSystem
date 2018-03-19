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

Election::Election() {
	num_seats=0;
	num_candidates=0;
	num_ballots=0;
}

Election::Election(int total_seats, int total_candidates, int total_ballots){
	this->num_seats=total_seats;
	this->num_candidates=total_candidates;
	this->num_ballots=total_ballots;
}

void Election::MoveBallot(int bal_no, BallotList& src, BallotList& dst) {
	Ballot temp=src.RemoveBallot(bal_no);
	dst.AddBallot(temp);
	// std::cout << "SIZE OF DST IS NOW " <<dst.get_ballot_list().size()<< '\n';
}

void Election::ReadNames(string filename) {
	ifstream infile;
	infile.open(filename.c_str());
	string data;
	getline(infile,data,'\n');
	//std::cout << "HAHA" << '\n';
	//std::cout << data << '\n';
	istringstream ss(data);
	string token;

	while(std::getline(ss, token, ',')) {
		  Candidate temp(token, 0);
	    candidates.Add(temp);
	}

	std::cout << "Candidate size is " << candidates.ListSize() << '\n';

	infile.close();
}
