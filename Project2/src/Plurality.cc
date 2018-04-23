/*!******************************************************************************
 * Name            : Plurality.cc
 * Project         : Voting System
 * Description     : Implementation file for Plurality
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "../include/Plurality.h"

using namespace std;

Plurality::Plurality() : Election() {}

Plurality::Plurality(int num_seats, int num_candidates, int num_ballots)
    : Election(num_seats, num_candidates, num_ballots) {}

int Plurality::ReturnHighestVoteIndex(Ballot b) {
  int min = 999;
  int min_index = 0;

  // Technically we can just look for 1 but This might be useful for STV
  // Finds the index where the higehest vote exists
  for (unsigned i = 0; i < b.get_votes().size(); i++) {
    if (b.get_votes()[i] != 0 && b.get_votes()[i] < min) {
      min = b.get_votes()[i];
      min_index = i;
    }
  }
  return min_index;
}
// The plurality algorithm reads the ballots and distributes them to the
// respective candidates.
// It then calls ReturnWinners which will return the winners of the seats
void Plurality::Algorithm() {
  int bal_no;
  int highest_index;
  ofstream logFile, audit;
  logFile.open("logFile.txt");
  audit.open("Audit.txt");

//Things for audit file
  //audit.open("Audit.txt");
  audit << "Plurality" << endl;
  for (unsigned i = 0; i < get_candidates().get_candidate_list().size(); i++)
  {
	  //getting candidate names
      audit << "Candidate Names: " << get_candidates().get_candidate_list()[i].get_name() << endl;
  }
  audit << "Number of Candidates: " << get_num_candidates() << endl;

  // current date/time based on current system
  time_t now = time(0);
  //cout << "Number of sec since January 1,1970:" << now << endl;
  tm *ltm = localtime(&now);
  // print various components of tm structure.
 audit << "The Date is: " << ltm-> tm_mday << " " << 1 + ltm-> tm_mon << " " << 1900 + ltm->tm_year<<endl ;



  // The following loop goes through the original list of ballots and
  // distributes
  // the ballots to the respective candidate based on the rankings on the ballot
  int ballots = get_num_ballots();
  for (int i = 0; i < ballots; i++) {
    // Gets the highest vote index in a given ballot from 'ballots'
    highest_index = ReturnHighestVoteIndex(get_ballots().get_ballot_list()[0]);

    // Gets ballot no of current ballot
    bal_no = get_ballots().get_ballot_list()[0].get_ballot_no();

    // Moves Ballot from 'ballots' to candidate using the ballot no in 'bal_no'
    MoveBallot(
        bal_no, get_ballots(),
        get_candidates().get_candidate_list()[highest_index].get_votes());

    cout << "Round: " << i << endl;
    logFile << "Round: " << i << endl;
    for (unsigned j = 0; j < get_candidates().get_candidate_list().size(); j++) {
      if (get_candidates().get_candidate_list()[j].get_votes().ListSize() > 0) {
        cout << "Candidate: " << j << " Votes: "
             << get_candidates().get_candidate_list()[j].get_votes().ListSize()
             << endl;
        logFile << "Candidate: " << j << " Votes: "
            << get_candidates().get_candidate_list()[j].get_votes().ListSize()
            << endl;
      }
    }
  }

  // for (unsigned i = 0; i < get_candidates().get_candidate_list().size(); i++) {
  //   cout << "Candidate: " << i << " Votes: "
  //        << get_candidates().get_candidate_list()[i].get_votes().ListSize()
  //        << endl
  //   logFile << "Candidate: " << i << " Votes: "
  //       << get_candidates().get_candidate_list()[i].get_votes().ListSize()
  //       << endl;
  // }

  // Run the ReturnWinners function from candidate_list which will fill a winner
  // vector with the candidates that won the seats

  vector<Candidate> winners = get_candidates().ReturnWinners(get_num_seats());
  // This section writes to the log file.
  if (get_num_seats() > 1) {
    cout << "THE WINNERS ARE: ";
    logFile << "THE WINNERS ARE: ";
    audit << "THE WINNERS ARE: ";
  } else {
    cout << "THE WINNER IS: ";
    logFile << "THE WINNER IS: ";
    audit << "THE WINNER IS: ";
  }
  for (unsigned i = 0; i < winners.size(); i++) {
    cout << winners[i].get_name();
    logFile << winners[i].get_name();
    audit << winners[i].get_name();
    if (i < winners.size() - 1) {
      cout << ", ";
        logFile << ", ";
        audit << ", ";
    }
  }
  cout << endl;
  logFile << endl;
  audit << endl;

  cout << endl << "##########################################" << endl;
  if (get_num_seats() > 1) {
    cout << "THE WINNERS ARE: ";
  } else {
    cout << "THE WINNER IS: ";
  }
  for (unsigned i = 0; i < winners.size(); i++) {
    cout << winners[i].get_name();
    if (i < winners.size() - 1) {
      cout << ", ";
    }
  }
  cout << endl << "##########################################" << endl;
  cout << endl;
  logFile.close();
  audit.close();

}
