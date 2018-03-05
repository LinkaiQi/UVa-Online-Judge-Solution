#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define EMPTY_SQUARE 0
#define QUEEN_SQUARE 1
#define BAD_SQUARE 2

using namespace std;


int check_safety(int *board, int row, int col, int n) {
  // no queens in the same row
  for (int i = 0; i < col; i++) {
    if (board[row*n+i] == QUEEN_SQUARE) {
      return false;
    }
  }
  // no queens in upper left diagonal
  for (int i=row, j=col; i>=0 && j>=0; i--, j--) {
    if (board[i*n+j] == QUEEN_SQUARE) {
      return false;
    }
  }
  // no queens in lower left diagonal
  for (int i=row, j=col; i<n && j>=0; i++, j--) {
    if (board[i*n+j] == QUEEN_SQUARE) {
      return false;
    }
  }
  // if it's safe, then return true
  return true;
}


int solve_nq(int *board, int col, int n) {
  // base case: all queens has been placed
  if (col == n) {
    return 1;
  }
  // try to place the queen in all rows
  int index, count = 0;
  for (int row = 0; row < n; row++) {
    index = row * n + col;
    if (board[index] != BAD_SQUARE && check_safety(board, row, col, n)) {
      board[index] = QUEEN_SQUARE;
      count += solve_nq(board, col+1, n);
      // backtrack to previous board state
      board[index] = EMPTY_SQUARE;
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
    cout << "Case " << num_case  << ": " << solve_nq(board, 0, n) << endl;

    // free board and read next text
    delete[] board;
    cin >> n;
  }
  return 0;
}
