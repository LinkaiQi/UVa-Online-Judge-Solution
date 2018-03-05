/* UVa problem: 11195
 *
 * Topic: Backtracking
 *
 * Level: challenging
 *
 * Brief problem description:
 *   N-QUEEN problem:
 *   Count the number of placement of n queens on an n * n board so that no
 *   two queens attack each other.
 *   There are some bad squares where queens cannot be placed. (ad squares
 *   cannot be used to block queens’ attack)
 *
 * Solution Summary:
 *   This problem can be solved by using backtracking. We try to place queens
 *   one by one in different columns. When we place a queen, we check whether
 *   the queen is conflict with other queens. If we have found a way to place
 *   the queens then we backtrack and return 1.
 *
 * Used Resources:
 *   -
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

#define EMPTY_SQUARE 0
#define QUEEN_SQUARE 1
#define BAD_SQUARE 2

using namespace std;


int solve_nq(int *board, int col, int n, int row_taken, int upper_diag, int lower_diag) {
  // base case: all queens has been placed
  if (col == n) {
    return 1;
  }

  // get all safe move from the current column
  int safe_col = ~(row_taken | upper_diag | lower_diag);

  int count = 0;
  for (int row = 0; row < n; row++) {
    if (((safe_col >> row) & 1) && board[row*n+col] != BAD_SQUARE) {
      count += solve_nq(board, col+1, n, row_taken|(1<<row), (upper_diag|(1<<row))<<1, (lower_diag|(1<<row))>>1);
    }
  }
  return count;
}

int main() {
  int n, *board, num_case = 0;
  char cell;
  cin >> n;
  while (n) {
    num_case++;
    // Read board into a one-dimensional array
    board = new int[n*n] ();
    for (int i = 0; i < n*n; i++) {
      cin >> cell;
      if (cell == '*') {
        board[i] = BAD_SQUARE;
      }
    }

    // solve n-queues problem using backtracking. Count the number of solutions
    cout << "Case " << num_case  << ": " << solve_nq(board, 0, n, 0, 0, 0) << endl;

    // free board and read next text
    delete[] board;
    cin >> n;
  }
  return 0;
}
