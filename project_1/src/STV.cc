/*!******************************************************************************
 * Name            : BallotList.cc
 * Project         : Voting System
 * Description     : Implementation file for BallotList
 * Original Authors : Maxwell Dahl, Sanjana Jonnalagadda, Anthony Phan,
                      Ronny Yogiswara
 ******************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../include/STV.h"

using namespace std;

STV::STV() : Election() {}

STV::STV(int num_seats, int num_candidates, int num_ballots) : Election(num_seats, num_candidates, num_ballots) {
  CalculateDroop();
}

void STV::CalculateDroop() {
  droop = floor(get_num_ballots()/(get_num_seats()+1)) + 1;

}
void STV::Algorithm() {

}
