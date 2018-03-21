#include <cxxtest/TestSuite.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "../include/Candidate.h"
#include "../include/CandidateList.h"

using namespace std;

class CandidateListTestSuite : public CxxTest::TestSuite {

  public:
    void test_generic_constructor() {
      CandidateList c;
      std::vector<Candidate> empty;
      TS_ASSERT(empty == c.get_candidate_list());
    }

    void test_add_candidate() {
      CandidateList cL;
      Candidate c("A",10);
      cL.Add(c);
      TS_ASSERT(c == cL.get_candidate_list()[0]);
    }

    void test_remove_candidate() {
      CandidateList cL;
      Candidate c("A",10);
      cL.Add(c);
      Candidate removed = cL.Remove("A");
      TS_ASSERT(c == removed);
      TS_ASSERT(cL.get_candidate_list().size() == 0);
    }

    void test_return_loser() {
      CandidateList c;
      Candidate a("A",10);
      Candidate b("B",20);
      c.Add(a);
      c.Add(b);
      TS_ASSERT(a == c.ReturnLoser());
    }

    void test_return_winner() {
      CandidateList c;
      Candidate a("A",10);
      Candidate b("B",20);
      c.Add(a);
      c.Add(b);
      TS_ASSERT(b == c.ReturnWinner());
    }

    void test_return_winners() {
      CandidateList c;
      Candidate a("A",10);
      Candidate b("B",20);
      c.Add(a);
      c.Add(b);
      vector<Candidate> winners;
      winners.push_back(b);
      winners.push_back(a);
    }

};
