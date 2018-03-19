#include "../include/BallotList.h"
#include "../include/Plurality.h"

using namespace std;

int main(int argc, char *argv[]) {

  /*
  argv[1] = no of candidates
  argv[2] = no of winners
  argv[3] = no of ballots
  argv[4] = Vote type
  argv[5] = filename
  */

  std::string vote_type_(argv[4]);
  if (vote_type_ == "Plurality"){



    Plurality testp(atoi(argv[2]),atoi(argv[1]),atoi(argv[3]));


    BallotList init_ballots_;
    testp.ReadFile("ex.csv");
    init_ballots_.ReadFile("ex.csv",atoi(argv[3]));
    for (int i = 0; i < init_ballots_.ListSize(); i++) {
      for (unsigned j = 0; j < init_ballots_.get_ballot_list()[i].get_votes().size(); j++ ) {
        cout << init_ballots_.get_ballot_list()[i].get_votes()[j] << " ";
      }
      cout << endl;
    }
    // cout << init_ballots_.ListSize() << endl;

    testp.set_ballots(init_ballots_);

    testp.Algorithm();
  }

  else {
    std::cout << "Unknown Vote Type" << '\n';
  }
  return 0;
}
