/* UVa problem: 11417
 *
 * Topic: Arithmetic
 *
 * Level: easy
 *
 * Brief problem description:
 *   Given the value of N, find the value of G.
 *   The definition of G is:
 *      G += GCD(i,j) for (0<i<N), (i<j<N+1)
 *
 * Solution Summary:
 *   This is a simple problem. We only need the Euclidean Algorithm for
 *   finding GCD(i,j). Just add up the result of gcd(i,j) would be the solution.
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
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int N, G;
  while (cin >> N, N) {
    G = 0;
    for (int i = 1; i < N; i++) {
      for (int j = i+1; j <= N; j++) {
        G += gcd(i, j);
      }
    }
    cout << G << endl;
  }
  return 0;
}
