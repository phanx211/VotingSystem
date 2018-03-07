/*!******************************************************************************
 * Name            : BallotList.cc
 * Project         : Voting System
 * Description     : Implementation file for BallotList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "BallotList.h"
#include "Ballot.h"

using namespace std;

BallotList::BallotList() {
}


BallotList::BallotList(std::vector<Ballot> ballots) {
	this->ballot_list = ballots;
}

void BallotList::ShuffleBallots() {
  std::random_shuffle ( ballot_list.begin(), ballot_list.end() );
	// for (Ballot b:ballot_list) {
	// 	b.set_ballot_no(i);
	// 	i++;
	// }
}

Ballot BallotList::RemoveBallot(int ballot_no) {
	int i=0;
	Ballot temp;
	for (Ballot b:ballot_list) {
		if (b.get_ballot_no() == ballot_no) {
			temp = ballot_list.at(i);
			ballot_list.erase(ballot_list.begin()+i);
			break;
		}
		i++;
	}
	return temp;
}

void BallotList::AddBallot(Ballot ballot) {
	ballot_list.push_back(ballot);
}

int BallotList::ListSize() {
	return ballot_list.size();
}

/*
int main(void){
  BallotList x;
  Ballot t;
  t.set_ballot_no(5);
  Ballot f;
  f.set_ballot_no(4);
  Ballot c;
  c.set_ballot_no(3);
  Ballot a;
  a.set_ballot_no(2);
  Ballot b;
  b.set_ballot_no(1);
  x.AddBallot(b);
  x.AddBallot(a);
  x.AddBallot(c);
  x.AddBallot(f);
  x.AddBallot(t);
  x.ShuffleBallots();
  x.ShuffleBallots();
  cout << x.get_ballot_list()[0].get_ballot_no() << endl;
  cout << x.get_ballot_list()[1].get_ballot_no() << endl;
  cout << x.get_ballot_list()[2].get_ballot_no() << endl;
  cout << x.get_ballot_list()[3].get_ballot_no() << endl;
  cout << x.get_ballot_list()[4].get_ballot_no() << endl;

  //cout << x.ListSize() << endl;


  return 0;
}
*/
