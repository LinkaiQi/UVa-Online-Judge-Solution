/* UVa problem: 454
 *
 * Topic: Strings
 *
 * Level: challenging
 *
 * Brief problem description:
 *   Given lines of phrase and word, find all anagrams in them
 *   (An anagram is a word or phrase formed by rearranging the letters of
 *    another word or phrase)
 *
 * Solution Summary:
 *    Remove all white space, then sort the pharses or words
 *    (ex. horse cart -> acehorrst)
 *    If the sorted pharse/word are the same, they are anagrams
 *
 * Used Resources:
 *
 *   Code inspired by:
 *    https://github.com/SITZ/UVa/blob/master/454.cpp
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- Linkai Qi
 */

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
  // get the number of test case
  int n_test;
  string text;
  getline(cin, text);
  stringstream ss(text);
  ss >> n_test;
  // read a empty line
  getline(cin, text);

  // loop each test case
  for (int i = 0; i < n_test; i++) {
    std::map<string, string> map;
    std::vector<string> v;
    getline(cin, text);
    while (text.length() != 0) {
      // cout << text << endl;
      v.push_back(text);
      // remove the text's white space and sort its charactors
      string s = text;
      s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
      sort(s.begin(), s.end());
      map[text] = s;
      // next line
      getline(cin, text);
    }
    sort(v.begin(), v.end());

    for (int m = 0; m < v.size()-1; m++) {
      for (int n = m+1; n < v.size(); n++) {
        if (map[v[m]] == map[v[n]]) {
          cout << v[m] << " = " << v[n] << endl;
        }
      }
    }
    // print single blank line
    if (i+1 != n_test) { cout << endl; }
  }

  return 0;
}
