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
vector<int> split_votes(string line) {
	vector<int> votes;
	string comma = ",";

	stringstream ss;
	string actual_string;

	ss << line[0];
	ss >> actual_string;
	// We use the stringstream to store the character received from line as a
	// string put into actual_string so that we can compare comma and that single
	// character string

	// If the first element is a comma, immediately append a 0 to the vector
	if (!(comma.compare(actual_string))) {
		votes.push_back(0);
	}
	else { // Otherwise, convert the element to an integer and append to vector
		votes.push_back(atoi(actual_string.c_str()));
	}
	string previous = actual_string; // previous is used to store the previous
																	// character in the string

	// Start iterating through the line, starting at the 2nd character
	for (int i = 1; i < line.length()-1; i++) {
		stringstream loop;
		loop << line[i];
		loop >> actual_string;

		// If the current character and the previous character are commas, add a 0
		if (!(comma.compare(actual_string)) && (previous == ",")) {
			votes.push_back(0);
		}
		// If the current character is not a comma, convert character to int and add
		// to vector
		else if (comma.compare(actual_string)) {
			votes.push_back(atoi(actual_string.c_str()));
			previous = actual_string;
		}
		// If the current character is a comma and the previous wasn't, go on to next
		// element
		else {
			previous = actual_string;
		}
	}

	stringstream loop;
	loop << line[line.length()-1];
	loop >> actual_string;
	// If the last character of the string is a comma, add a 0
	if (!(comma.compare(actual_string))) {
		votes.push_back(0);
	}
	return votes;
}

int main()
{
	// cout << "Hello World!" << endl;
	// return 0;
	ifstream infile;
	infile.open("ex.csv");
	string line;
	getline(infile,line,'\n');
	for (int i=0; i<11; i++) {
		getline(infile,line,'\n');
		cout << line << endl;
		cout << line.length() << endl;
		vector<int> votes = split_votes(line);
		for (int i = 0; i<votes.size(); i++) {
			cout << votes[i];
		}
		cout << "\n";
	}
	// string line = ",2,3,,,,,1,";
	// vector<int> votes = split_votes(line);
	// for (int i = 0; i<votes.size(); i++) {
	// 	cout << votes[i];
	// }
	// cout << "\n";

	return 0;
}
