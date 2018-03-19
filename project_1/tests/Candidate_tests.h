#include <cxxtest/TestSuite.h>
#include "include/Candidate.h"

class CandidateTestSuite : public CxxTest::TestSuite {

  public:

    Candidate *c;

    test_generic_constructor() {
      c = new Candidate();
      TS_ASSERT(c);
      TS_ASSERT(c.get_name() == "");
      TS_ASSERT(c.get_num_ballots() == 0);
    }

    test_custom_constructor() {

    }
}
