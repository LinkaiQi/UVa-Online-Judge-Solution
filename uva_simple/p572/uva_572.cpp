/* UVa problem: 558
 *
 * Topic: Graph Algorithms
 *
 * Level: easy
 *
 * Brief problem description:
 *   "Given a grid that divides the land into numerous square plots. A plot
 *   containing oil is called a pocket. If two pockets are adjacent, then they
 *   are part of the same oil deposit. Oil deposits can be quite large and may
 *   contain numerous pockets." -- UVa_Online_Judge
 *   Find how many di erent oil deposits are contained in a grid.
 *
 * Solution Summary:
 *   Flood fill algorithm can easily solve this problem. In each iteration, select
 *   a un-visited pocket, and then use 'dfs' fully explore its pocket neighbour,
 *   mark explored plot as visited. Each iteration is a Oil deposit. Count the
 *   number of iterations.
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
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
char Grid[100][100];

void dfs(int m, int n) {
  // mark as visited
  Grid[m][n] = 'x';
  for (int i = m-1; i <= m+1; i++) {
    for (int j = n-1; j <= n+1; j++) {
      if (i >= 0 && i < M && j >= 0 && j < N && Grid[i][j] == '@') {
        dfs(i, j);
      }
    }
  }
}

int main() {
  while (cin >> M >> N, M) {
    // read grid
    for (int m = 0; m < M; m++) {
      for (int n = 0; n < N; n++) {
        cin >> Grid[m][n];
      }
    }

    // debug
    // for (int m = 0; m < M; m++) {
    //   for (int n = 0; n < N; n++) {
    //     cout << Grid[m][n] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    int count = 0;
    for (int m = 0; m < M; m++) {
      for (int n = 0; n < N; n++) {
        if (Grid[m][n] == '@') {
          count++;
          dfs(m, n);
        }
      }
    }

    cout << count << endl;

  }

  return 0;
}
