#include <cxxtest/TestSuite.h>
#include <cstdlib>
#include <algorithm>
#include "Ballot.h"
#include "BallotList.h"

class BallotListTestSuite : public CxxTest::TestSuite {

  public:

    void ShuffleBallots_test() {
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
    }

    void RemoveBallot_test() {
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
    }

    void AddBallot_test() {
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
    }

    void ListSize_test() {
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
    }

    void MakeBallot_test() {
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
    }

    void ReadFile_test() {
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
    }
}
