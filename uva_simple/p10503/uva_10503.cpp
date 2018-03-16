/* UVa problem: 10503
 *
 * Topic: Backtracking
 *
 * Level: easy
 *
 * Brief problem description:
 *   The dominoes solitaire: First, pick two pieces, and put them at two extremes
 *   of a row with a number (n) of spaces between them. After that, other pieces(m)
 *   are picked out to fill the spaces. According to the rules of dominoes: the
 *   number of adjacent dots on two different dominoes must coincide. Find a solution
 *   to fill the space.
 *
 * Solution Summary:
 *   This problem can be easily solved be using Backtracking. Choose a piece from 'M'
 *   , and mark it as 'Used', then, choose the next un-used piece. If we have used 'n'
 *   piece (filled the space), and the number on the last choosed piece is equal to
 *   the number on the ending piece, then we have found a solution.
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

using namespace std;

int N, M, Start, End;
int L_pieces[14], R_pieces[14];
bool Used[14];

bool search_solution(int n, int current) {
  if (n == N) {
    if (current == End) {
      // cout << n << ' ' << current << endl;
      return true;
    } else {
      return false;
    }
  }

  for (int i = 0; i < M; i++) {

    if (Used[i]) { continue; }

    Used[i] = true;
    if (L_pieces[i] == current && search_solution(n+1, R_pieces[i])) {
      return true;
    } else if (R_pieces[i] == current && search_solution(n+1, L_pieces[i])) {
      return true;
    }
    Used[i] = false;
  }

  return false;
}



int main() {
  int temp;
  while (cin >> N >> M, N) {
    cin >> temp >> Start;
    cin >> End >> temp;
    for (int i = 0; i < M; i++) {
      cin >> L_pieces[i] >> R_pieces[i];
      Used[i] = false;
    }

    if (search_solution(0, Start)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    // cout << Start << ' ' << End << endl;
  }
  return 0;
}
