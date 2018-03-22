#include "../include/BallotList.h"
#include "../include/Plurality.h"
#include "../include/STV.h"
#include <time.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
  string no_cands;
  string no_seats;
  string no_bals;
  string vote_type_;
  string filename;
  cout << endl << "##########################################" << endl;
  cout << "Welcome to the best election system in the world. We are pleased to take your ballots and let you know who your winners are." << endl;
  cout << "##########################################" << endl << endl;
  cout << "Enter number of candidates: ";
  getline(cin,no_cands);
  cout <<"Enter number of seats: ";
  getline(cin,no_seats);
  cout << "Enter number of ballots: ";
  getline(cin,no_bals);
  cout << "Enter voting type (Plurality or STV, case sensitive): ";
  getline(cin,vote_type_);
  cout << "Enter the filename of the csv file: ";
  getline(cin,filename);
  cout << "The election process has been recorded in log.txt." << endl;

  freopen("log.txt","w",stdout);
  srand(time(NULL)); // Used for randomizing

  /*
  argv[1] = no of candidates
  argv[2] = no of winners
  argv[3] = no of ballots
  argv[4] = Vote type
  argv[5] = filename
  */

  if (vote_type_ == "Plurality"){

	// Creates a plurality object called testp taking in some arguments from the
	// command line
    Plurality testp(atoi(no_seats.c_str()),atoi(no_cands.c_str()),atoi(no_bals.c_str()));
    BallotList init_ballots_;
    testp.ReadNames(filename); // Initialize the candidate list based on names in the csv
    init_ballots_.ReadFile(filename,atoi(no_bals.c_str())); // Initializes the list of ballots
  												// reading the lines of the csv

// The following commented section can be uncommented to see the integer
// representation of the votes.
    // for (int i = 0; i < init_ballots_.ListSize(); i++) {
    //   for (unsigned j = 0; j < init_ballots_.get_ballot_list()[i].get_votes().size(); j++ ) {
    //     cout << init_ballots_.get_ballot_list()[i].get_votes()[j] << " ";
    //   }
    //   cout << endl;
    // }

  // Sets the ballot_list in the Election class to init_ballots_
    testp.set_ballots(init_ballots_);

  // Runs the plurality after all the paremeters have been set
    testp.Algorithm();
  }
  else if (vote_type_== "Droop" || vote_type_== "STV") {
  	STV testp(atoi(no_seats.c_str()),atoi(no_cands.c_str()),atoi(no_bals.c_str()));
    BallotList init_ballots_;
    testp.ReadNames(filename); // Initialize the candidate list based on names in the csv
    init_ballots_.ReadFile(filename,atoi(no_bals.c_str())); // Initializes the list of ballots
  												// reading the lines of the csv
    // for (int i = 0; i < init_ballots_.ListSize(); i++) {
    //   for (unsigned j = 0; j < init_ballots_.get_ballot_list()[i].get_votes().size(); j++ ) {
    //     cout << init_ballots_.get_ballot_list()[i].get_votes()[j] << " ";
    //   }
    //   cout << endl;
    // }
  // Sets the ballot_list in the Election class to init_ballots_
    testp.set_ballots(init_ballots_);

  // Runs the plurality after all the paremeters have been set
    testp.Algorithm();
  }
  else {
    cout << "Unknown Vote Type" << '\n';
  }








  return 0;
}
