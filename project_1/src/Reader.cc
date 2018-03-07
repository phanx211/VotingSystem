/*!******************************************************************************
 * Name            : Reader.cc
 * Project         : Voting System
 * Description     : Implementation file for Ballot
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "include/Reader.h"
using namespace std; 

Reader::Reader() {
	in = csv;
	myFile = file;  

}

//read in the CSV file from main 
void Reader::read(string &input, ifstream &inFile) 
{
	bool again;
	do 
	{
		again = true;
		inFile.open(input);
		
		if (inFile.fail()){
		cout << "ERROR: can't open input file: " << input << endl; 
		again = false;
		}
		
	}while (again == 0);
	
	return; 	
}

