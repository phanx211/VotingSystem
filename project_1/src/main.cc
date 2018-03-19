#include "../include/BallotList.h"
#include "../include/Plurality.h"
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {
  srand(time(NULL)); // Used for randomizing

  /*
  argv[1] = no of candidates
  argv[2] = no of winners
  argv[3] = no of ballots
  argv[4] = Vote type
  argv[5] = filename
  */

  std::string vote_type_(argv[4]);
  std::string filename(argv[5]);
  if (vote_type_ == "Plurality"){

	// Creates a plurality object called testp taking in some arguments from the
	// command line
    Plurality testp(atoi(argv[2]),atoi(argv[1]),atoi(argv[3]));

    BallotList init_ballots_;
    testp.ReadNames(filename); // Initialize the candidate list based on names in the csv
    init_ballots_.ReadFile(filename,atoi(argv[3])); // Initializes the list of ballots
													// reading the lines of the csv
    for (int i = 0; i < init_ballots_.ListSize(); i++) {
      for (unsigned j = 0; j < init_ballots_.get_ballot_list()[i].get_votes().size(); j++ ) {
        cout << init_ballots_.get_ballot_list()[i].get_votes()[j] << " ";
      }
      cout << endl;
    }

	// Sets the ballot_list in the Election class to init_ballots_
    testp.set_ballots(init_ballots_);

	// Runs the plurality after all the paremeters have been set
    testp.Algorithm();
  }
  else if (vote_type_== "Droop") {
	cout << "Droop algorithm" << endl;
  }
  else {
    cout << "Unknown Vote Type" << '\n';
  }
  return 0;
}
