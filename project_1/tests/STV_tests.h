#include <cxxtest/TestSuite.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../include/STV.h"

using namespace std;

class STVTestSuite : public CxxTest::TestSuite {

  public:

    void test_get_index() {
      STV a;
      vector<int> v;
      v.push_back(1);
      v.push_back(2);
      v.push_back(3);
      TS_ASSERT(a.get_index(v,2) == 1);
    }

    void test_return_name_of_vote() {
      STV s(1,4,3);
      BallotList init_ballots_;
      testp.ReadNames("tests/test.csv"); // Initialize the candidate list based on names in the csv
      init_ballots_.ReadFile("tests/test.csv",3);
      TS_ASSERT(s.ReturnNameOfVote(s.get_ballots()[0]) == "[A]");
      TS_ASSERT(s.ReturnNameOfVote(s.get_ballots()[1]) == "[B]");
      TS_ASSERT(s.ReturnNameOfVote(s.get_ballots()[2]) == "[A]");
    }

    void test_move_candidate() {
      STV s;
      CandidateList cL1;
      CandidateList cL2;
      Candidate a("A");
      Candidate b("B");
      cL1.Add(a);
      cL1.Add(b);
      s.MoveCandidate("A",cL1,cL2);
      TS_ASSERT(cL1.get_candidate_list().ListSize() == 1);
      TS_ASSERT(cL1.get_candidate_list()[0].get_name() == "B");
      TS_ASSERT(cL2.get_candidate_list().ListSize() == 1);
      TS_ASSERT(cL2.get_candidate_list()[0].get_name() == "A");
    }

    void test_calculate_droop() {
      STV s(1,4,3);
      TS_ASSERT(s.CalculateDroop() == 1);
    }
};
