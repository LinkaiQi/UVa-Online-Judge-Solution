/* UVa problem: 307
 *
 * Topic: Backtracking
 *
 * Level: challenging
 *
 * Brief problem description:
 *   George took sticks of the same length and cut them randomly until all parts
 *   became at most 50 units long. Now he wants to return sticks to the original
 *   state, but he forgot how many sticks he had originally and how long they
 *   were originally.
 *   Computes the smaillest possible original length of those sticks
 *
 * Solution Summary:
 *   This problem can be solved by using backtracking strategy. We select a stick
 *   fragment at start, and try to find other stick fregments that can compose them
 *   into the orignal stick length. If we cannot find any stick fragment to form
 *   a stick with original length, we return to previous state and try to select
 *   another stick fragment(backtrack)
 *   Pruning search space is very important in this question, since the time limit
 *   constraint for solving the problem is only 3 seconds.
 *      (See Pruning methods in code comments)
 *
 * Used Resources:
 *   Prune method reference: http://naivered.github.io/2016/04/08/Problem_Solving/UVa/UVa-307-Sticks/
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

int Sticks[128];
int N_sticks, Sum, Max_len;
bool Is_used[128];

using namespace std;


// Backtracking
int is_original_len(int goal_len, int current_len, int num_used, int start_at) {
  // --- Debug ---
  // cout << goal_len << ' ' << current_len << ' ' << num_used << endl;

  // base case: we have used all stick fragments
  if (num_used==N_sticks && current_len==goal_len) {
    return true;
  }

  // finish compose a original stick
  if (current_len == goal_len) {
    current_len = 0;
    start_at = 0;
  }
  // find next available stick fragments
  for (int i = start_at; i < N_sticks; i++) {

    if (Is_used[i] || (i && Sticks[i] == Sticks[i-1] && !Is_used[i-1])) {
      continue;
    }

    if (current_len+Sticks[i] <= goal_len) {
      Is_used[i] = true;
      if (is_original_len(goal_len, current_len+Sticks[i], num_used+1, i+1)) {
        return true;
      } else if (current_len == 0) {
        // if the selected stick fragment is the first fragment in the original stick
        // and cannot compose to 'goal_len', then we don't need to check other options,
        // since the fragment won't eventually compose to a 'goal_len' original stick later on.
        Is_used[i] = false;
        return false;
      }
      Is_used[i] = false;
    }
  }

  return false;
}


// 'is_original_len' helper function
int find_min_length() {
  // initialize all sticks to available state
  fill(Is_used, Is_used + N_sticks, false);
  // find minimum possible orignal stick length
  // the orignal length of the sticks must equal or greater than the longest
  // stick fragment.
  for (int i = Max_len; i <= Sum; i++) {
    if (Sum % i == 0 && is_original_len(i, 0, 0, 0)) {
      return i;
    }
  }
  return 0;
}


int main() {
  while (cin >> N_sticks, N_sticks) {

    Sum = 0;
    for (int i = 0; i < N_sticks; i++) {
      cin >> Sticks[i];
      Sum += Sticks[i];
    }

    sort(Sticks, Sticks+N_sticks, greater<int>());
    Max_len = Sticks[0];

    cout << find_min_length() << endl;

    // --- Debug ---
    // for (int i = 0; i < N_sticks; i++) { cout << Sticks[i] << ' '; }
    // cout << endl;
    // cout << "-------" << endl;

  }
  return 0;
}
