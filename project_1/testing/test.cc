#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "test.h"

using namespace std;
// Returns the votes of a single ballot as a vector of integers. Takes in
// a string which is a line of the csv file
vector<int> make_ballot(string line) {
	vector<int> votes;
	// We use the stringstream to store the character received from line as a
	// string put into actual_string so that we can compare comma and that single
	// character string

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
	cout << line[line.length()-2] << endl;
	if ((line[line.length()-2] == ',') || (line[line.length()-2] == ' ')) {
		votes.push_back(0);
	}
	return votes;
}

int main()
{

	ifstream infile;
	infile.open("ex.csv");
	string line;
	getline(infile,line,'\n');
	for (int i=0; i<11; i++) {
		getline(infile,line,'\n');
		cout << line << endl;
		vector<int> votes = make_ballot(line);
		for (int i = 0; i<votes.size(); i++) {
			cout << votes[i] << ' ';
		}
		cout << "\n";
	}
	// string line = "1, ,21,3,, ,,,1,";
	// // for (int i=0; i<line.length(); i++) {
	// // 	cout << line[i] << endl;
	// // }
	// if (line[0] == ' ') {
	// 	cout << "Success" << endl;
	// }
	// vector<int> votes = split_votes(line);
	// //votes.erase(votes.end()-1);
	// for (int i = 0; i<votes.size(); i++) {
	// 	cout << votes[i] << endl;
	// }
	return 0;
}
