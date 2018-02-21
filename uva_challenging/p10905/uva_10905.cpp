/* UVa problem: 10905
 *
 * Topic: Sorting
 *
 * Level: challenging
 *
 * Brief problem description:
 *   Given a set of integer numbers. Find a way to concatenate them so we can
 *   have the result is the largest.
 *
 * Solution Summary:
 *   Given two number a and b, there are two way we can concatenate them:
 *   ab and ba. If ab > ba, we should put x before y to get the larger number,
 *   vice versa. Therefore, according to this rule, we can sort the integer
 *   numbers that will produced the largest number.
 *
 * Used Resources:
 *
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


bool cmp(string L, string R) {
  return L + R > R + L;
}

void get_largest_num(int n_test) {
  string num;
  vector<string> v;
  // read the set of numbers
  for (int i = 0; i < n_test; i++) {
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end(), cmp);
  // print the sorted numbers to stdout
  for (int j = 0; j < n_test; j++)
    cout << v[j];
  cout << endl;
}


int main() {
  int n_test;

  // debug
  // ifstream inFile;
  // inFile.open("./input.txt");

  while (cin >> n_test && n_test) {
    get_largest_num(n_test);
  }

  // inFile.close();
  return 0;
}
