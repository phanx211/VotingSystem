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
  string no_cands;
  string no_seats;
  string no_bals;
  string vote_type_;
  string filename;
  cout << endl << "##########################################" << endl;
  cout << "Welcome to the best election system in the world. We are pleased to "
          "take your ballots and let you know who your winners are."
       << endl;
  cout << "##########################################" << endl << endl;
  cout << "Enter number of candidates: ";
  getline(cin, no_cands);
  cout << "Enter number of seats: ";
  getline(cin, no_seats);
  cout << "Enter number of ballots: ";
  getline(cin, no_bals);
  cout << "Enter voting type (Plurality or STV, case sensitive): ";
  getline(cin, vote_type_);
  cout << "Enter the filename of the csv file: ";
  getline(cin, filename);
  cout << "The election process has been recorded in log.txt." << endl;

  freopen("log.txt", "w", stdout);
  fclose(stdout); 
  
  //Audit File in addition to Log 
  freopen("audit.txt", "w", stdout); 
  
  
  srand(time(NULL));  // Used for randomizing


  if (vote_type_ == "Plurality") {
    // Creates a plurality object called testp taking in some arguments from the
    // command line
    Plurality testp(atoi(no_seats.c_str()), atoi(no_cands.c_str()),
                    atoi(no_bals.c_str()));
    BallotList init_ballots_;
    testp.ReadNames(
        filename);  // Initialize the candidate list based on names in the csv
    init_ballots_.ReadFile(
        filename, atoi(no_bals.c_str()));  // Initializes the list of ballots
                                           // reading the lines of the csv

    // Sets the ballot_list in the Election class to init_ballots_
    testp.set_ballots(init_ballots_);

    // Runs the plurality after all the paremeters have been set
    testp.Algorithm();
  } else if (vote_type_ == "Droop" || vote_type_ == "STV") {
    STV testp(atoi(no_seats.c_str()), atoi(no_cands.c_str()),
              atoi(no_bals.c_str()));
    BallotList init_ballots_;
    testp.ReadNames(
        filename);  // Initialize the candidate list based on names in the csv
    init_ballots_.ReadFile(
        filename, atoi(no_bals.c_str()));  // Initializes the list of ballots
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
