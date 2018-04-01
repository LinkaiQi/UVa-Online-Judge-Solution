/* UVa problem: 674
 *
 * Topic: Dynamic Programming
 *
 * Level: easy
 *
 * Brief problem description:
 *   "Suppose there are 5 types of coins: 50-cent, 25-cent, 10-cent, 5-cent,
 *   and 1-cent. We want to make changes with these coins for a given amount
 *   of money. Write a program to find the total number of different ways of
 *   making changes for any amount of money in cents." -- Algorithmist
 *
 * Solution Summary:
 *   We can solve this problem using DP:
 *   Assume 'c' cents to make change:
 *    ways[c] = Sum of ways[c-t], for t in {1,5,10,25,50}
 *
 * Used Resources:
 *   None
 *
 * I hereby certify t`hat I have produced the following solution myself
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

#define MAX_CHANGE 7490

using namespace std;

int Coins[] = {1, 5, 10, 25, 50};
int Ways[MAX_CHANGE];

void DP() {
  fill(Ways, Ways + MAX_CHANGE, 0);
  Ways[0] = 1;
  int value;

  for (int i = 0; i < 5; i++) {
    value = Coins[i];
    for (int j = value; j < MAX_CHANGE; j++) {
      Ways[j] = Ways[j] + Ways[j - value];
    }
  }
}

int main() {
  int n;

  DP();
  while (cin >> n) {
    cout << Ways[n] << endl;
  }
  return 0;
}
