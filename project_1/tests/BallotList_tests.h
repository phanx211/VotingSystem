#include <cxxtest/TestSuite.h>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include "../include/Ballot.h"
#include "../include/BallotList.h"

using namespace std;

class BallotListTestSuite : public CxxTest::TestSuite {

  public:

    void test_ShuffleBallots() {
		BallotList b;
  		vector<int> v;
  		v.push_back(1);
  		v.push_back(2);
  		Ballot b0(1,v);
  		Ballot b1(2,v);
  		Ballot b2(3,v);
  		b.AddBallot(b0);
  		b.AddBallot(b1);
  		b.AddBallot(b2);
  		BallotList c = b;
		vector<int> original;
		original.push_back(1);
		original.push_back(2);
		original.push_back(3);
  		c.ShuffleBallots();
		vector<int> shuffled;
		shuffled.push_back(c.get_ballot_list()[0].get_ballot_no());
		shuffled.push_back(c.get_ballot_list()[1].get_ballot_no());
		shuffled.push_back(c.get_ballot_list()[2].get_ballot_no());
  		TS_ASSERT(original != shuffled);
    }

    void test_RemoveBallot() {
		BallotList b;
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		Ballot b0(1,v);
		Ballot b1(2,v);
		Ballot b2(3,v);
		b.AddBallot(b0);
		b.AddBallot(b1);
		b.AddBallot(b2);
		b.RemoveBallot(1);
		for (int i = 0; i < b.ListSize(); i++) {
			TS_ASSERT(b.get_ballot_list()[i].get_ballot_no() != 1);
		}
    }

    void test_AddBallot() {
		BallotList b;
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		Ballot b0(1,v);
		Ballot b1(2,v);
		Ballot b2(3,v);
		Ballot b3(4,v);
		b.AddBallot(b0);
		b.AddBallot(b1);
		b.AddBallot(b2);
		TS_ASSERT(b.ListSize() == 3);
		b.AddBallot(b3);
		TS_ASSERT(b.ListSize() == 4);
		TS_ASSERT(b.get_ballot_list()[3].get_ballot_no() == 4);
    }

    void test_ListSize() {
		BallotList b;
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		Ballot b0(1,v);
		Ballot b1(2,v);
		Ballot b2(3,v);
		b.AddBallot(b0);
		b.AddBallot(b1);
		b.AddBallot(b2);
		TS_ASSERT(b.ListSize() == 3);
    }

	void test_MakeBallot() {
		BallotList b;
		b.MakeBallot("1,2,3");
		TS_ASSERT(b.ListSize() == 1);
		TS_ASSERT(b.get_ballot_list()[0].get_votes()[0] == 1);
		TS_ASSERT(b.get_ballot_list()[0].get_votes()[1] == 2);
		TS_ASSERT(b.get_ballot_list()[0].get_votes()[2] == 3);
    }

	void test_ReadFile() {
		BallotList b;
		b.ReadFile("tests/test.csv",3);
		TS_ASSERT(b.ListSize() == 3);
		TS_ASSERT(b.get_ballot_list()[0].get_votes()[0] == 1);
		TS_ASSERT(b.get_ballot_list()[0].get_votes()[1] == 0);
		TS_ASSERT(b.get_ballot_list()[0].get_votes()[2] == 0);
		TS_ASSERT(b.get_ballot_list()[1].get_votes()[0] == 2);
		TS_ASSERT(b.get_ballot_list()[1].get_votes()[1] == 1);
		TS_ASSERT(b.get_ballot_list()[1].get_votes()[2] == 3);
		TS_ASSERT(b.get_ballot_list()[2].get_votes()[0] == 1);
		TS_ASSERT(b.get_ballot_list()[2].get_votes()[1] == 2);
		TS_ASSERT(b.get_ballot_list()[2].get_votes()[2] == 3);
    }
};
