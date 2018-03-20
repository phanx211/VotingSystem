#include <cxxtest/TestSuite.h>
#include "../include/Candidate.h"

using namespace std;

class CandidateTestSuite : public CxxTest::TestSuite {

  public:

    test_generic_constructor() {
      Candidate c;
      TS_ASSERT(c);
      TS_ASSERT(c.get_name() == "");
      TS_ASSERT(c.get_num_ballots() == 0);
    }

    test_custom_constructor() {
	  Candidate c;
	  c.set_name("[A]");
	  c.set_num_votes(13);
      TS_ASSERT(c);
      TS_ASSERT(c);
      TS_ASSERT(c.get_name() == "[A]");
      TS_ASSERT(c.get_num_ballots() == 13);
    }
};
