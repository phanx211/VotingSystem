#include <cxxtest/TestSuite.h>
#include "../include/Candidate.h"
#include "../include/BallotList.h"

using namespace std;

class CandidateTestSuite : public CxxTest::TestSuite {

  public:

    void test_generic_constructor() {
      Candidate c;
      TS_ASSERT(c.get_name() == "");
      TS_ASSERT(c.get_num_ballots() == 0);
    }

    void test_custom_constructor() {
  	  Candidate c("[A]");
      TS_ASSERT(c.get_name() == "[A]");
  	  TS_ASSERT(c.get_num_ballots() == 0);
  	  TS_ASSERT(c.get_votes().ListSize() == 0);
    }
};
