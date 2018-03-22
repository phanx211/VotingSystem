#include <cxxtest/TestSuite.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../include/Plurality.h"

using namespace std;

class PluralityTestSuite : public CxxTest::TestSuite {

  public:

    void test_return_highest_vote_index() {
      vector<int> v;
      Plurality p;
      v.push_back(3);
      v.push_back(1);
      v.push_back(4);
      v.push_back(2);
      Ballot b(1,v);
      TS_ASSERT(p.ReturnHighestVoteIndex(b) == 1);
    }
    
};
