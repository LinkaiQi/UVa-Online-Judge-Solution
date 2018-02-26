/* UVa problem: 202
 *
 * Topic: Arithmetic
 *
 * Level: challenging
 *
 * Brief problem description:
 *   Every rational number (fraction) has a repeating cycle. Given the numerator
 *   and denominator of a fraction, determines their repeating cycles
 *    ( e.g 5/7 -> 0.(714285) repeating_cycle:714285 )
 *
 * Solution Summary:
 *   Do division operation continously until we find a repeat reminder.
 *   If a same reminder occurs twice, then we have found the repeating decimals.
 *   The repeating decimals start with the first occurence of the reminder,
 *   end with the second occurence of the reminder.
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
#include <sstream>
#include <string>

/*

5/43 = 0.(116279069767441860465)
   21 = number of digits in repeating cycle

*/

using namespace std;

void find_repeating_decimals(int n, int d) {
  // the largest possible reminder could be 2999,
  // since none of the input (denominator) exceeds 3000
  bool reminder[3000] = {false};
  // vector<int> v;

  cout << n/d << '.';
  n = n % d;
  reminder[n] = true;
  int n2 = n;

  bool find_repeat = false; int start_rem;
  while (!find_repeat) {
    n = n * 10;
    // v.push_back(n/d);
    n = n % d;
    if (reminder[n]) { find_repeat = true; start_rem = n; }
    else { reminder[n] = true; }
  }

  int n_find = 0; int repeat_digit = 0; int i = 0;
  if (n2 == start_rem) {
    cout << '(';
    n_find++; repeat_digit++;
  }
  while (n_find < 2) {
    n2 = n2 * 10;

    // v.push_back(n/d);
    if (i < 50) {
      cout << n2/d;
    }

    n2 = n2 % d;

    if (n2 == start_rem) {
      if (n_find == 0 && i < 50)
        cout << '(';
      if (n_find == 1 && i < 50)
        cout << ')' << endl;
      n_find++;
    }

    // count the number of repeat digits
    if (n_find == 1)
      repeat_digit++;
    if (i == 50) {
      cout << "...)" << endl;
    }

    i++;
  }

  cout << "   " << repeat_digit << " = number of digits in repeating cycle\n" << endl;

  // bool end = false;
  // while (true) {
  //   // n2 = n2 * 10;
  //   if (n2 % d == start_rem && !end) {
  //     cout << '(';
  //     end = true;
  //   }
  //   else if (n2 % d == start_rem && end) {
  //     cout << ')' << endl;
  //     break;
  //   }
  //   n2 = n2 * 10;
  //   cout << n2/d;
  //   n2 = n2 % d;
  // }


  // cout << '$' << start_rem << endl;
  // for (int i = 0; i < 30; i++) {
  //   n2 = n2 * 10;
  //   cout << n2/d;
  //   n2 = n2 % d;
  //   if (n2 == start_rem) {
  //     cout << '|';
  //   }
  // }
  // cout << endl;

}

int main() {
  string str;
  int numerator, denominator;

  while (getline(cin, str)) {
    stringstream ss(str);
    ss >> numerator >> denominator;
    // cout << '#' << numerator << ' ' << denominator << endl;
    cout << numerator << "/" << denominator << " = ";
    find_repeating_decimals(numerator, denominator);
  }

  return 0;
}
