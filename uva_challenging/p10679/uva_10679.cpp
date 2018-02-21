/* UVa problem: 10679
 *
 * Topic: Strings
 *
 * Level: challenging
 *
 * Brief problem description:
 *
 *  Given a text string and a set of patterns as input, determine patterns
 *   that match the text.
 *
 * Solution Summary:
 *   This problem can be solved by brute force, but it will cost O(mn),
 *   m is the length of text, and n is the length of the pattern.
 *   There are few linear time algorithms can solved this question in linear time
 *   I implemented the KMP Algorithm. First KMP algorithm calcualte the Prefix
 *   function of the pattern. Given a pattern p, Prefix function is the length of
 *   the longest prefix of p that is a proper suffix of P(q).
 *   The Prefix function gives the ideas of how much characters we can jump when we
 *   encounter a miss match
 *   The time complixity of the KMP algorithm is O(m+n)
 *
 *
 * Used Resources:
 *
 *   implemented using KMP algorithm
 *    https://brilliant.org/wiki/knuth-morris-pratt-algorithm/
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

// a b a b a c a
// 0 0 1 2 3 0 1
void calc_prefix(string P, int *prefix) {
  prefix[0] = 0;
  int j = 0;
  for (int i = 1; i < P.length(); i++) {
    while (j>=0 && P[j]!=P[i]) {
      if (j >= 1) {
        j = prefix[j-1];
      } else {
        j--;
      }
    }
    j++;
    prefix[i] = j;
  }
}

bool search_pattern(string S, string P, int *prefix) {
  int n_S = S.length();
  int n_P = P.length();
  int j = 0;
  for (int i = 0; i < n_S; i++) {
    if (j == n_P) { return true; }
    if (S[i] == P[j]) {
      j++;
    } else {
      if (j-1 >= 0) {
        j = prefix[j-1] + 1;
      } else {
        j = 0;
      }
    }
  }
  if (n_S == n_P && j == n_P) {
    return true;
  }
  return false;
}


int main() {
  int n_test;
  cin >> n_test;
  for (int i = 0; i < n_test; i++) {
    string S;
    int n_p;
    cin >> S >> n_p;
    for (int j = 0; j < n_p; j++) {
      string P;
      int prefix[1000];
      cin >> P;
      calc_prefix(P, prefix);
      if (search_pattern(S, P, prefix)) {
        cout << 'y' << endl;
      } else {
        cout << 'n' << endl;
      }
    }
  }

  return 0;
}
