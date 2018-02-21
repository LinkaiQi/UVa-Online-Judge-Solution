/* UVa problem: 11512
 *
 * Topic: String
 *
 * Level: challenging
 *
 * Brief problem description:
 *
 *   Find the longest common substring
 *
 * Solution Summary:
 *
 *   1. Construct suffix array from the string,
 *   2. Find the longest common prefix in the suffix
 *      (only needs to compare adjacent strings)
 *
 * Used Resources:
 *
 *   build suffix array algorithm referenced from:
 *   https://www.geeksforgeeks.org/suffix-array-set-1-introduction/
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
#include <algorithm>

using namespace std;

struct suffix {
  string suff;
  int index;
};

bool cmp (struct suffix a, struct suffix b) {
  return a.suff < b.suff;
}

int main() {
  int cases;
  string str;
  cin >> cases;
  for (int l = 0; l < cases; l++) {
    cin >> str;
    // construct suffix array
    int n = str.length();
    struct suffix suffixes[n];
    for (int i = 0; i < n; i++) {
      suffixes[i].suff = str.substr(i);
      suffixes[i].index = i;
    }
    sort(suffixes, suffixes+n, cmp);
    // find the longest common prefix in the suffix (compare adjacent strings)
    int max_len = 0;
    int occurence = 0;
    string longest_substr;
    for (int i = 0; i < n-1; i++) {
      string str1 = suffixes[i].suff;
      string str2 = suffixes[i+1].suff;
      int common_len = 0;
      int m = min(str1.length(), str2.length());
      for (int j = 0; j < m; j++) {
        if (str1[j] == str2[j]) {
          common_len++;
        } else { break; }
      }
      if (common_len > max_len) {
        occurence = 2;
        max_len = common_len;
        longest_substr = str1.substr(0, common_len);
      } else if (longest_substr == str1.substr(0, common_len)) {
        occurence++;
      }
    }
    // print result in stdout
    if (max_len) {
      cout << longest_substr << " " << occurence << endl;
    } else {
      cout << "No repetitions found!" << endl;
    }
  }

  return 0;
}
