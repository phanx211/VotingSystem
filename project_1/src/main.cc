#include "../include/BallotList.h"
#include "../include/CandidateList.h"

using namespace std;

int main(int argc, char *argv[]) {

  BallotList tests;
  tests.ReadFile("ex.csv",11);
  for (int i = 0; i < tests.ListSize(); i++) {
    for (int j = 0; j < tests.get_ballot_list()[i].get_votes().size(); j++ ) {
      cout << tests.get_ballot_list()[i].get_votes()[j] << " ";
    }
    cout << endl;
  }
  cout << tests.ListSize() << endl;
  return 0;
}
