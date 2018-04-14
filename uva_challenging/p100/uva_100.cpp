/* UVa problem: 100
 *
 * Topic: Other
 *
 * Level: challenging
 *
 * Brief problem description:
 *   "Follow the instructions for all the numbers in the given range and keep
 *   record of the largest cycle" -- Algorithmist
 *
 * Solution Summary:
 *   This problem can be solved by bruteforce. Follows the equation given by
 *   the question, find the maximum cycle.
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

using namespace std;

int three_n_plus_one(int n) {
  int cycle = 1;
  while (n != 1) {
    if (n % 2 == 1) {
      n = 3*n + 1;
    } else {
      n = n >> 1;
    }
    cycle += 1;
  }
  return cycle;
}

int main() {
  int input_i, input_j, i, j, max_cycle_length, cycle;

  while (cin >> input_i >> input_j) {
    if (input_i > input_j) {
      i = input_j;
      j = input_i;
    } else {
      i = input_i;
      j = input_j;
    }

    max_cycle_length = 0;
    for (int n = i; n < j+1; n++) {
      cycle = three_n_plus_one(n);
      if (cycle > max_cycle_length) {
        max_cycle_length = cycle;
      }
    }

    cout << input_i << ' ' << input_j << ' ' << max_cycle_length << endl;
  }
}
