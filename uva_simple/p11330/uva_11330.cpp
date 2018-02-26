/* UVa problem: 11330
 *
 * Topic: Combinatorics
 *
 * Level: easy
 *
 * Brief problem description:
 *   Andy has n pairs of shoes, but he can not put these shoes in pair (He can
 *   only put a left sheo together with a right shoe, but he has not learned
 *   about puting pairs of shoes with the same color together).
 *   This question is find the minimal number of swiping shoes to let these shoes
 *   to pair up in the right order.
 *
 * Solution Summary:
 *   To solve this problem, we can fix the left shoes, and always try to swipe
 *   the right shoes. We swipe a shoes once a time, any pair of shoes, as long as
 *   they are pair up with same color. Count the number of swipes we do.
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


using namespace std;

int find_min_swipe(int *pairs, int n_pairs) {
  int swipes = 0;
  for (int i = 0; i < n_pairs*2; i+=2) {
    // find a shoe need to be swiped
    if (pairs[i] != pairs[i+1]) {
      for (int j = i+2; j < n_pairs*2; j+=2) {
        if (pairs[i] == pairs[j+1]) {
          pairs[j+1] = pairs[i+1];
          swipes++;
          break;
        }
      }
    }
  }
  return swipes;
}

int main() {
  int n_test, n_pairs, result;
  cin >> n_test;
  for (int i = 0; i < n_test; i++) {
    int pairs[20000];
    cin >> n_pairs;
    for (int j = 0; j < n_pairs*2; j++) {
      cin >> pairs[j];
    }
    result = find_min_swipe(pairs, n_pairs);
    cout << result << endl;
  }
  return 0;
}
