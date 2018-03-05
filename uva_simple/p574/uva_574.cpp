/* UVa problem: 574
 *
 * Topic: Backtracking
 *
 * Level: easy
 *
 * Brief problem description:
 *   Given a specified total 't' and a list of 'n' integers, find all distinct sums
 *   using numbers from the list that add up to 't'
 *
 * Solution Summary:
 *   The problem can be solved by recursive backtracing. Try each number in the list,
 *   and move forward. If current using numbers cannot sum up to 't', return to its
 *   previous state(backtracing) and try another number.
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
#include <map>
#include <algorithm>


using namespace std;

int T, N, Nums[12];
map<vector<int>, bool> Record;
vector<int> V;

void find_sum(int idx, int sum, vector<int> current_nums) {
  // base case
  if (sum == T) {
    if (Record.count(current_nums) == 1) {
      return;
    }
    // print result to stdout
    cout << current_nums[0];
    for (int i = 1; i < current_nums.size(); i++) {
      cout << '+' << current_nums[i];
    }
    cout << endl;
    // save the 'current_nums' to 'Record' to avoid duplicated result
    Record[current_nums] = true;
    return;
  }

  for (int i = idx; i < N; i++) {
    if (sum + Nums[i] > T) {
      continue;
    }
    V.push_back(Nums[i]);
    find_sum(i+1, sum+Nums[i], V);
    V.pop_back();
  }

  return;
}

int main() {
  while (cin >> T >> N, N) {
    for (int i = 0; i < N; i++) {
      cin >> Nums[i];
    }
    cout << "Sums of " << T << ':' << endl;

    Record.clear(); V.clear();
    find_sum(0, 0, V);

    if (!Record.size()) {
      cout << "NONE" << endl;
    }
  }
  return 0;
}
