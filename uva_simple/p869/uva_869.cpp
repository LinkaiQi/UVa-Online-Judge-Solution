/* UVa problem: 869
 *
 * Topic: Graph Algorithms
 *
 * Level: easy
 *
 * Brief problem description:
 *   "An airline catalog consists of a list of  ights between pairs of cities.
 *   A trip may be built by sequencing fights. Two airline companies are equivalent
 *   if they o er connections between the same pairs of cities, irrespective of
 *   the number of scales in between.
 *   Given the catalogs of two airline companies, determine if they are equivalent or not."
 *      -- UVa Online Judge
 *
 * Solution Summary:
 *   For each city i, if we have a flight from s to i and a flight from i to t,
 *   we can get city s and city t are connected. Continuing search connected cities
 *   for all transfer city i through above method, we will have a map of connections.
 *   Then compare between the connection maps of two airlines.
 *
 * Used Resources:
 *   Code reference:
 *     https://github.com/Diusrex/UVA-Solutions/blob/master/869%20Airline%20Comparison.cpp
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- Linkai Qi
 */


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define ALPHABET 26

using namespace std;

int N, M;
bool Airline1[ALPHABET][ALPHABET];
bool Airline2[ALPHABET][ALPHABET];

void find_connection() {
  for (int i = 0; i < ALPHABET; i++) {
    for (int s = 0; s < ALPHABET; s++) {
      for (int t = 0; t < ALPHABET; t++) {
        if (Airline1[s][i] && Airline1[i][t])
          Airline1[s][t] = true;
        if (Airline2[s][i] && Airline2[i][t])
          Airline2[s][t] = true;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int k;
  char S, T;
  bool diff;

  cin >> k;
  for (int c = 0; c < k; c++) {

    // initialize airline connection
    for (int i = 0; i < ALPHABET; i++) {
      for (int j = 0; j < ALPHABET; j++) {
        Airline1[i][j] = false; Airline2[i][j] = false;
      }
    }

    // read Airline 1
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> S >> T;
      Airline1[S-'A'][T-'A'] = true;
    }

    // read Airline 2
    cin >> M;
    for (int i = 0; i < M; i++) {
      cin >> S >> T;
      Airline2[S-'A'][T-'A'] = true;
    }

    // find cities connection graph
    find_connection();

    for (int i = 0; i < ALPHABET; i++) {
      cout << Airline1[0][i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < ALPHABET; i++) {
      cout << Airline2[6][i] << ' ';
    }
    cout << endl;

    // compare airlones
    diff = false;
    for (int i = 0; i < ALPHABET; i++) {
      for (int j = 0; j < ALPHABET; j++) {
        if (Airline1[i][j] != Airline2[i][j]) {
          diff = true;
        }
      }
    }

    // show result to stdout
    if (diff)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
    if (c != k-1)
      cout << endl;

  }
  return 0;
}
