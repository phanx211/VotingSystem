/*!******************************************************************************
 * Name            : BallotList.cc
 * Project         : Voting System
 * Description     : Implementation file for BallotList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "../include/BallotList.h"
#include "../include/Ballot.h"

using namespace std;

// Default Constructor
BallotList::BallotList() {
	vector<Ballot> ballot_list;
	this->ballot_list = ballot_list;
	num_ballots = 0;
}

// Constructor that sets ballot_list and num_ballots
BallotList::BallotList(std::vector<Ballot> ballots, int num) {
	this->ballot_list = ballots;
	this->num_ballots = num;
}

// Shuffles the order of ballot_list
void BallotList::ShuffleBallots() {
  std::random_shuffle ( ballot_list.begin(), ballot_list.end() );
}


// Removes a ballot object from ballot_list and returns it
Ballot BallotList::RemoveBallot(int ballot_no) {
	int i=0;
	Ballot temp;
	for (int i=0;i<ballot_list.size();i++) {
		if (ballot_list.at(i).get_ballot_no() == ballot_no) {
			temp = ballot_list.at(i);
			ballot_list.erase(ballot_list.begin()+i);
			break;
		}
	}
	return temp;
}

// Adds a ballot to ballot_list
void BallotList::AddBallot(Ballot ballot) {
	ballot_list.push_back(ballot);
}

// Returns the number of ballots in ballot_list
int BallotList::ListSize() {
	return ballot_list.size();
}

// Takes a line of the csv file (a single ballot), creates a ballot object, and translates
// the line of commas/numbers to a vector representing the votes on the ballot
void BallotList::MakeBallot(string data) {
	vector<int> votes;

	// If the first element is a comma, immediately append a 0 to the vector
	char c = data[0];
	if ((data[0] == ',') || (data[0] == ' ')) {
		votes.push_back(0);
	}
	else { // Otherwise, convert the element to an integer and append to vector
		int a = c-'0';
		votes.push_back(a);
	}
	char previous = data[0]; // previous is used to store the previous
																	// character in the string

	// Start iterating through the data, starting at the 2nd character
	for (unsigned i = 1; i <= data.length()-1; i++) {
		char s = data[i];
		// If the current character is a space, add a 0
		if (data[i] == ' ') {
			votes.push_back(0);
			previous = s;
		}
		// If the current character is a comma as well as the previous, add a 0
		else if ((data[i] == ',') && (previous == ',')) {
			votes.push_back(0);
		}

		// If the current character is not a comma, convert character to int and add
		// to vector
		else if ((data[i] != ',') && (data[i] != ' ')) {
			int b = s - '0';
			int c = b;
			if ((previous != ',') && (previous != ' ')) {
				votes.erase(votes.end()-1);
				int a = previous - '0';
				c = a*10 + b;
			}
			votes.push_back(c);
			previous = s;
		}
		else {
			previous = s;
		}
	}

	// If the last character of the string is a comma, add a 0
	if ((data[data.length()-1] == ',') || (data[data.length()-2] == ' ') || (data[data.length()-2] == ',')) {
		votes.push_back(0);
	}

	Ballot new_ballot(ListSize()+1,votes);
	this->AddBallot(new_ballot);
}

// Reads through the csv file containing the ballots and runs MakeBallot on 
// each line that is a ballot
void BallotList::ReadFile(string filename, int num_ballots) {
	ifstream infile;
	infile.open(filename.c_str());
	string data;
	getline(infile,data,'\n');
	for (int i=0; i<num_ballots; i++) {
		getline(infile,data,'\n');
		MakeBallot(data);
	}
	infile.close();
}
