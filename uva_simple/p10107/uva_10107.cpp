/* UVa problem: 10107
 *
 * Topic: Data structures
 *
 * Level: easy
 *
 * Brief problem description:
 *
 *   Keep reading number from stdin, after the new number has been added,
 *   get the current value of the median.
 *
 * Solution Summary:
 *
 *   Keeping a sorted list to store the number. To add a new numebr(num)
 *   in the sorted list, run binary search to find a position index(pos)
 *   of the list that list[pos] <= num. Then get the median of the set of
 *   numbers would only be constant time, since the list is sorted.
 *   Time complexity:
 *     insert a number: O(logn+n), get-median O(1)
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
#include <vector>

using namespace std;

int find_insert_pos(vector<int> v, int num) {
  int l = v.size();
  if (l == 0) { return 0; }
  int min = 0;
  int max = l - 1;

  while (min < max) {
    int mid = (min + max) / 2;
    if (v[mid] < num) {
      min = mid + 1;
    } else if (v[mid] > num) {
      max = mid - 1;
    } else {
      return mid + 1;
    }
  }

  if (v[min] > num) {
    return min;
  } else {
    return min + 1;
  }

  return 0;
}


int main() {
  int num;
  vector<int> v;
  while (cin >> num) {
    // using binary search to find the position to insert the new number
    // keep the vector sorted
    int pos = find_insert_pos(v, num);
    if (pos < 0) { v.push_back(num); }
    else { v.insert(v.begin()+pos, num); }

    // print to stdout
    // for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
    //   cout << *i << ' ';
    // cout << endl;
    int len_v = v.size();
    if (len_v % 2 == 0) {
      cout << (v[(len_v/2)-1] + v[len_v/2])/2  << endl;
    } else {
      cout << v[len_v/2]  << endl;
    }
  }
  return 0;
}
