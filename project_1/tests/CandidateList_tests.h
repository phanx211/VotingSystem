#include <cxxtest/TestSuite.h>
#include "include/Candidate.h"
#include "include/CandidateList.h"

class CandidateListTestSuite : public CxxTest::TestSuite {

  public:
    test_generic_constructor() {
      c = new CandidateList();
      std::vector<Candidate> empty;

      TS_ASSERT(c);
      TS_ASSERT(empty == c.get_candidate_list());
    }

    test_add_candidate() {
      cL = new CandidateList();
      c = new Candidate("A",10);
      cL.Add(c);
      TS_ASSERT(cL);
      TS_ASSERT(c);
      TS_ASSERT(c == cL.get_candidate_list()[0]);
    }

    test_remove_candidate() {
      cL = new CandidateList();
      c = new Candidate("A",10);
      cL.Add(c);
      Candidate removed = cL.Remove("A");
      TS_ASSERT(cL);
      TS_ASSERT(c);
      TS_ASSERT(c == removed);
      TS_ASSERT(cL.get_candidate_list().size() == 0);
    }

    test_return_loser() {
      c = new CandidateList();
      a = new Candidate("A",10);
      b = new Candidate("B",20);
      c.Add(a);
      c.Add(b);
      TS_ASSERT(a == c.ReturnLoser());
    }

    test_return_winner() {
      c = new CandidateList();
      a = new Candidate("A",10);
      b = new Candidate("B",20);
      c.Add(a);
      c.Add(b);
      TS_ASSERT(c);
      TS_ASSERT(a);
      TS_ASSERT(b);
      TS_ASSERT(b == c.ReturnWinner());
    }

    test_return_winners() {
      c = new CandidateList();
      a = new Candidate("A",10);
      b = new Candidate("B",20);
      c.Add(a);
      c.Add(b);
      vector<Candidate> winners;
      winners.push_back(b);
      winners.push_back(a);
    }

}
