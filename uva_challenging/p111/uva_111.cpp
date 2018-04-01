/* UVa problem: 111
 *
 * Topic: Dynamic Programming
 *
 * Level: challenging
 *
 * Brief problem description:
 *   Given a correct order of several historical events (chronological order).
 *   Input is a historical events sequence that may not in a correct order.
 *   Find the longest (not necessarily contiguous) sequence of events in the input
 *   which are in the correct order relative to each other.
 *
 * Solution Summary:
 *   We can convert this problem to a classic 'Longest Increasing Subsequence'
 *   problem, which can be solved by using DP.
 *
 * Used Resources:
 *   None
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
#include <algorithm>

using namespace std;

int N;
int RANK[32];
int INPUT[32];
int LIS[32];

int calc_LIS() {
  fill(LIS, LIS+32, 1);
  // compute LIS values
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < i; j++) {
      if (RANK[INPUT[j]] < RANK[INPUT[i]] && LIS[i] < LIS[j] + 1) {
        LIS[i] = LIS[j] + 1;
      }
    }
  }
  // find the maximum LIS value
  int max = 0;
  for (int i = 1; i <= N; i++) {
    // cout << LIS[i] << ' ';
    if (LIS[i] > max) {
      max = LIS[i];
    }
  }
  // cout << endl;
  return max;
}

int main() {
  int f, k;

  cin >> N;
  // read ranking
  for (int i = 0; i < N; i++) {
    cin >> RANK[i+1];
  }

  while (cin >> f) {
    // read students history ordering
    INPUT[f] = 1;
    for (int i = 2; i <= N; i++) {
      cin >> k;
      INPUT[k] = i;
    }

    // calcuate LIS problem
    cout << calc_LIS() << endl;

    // debug
    // for (int i = 0; i < N; i++) {
    //   cout << INPUT[i] << ' ';
    // }
    // cout << endl;
  }

  return 0;
}
