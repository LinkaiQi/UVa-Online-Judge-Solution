/* UVa problem: 10041
 *
 * Topic: Sorting
 *
 * Level: easy
 *
 * Brief problem description:
 *
 *   Given a set of numbers (street number), find a number that minimizing the
 *   sum of distances to the numbers in the set.
 *    distance: d(i,j) = |si − sj|
 *
 * Solution Summary:
 *
 *   This problem can be solved by brute force. Find the minimum and maximum
 *   number(street number) in set, the number that will minimize sum of distances
 *   cannot fall outside the [min, max] range. Thus, we can calculate the sum
 *   distances of all the numbers in that range.
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
#include <stdlib.h>
#include <limits.h>
#include <string>

using namespace std;

long get_min_distance(int min, int max, int *relatives, int size) {
  long min_sun = LONG_MAX;
  // cout << min << ' ' << max << endl;
  for (int st = min; st < max; st++) {
    // calculate sum
    long sum = 0;
    for (int i = 0; i < size; i++) {
      sum = sum + abs(relatives[i] - st);
      // cout << sum << endl;
    }
    // get minimum value of sum
    if (sum < min_sun) { min_sun = sum;}
  }
  return min_sun;
}

int main() {
  int n_test, relatives[500];
  cin >> n_test;
  for (int i = 0; i < n_test; i++) {
    int r_size;
    // read number of relatives
    cin >> r_size;
    int max = 0; int min = 30000; int st_num;
    for (int j = 0; j < r_size; j++) {
      // relative street number
      cin >> st_num;
      if (st_num < min) { min = st_num; }
      if (st_num > max) { max = st_num; }
      relatives[j] = st_num;
    }
    long res = get_min_distance(min, max, relatives, r_size);
    cout << res << endl;
  }

  return 0;
}
