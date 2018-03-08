#include "../include/BallotList.h"
#include "../include/CandidateList.h"

using namespace std;

int main(int argc, char *argv[]) {

  BallotList tests;
  tests.ReadFile("ex.csv",10);
  // for (int i = 0; i < tests.ListSize(); i++) {
  //   cout << tests.get_ballot_list()[i].get_ballot_no() << endl;
  // }
  cout << tests.ListSize() << endl;
  return 0;
}
