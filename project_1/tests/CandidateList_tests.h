#include <cxxtest/TestSuite.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "../include/CandidateList.h"


using namespace std;

class CandidateListTestSuite : public CxxTest::TestSuite {

  public:
    
    void test_generic_constructor() {
      CandidateList c;
      vector<Candidate> empty;
      TS_ASSERT(empty.size() == c.get_candidate_list().size());
    }

  	void test_remove_candidate() {
      CandidateList cL;
      Candidate c("A");
      cL.Add(c);
      Candidate removed;
	    removed = cL.Remove("A");
      TS_ASSERT(c.get_name() == removed.get_name());
      TS_ASSERT(cL.get_candidate_list().size() == 0);
    }

    void test_there_exists() {
      CandidateList cL;
      Candidate c("A");
      cL.Add(c);
      TS_ASSERT(cL.ThereExists("A") == true);
    }

  	void test_add_candidate() {
      CandidateList cL;
      Candidate c("A");
      cL.Add(c);
      TS_ASSERT(c.get_name() == cL.get_candidate_list()[0].get_name());
    }

  	void test_return_loser() {
      CandidateList c;
      Candidate a("A");
      Candidate b("B");
  	  Ballot ballot;
  	  Ballot ballot2;
  	  a.get_votes().get_ballot_list().push_back(ballot);
  	  b.get_votes().get_ballot_list().push_back(ballot);
  	  b.get_votes().get_ballot_list().push_back(ballot2);
      c.Add(a);
      c.Add(b);
      TS_ASSERT(a.get_name() == c.ReturnLoser().get_name());
    }

    void test_return_candidate(){
      CandidateList cL;
      Candidate c("A");
      cL.Add(c);
      TS_ASSERT(cL.ReturnCandidate("A").get_name() == c.get_name());
    }

    void test_return_winner() {
      CandidateList c;
      Candidate a("A");
      Candidate b("B");
  	  Ballot ballot;
  	  b.get_votes().get_ballot_list().push_back(ballot);
      c.Add(a);
      c.Add(b);
      TS_ASSERT(b.get_name() == c.ReturnWinner().get_name());
    }

    void test_return_winners() {
      CandidateList c;
      Candidate a("A");
      Candidate b("B");
      c.Add(a);
      c.Add(b);
      vector<Candidate> winners;
      winners.push_back(b);
      winners.push_back(a);
    }

    void test_list_size() {
      CandidateList c;
      Candidate a("A");
      Candidate b("B");
      c.Add(a);
      c.Add(b);
      TS_ASSERT(c.ListSize() == 2);
    }
};
