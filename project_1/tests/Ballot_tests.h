#include <cxxtest/TestSuite.h>
#include "include/Ballot.h"

using namespace std;

class BallotTestSuite : public CxxTest::TestSuite {

  public:

    Ballot *b;

    void test_generic_constructor() {
      b = new Ballot();
      TS_ASSERT(b);
      TS_ASSERT(b.ballot_no == 0);
    }

    void test_custom_constructor() {
      vector<int> v;
      v.push_back(1);
      v.push_back(2);
      b = new Ballot(1,v);

      TS_ASSERT(b.get_ballot_no() == 1);
      TS_ASSERT(b.get_votes()[0] == 1 && b.get_votes()[1] == 2);
    }
};
