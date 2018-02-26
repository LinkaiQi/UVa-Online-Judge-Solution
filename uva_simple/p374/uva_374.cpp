/* UVa problem: 374
 *
 * Topic: Number Theory
 *
 * Level: easy
 *
 * Brief problem description:
 *   Given B, P, M, try to compute B^P mod M. They could be very large number.
 *   B and P are integers in range of [0, 2147483647], M is an integer in range
 *   [1, 46340].
 *
 * Solution Summary:
 *   We can use the property of repeating squaring to compute the value efficiently
 *   ex. 3^2 = 9 = 3 * 3
 *       3^4 = 81 = 9 * 9
 *       ...
 *   and the property of:
 *   (a * b) mod m = (a mod m) * (b mod m) mod m
 *   to compute the value efficiently
 *
 * Used Resources:
 *   Reference: Algorithmist,
 *   http://www.algorithmist.com/index.php/UVa_374
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


using namespace std;

long calc_mod(long B, long P, long M) {
  if (P == 0) {
    return 1;
  }
  long mod2 = calc_mod(B, P/2, M);
  if (P % 2 == 0) {
    return (mod2 * mod2) % M;
  } else {
    return (((mod2 * mod2) % M) * B) % M;
  }
}

int main() {
  long B, P, M;
  while (cin >> B >> P >> M) {
    // cout << B << ' '<< P << ' ' << M << endl;
    cout << calc_mod(B, P, M) << endl;
  }
  return 0;
}
