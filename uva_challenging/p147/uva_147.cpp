/* UVa problem: 147
 *
 * Topic: Dynamic Programming
 *
 * Level: challenging
 *
 * Brief problem description:
 *   “New Zealand currency consists of $100, $50, $20, $10, and $5 notes and
 *   $2, $1, 50c, 20c, 10c and 5c coins. Write a program that will determine,
 *   for any given amount, in how many ways that amount may be made up.“
 *    -- UVa_Online_Judge
 *
 * Solution Summary:
 *   We can solve this problem using DP:
 *   Convert unit from dollar to cent.
 *   Assume 'c' cents to make change:
 *    ways[c] = Sum of ways[c-t], 
 *    for t in {5,10,20,50,100,200,500,1000,2000,5000,10000}
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

#define MAX_CHANGE 30001

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int Currency[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long Ways[MAX_CHANGE];

void DP() {
  fill(Ways, Ways + MAX_CHANGE, 0);
  Ways[0] = 1;
  int value;

  for (int i = 0; i < 11; i++) {
    value = Currency[i];
    for (int j = value; j < MAX_CHANGE; j+=5) {
      Ways[j] = Ways[j] + Ways[j - value];
    }
  }
}

int main() {
  string s;
  int cents;

  DP();

  while (cin >> s, s != "0.00") {
    cout << setw(6) << s;
    // remove '.', convert dollar to cents
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '.') {
        s.erase(i,1);
        break;
      }
    }
    stringstream ss(s);
    ss >> cents;
    cout << setw(17) << Ways[cents] << endl;
  }

  return 0;
}
