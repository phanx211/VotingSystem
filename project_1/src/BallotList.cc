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

BallotList::BallotList() {
	vector<Ballot> ballot_list;
	this->ballot_list = ballot_list;
	num_ballots = 0;
}


BallotList::BallotList(std::vector<Ballot> ballots, int num) {
	this->ballot_list = ballots;
	this->num_ballots = num;
}

void BallotList::ShuffleBallots() {
  std::random_shuffle ( ballot_list.begin(), ballot_list.end() );
	// for (Ballot b:ballot_list) {
	// 	b.set_ballot_no(i);
	// 	i++;
	// }
}

Ballot BallotList::RemoveBallot(int ballot_no) {
	int i=0;
	Ballot temp;
	for (Ballot b:ballot_list) {
		if (b.get_ballot_no() == ballot_no) {
			temp = ballot_list.at(i);
			ballot_list.erase(ballot_list.begin()+i);
			break;
		}
		i++;
	}
	return temp;
}

void BallotList::AddBallot(Ballot ballot) {
	// std::cout << "Adding " << ballot.get_ballot_no() << '\n';
	ballot_list.push_back(ballot);
	// std::cout << "Size is now" << ballot_list.size() << '\n';
}

int BallotList::ListSize() {
	return ballot_list.size();
}

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
	for (unsigned i = 1; i < data.length()-1; i++) {
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

void BallotList::ReadFile(string filename, int num_ballots) {
	ifstream infile;
	infile.open(filename.c_str());
	string data;
	getline(infile,data,'\n');
	// std::cout << data << '\n';
	for (int i=0; i<num_ballots; i++) {
		getline(infile,data,'\n');
		//cout << data << endl;
		MakeBallot(data);
	}
	infile.close();
}
