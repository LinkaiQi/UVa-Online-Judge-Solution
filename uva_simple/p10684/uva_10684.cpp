/* UVa problem: 10684
 *
 * Topic: Dynamic Programming
 *
 * Level: easy
 *
 * Brief problem description:
 *   Given a sequence of bets 'SEQ', the bets could be positive number or negative number.
 *   Find the maximum possible gain out of a sequence of bets.
 *
 * Solution Summary:
 *   This problem is a maximum subsequence sum problem.
 *   Let MAX[i] be the maximum subsequence sum we can get if we end the subsequence
 *   at position i. I have equation:
 *      MAX[i] = MAX[i-1] + SEQ[i]
 *   If MAX[i] is an negative value, we could get a larger result by discarding
 *   all previous sum, which makes MAX[i] = 0
 *   The maximum value of MAX[i], for 0 < i < N, would be the solution.
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
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int N, SEQ[10000], MAX[10000];

int main() {
  while (cin >> N, N) {
    // read input
    for (int i = 0; i < N; i++) {
      cin >> SEQ[i];
    }
    // calculate largest sub sequence
    if (SEQ[0] > 0) { MAX[0] = SEQ[0]; }
    else { MAX[0] = 0; }
    for (int i = 1; i < N; i++) {
      if (MAX[i-1]+SEQ[i] > 0) {
        MAX[i] = MAX[i-1] + SEQ[i];
      } else {
        MAX[i] = 0;
      }
    }
    // find max streak
    int max_streak = 0;
    for (int i = 0; i < N; i++) {
      if (MAX[i] > max_streak) { max_streak = MAX[i]; }
    }
    // print result to stdout
    if (max_streak > 0) {
      cout << "The maximum winning streak is " << max_streak  << '.' << endl;
    } else {
      cout << "Losing streak." << endl;
    }
  }
  return 0;
}
