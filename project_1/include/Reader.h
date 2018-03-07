/*!******************************************************************************
 * Name            : Reader.h
 * Project         : Voting System
 * Description     : Header file for BallotList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

class Reader {
	public:
		//Constructors
		Reader(string &csv, ifstream &file);

		//Getters/Setters

		//Methods
		void read(string &in, ifstream &myFile);

	private:
		string in;
		ifstream myFile; 
};

