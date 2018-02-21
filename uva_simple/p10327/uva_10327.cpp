/* UVa problem: 10327
 *
 * Topic: Sorting
 *
 * Level: easy
 *
 * Brief problem description:
 *   Given a unsorted list, find the minimum number of flips (exchange two
 *   adjacent terms) that can sort the numbers in ascending order .
 *
 * Solution Summary:
 *   Compare every element in the list with every element after it, if the
 *   element in the front is larger, then the number of flips + 1
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


int calcu_nflip(int *num, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (num[j] < num[i]) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  int n, n_flip;
  int nums[1000];
  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    // perform merge sort O(n*logn)
    n_flip = calcu_nflip(nums, n);
    cout << "Minimum exchange operations : " << n_flip << endl;
  }

}
