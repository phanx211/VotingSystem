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
	ballot_list.push_back(ballot);
}

int BallotList::ListSize() {
	return ballot_list.size();
}

void MakeBallot(string data) {
	vector<int> votes;

	// If the first element is a comma, immediately append a 0 to the vector
	char c = line[0];
	if ((line[0] == ',') || (line[0] == ' ')) {
		votes.push_back(0);
	}
	else { // Otherwise, convert the element to an integer and append to vector
		int a = c-'0';
		votes.push_back(a);
	}
	char previous = line[0]; // previous is used to store the previous
																	// character in the string

	// Start iterating through the line, starting at the 2nd character
	for (int i = 1; i < line.length()-1; i++) {
		char s = line[i];
		// If the current character is a space, add a 0
		if (line[i] == ' ') {
			votes.push_back(0);
			previous = s;
		}
		// If the current character is a comma as well as the previous, add a 0
		else if ((line[i] == ',') && (previous == ',')) {
			votes.push_back(0);
		}

		// If the current character is not a comma, convert character to int and add
		// to vector
		else if ((line[i] != ',') && (line[i] != ' ')) {
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
	if ((line[line.length()-1] == ',') || (line[line.length()-1] == ' ')) {
		votes.push_back(0);
	}

	Ballot new_ballot = new Ballot(0,votes);
	this->AddBallot(new_ballot);
}

void ReadFile(string filename) {
	ifstream infile;
	infile.open(filename);
	string line;
	getline(infile,line,'\n');
	for (int i=0; i<this->num_ballots; i++) {
		getline(infile,line,'\n');
		MakeBallot(line);
	}
}
/*
int main(void){
  BallotList x;
  Ballot t;
  t.set_ballot_no(5);
  Ballot f;
  f.set_ballot_no(4);
  Ballot c;
  c.set_ballot_no(3);
  Ballot a;
  a.set_ballot_no(2);
  Ballot b;
  b.set_ballot_no(1);
  x.AddBallot(b);
  x.AddBallot(a);
  x.AddBallot(c);
  x.AddBallot(f);
  x.AddBallot(t);
  x.ShuffleBallots();
  x.ShuffleBallots();
  cout << x.get_ballot_list()[0].get_ballot_no() << endl;
  cout << x.get_ballot_list()[1].get_ballot_no() << endl;
  cout << x.get_ballot_list()[2].get_ballot_no() << endl;
  cout << x.get_ballot_list()[3].get_ballot_no() << endl;
  cout << x.get_ballot_list()[4].get_ballot_no() << endl;

  //cout << x.ListSize() << endl;


  return 0;
}
*/
