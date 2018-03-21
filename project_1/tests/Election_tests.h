#include <cxxtest/TestSuite.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "../include/Election.h"

using namespace std;

class ElectionTestSuite : public CxxTest::TestSuite {

  public:

    void test_generic_constructor() {
      Election e;
      TS_ASSERT(e.get_num_seats() == 0);
      TS_ASSERT(e.get_num_candidates() == 0);
      TS_ASSERT(e.get_num_ballots() == 0);
    }

    void test_custom_constructor() {
      Election e(2,3,8);
      TS_ASSERT(e.get_num_seats() == 2);
      TS_ASSERT(e.get_num_candidates() == 3);
      TS_ASSERT(e.get_num_ballots() == 8);
    }

    void test_move_ballot() {
      vector<int> v;
      Election e;
      Ballot a(1,v);
      Ballot b(2,v);
      BallotList bL1, bL2;
      bL1.AddBallot(a);
      bL1.AddBallot(b);
      e.MoveBallot(1, bL1, bL2);
      TS_ASSERT(bL2.ListSize() == 1);
      TS_ASSERT(bL2.get_ballot_list().back().get_ballot_no() == 1);
    }

    void test_read_names() {
      Election e;
      e.ReadNames("tests/test.csv");
      TS_ASSERT(e.get_candidates().get_candidate_list()[0].get_name() == "[A]");
      TS_ASSERT(e.get_candidates().get_candidate_list()[1].get_name() == "[B]");
      TS_ASSERT(e.get_candidates().get_candidate_list()[2].get_name() == "[C]");
      TS_ASSERT(e.get_candidates().get_candidate_list()[3].get_name() == "[D]\r");
    }
};
