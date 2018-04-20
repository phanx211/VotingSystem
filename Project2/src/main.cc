/*!******************************************************************************
 * Name            : main.cc
 * Project         : Voting System
 * Description     : Main driver file.
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include "../include/BallotList.h"
#include "../include/Plurality.h"
#include "../include/STV.h"
#include <time.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
  //string no_cands;
  //string no_seats;
  //string no_bals;
  //string vote_type_;
  string filename;

  cout << endl << "##########################################" << endl;
  cout << "Welcome to the best election system in the world. We are pleased to "
          "take your ballots and let you know who your winners are."
       << endl;
  cout << "##########################################" << endl << endl;

  if (argc < 2) {
    cout << "Enter filename of the csv file: ";
    getline(cin, filename);
  }
  else {
    filename = argv[1];
    cout << "Filename entered: " << filename << endl;
  }

  srand(time(NULL));  // Used for randomizing

  Election election_type;
  election_type.ReadParameters(filename);

  if (election_type.get_election_type() == "Plurality") {
  //if (vote_type_ == "Plurality") {
	// Creates a plurality object called testp taking in some arguments from the
	// command line
	Plurality testp;
	testp.ReadParameters(filename);
	//Plurality testp(atoi(no_seats.c_str()), atoi(no_cands.c_str()),
	//	atoi(no_bals.c_str()));
	BallotList init_ballots_;
	testp.ReadNames(
		filename);  // Initialize the candidate list based on names in the csv
	init_ballots_.ReadFile(
		filename, testp.get_num_ballots());  // Initializes the list of ballots (added getter for Project 2)
											// reading the lines of the csv

	// Sets the ballot_list in the Election class to init_ballots_
	testp.set_ballots(init_ballots_);

	// Runs the plurality after all the paremeters have been set
	testp.Algorithm();
  } else if (election_type.get_election_type() == "Droop" || election_type.get_election_type() == "STV") {
  //} else if (vote_type_ == "Droop" || vote_type_ == "STV") {
	STV testp;
	testp.ReadParameters(filename);
    //STV testp(atoi(no_seats.c_str()), atoi(no_cands.c_str()),
    //          atoi(no_bals.c_str()));
    BallotList init_ballots_;
    testp.ReadNames(
        filename);  // Initialize the candidate list based on names in the csv
    init_ballots_.ReadFile(
        filename, testp.get_num_ballots());  // Initializes the list of ballots (added getter for Project 2)
                                           // reading the lines of the csv

    // Sets the ballot_list in the Election class to init_ballots_
    testp.set_ballots(init_ballots_);

    // Runs the plurality after all the paremeters have been set
    testp.Algorithm();
  } else {
    cout << "Unknown Vote Type" << '\n';
  }

  return 0;
}
