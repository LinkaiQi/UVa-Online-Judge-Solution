/* UVa problem: 10003
 *
 * Topic: Dynamic Programming
 *
 * Level: easy
 *
 * Brief problem description:
 *   We have to cut a wood stick into pieces. The cutting company charges money
 *   according to the length of the stick. (e.g cut a length of 8 wood stick into
 *   half would cost 8 dollars). Given the length of the wood stick and where to
 *   cut the wood stick (could be many cuts), calculate the order of cuts to minimize
 *   the cost.
 *
 * Solution Summary:
 *   This problem can be solved by using DP.
 *   C(a_1, a_2, ... , a_n) where a_i are places where cuts are possible.
 *   The formula to get the minimum cost would be:
 *    C(a_i, a_j) = min[C(a_i, a_k) + C(a_k, a_j)] + cost(a_i, a_j)
 *    The cost of making a cut is simply: cost(a_i, a_j) = a_j - a_i.
 *
 * Used Resources:
 *   Algorithm reference: Algorithmist
 *      http://www.algorithmist.com/index.php/UVa_10003
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
#include <limits.h>


using namespace std;

int L, N;
int CUT[52];
int MIN[52][52];

int init() {
  for (int i = 0; i < 52; i++) {
    for (int j = 0; j < 52; j++) {
      MIN[i][j] = -1;
    }
  }
  // base case
  for (int i = 0; i < 51; i++) {
    MIN[i][i+1] = 0;
  }
  return 0;
}

int DP(int s, int t) {
  // cout << s << ' ' << t << endl;
  int min, cost;
  // base case
  if (MIN[s][t] != -1) {
    return MIN[s][t];
  }
  // find best cut
  min = INT_MAX;
  for (int i = s+1; i < t; i++) {
    cost = DP(s, i) + DP(i, t) + (CUT[t] - CUT[s]);
    if (min > cost)
      min = cost;
  }
  MIN[s][t] = min;
  return min;
}


int main() {
  while (cin >> L, L) {
    cin >> N;
    for (int i = 1; i < N+1; i++) {
      cin >> CUT[i];
    }
    CUT[0] = 0; CUT[N+1] = L;

    init();
    cout << "The minimum cutting is " << DP(0, N+1) << "." << endl;

  }

  return 0;
}
