/* UVa problem: 406
 *
 * Topic: Number Theory
 *
 * Level: challenging
 *
 * Brief problem description:
 *   Find all prime numbers between 1 and N (1 <= N <= 1000) form a prime list.
 *   Given a integer C, return all 2C prime numbers from the middle of the prime
 *   list, if the list has even length. Return 2C-1 prime numbers otherwises.
 *
 * Solution Summary:
 *   Since N < 1001, we only need all the prime numbers less than 1001.
 *   Mark all number n as prime number at first, loop all numbers from 2 to n,
 *   If the visting number 'i' is a prime number, add 'i' to the prime list, and
 *   mark all the muliples of 'i' as non-prime number. Continue still 'i' equals
 *   1000;
 *   Through this method, we can find all primes < 1001 approximately in O(nlogn),
 *   then return the prime numbers in the middle of the prime list is easy.
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
#include <algorithm>

using namespace std;

int num_primes = 0;
int primes[1024];

// get all primes that is less than 1001 (maximum value of int)
void get_all_primes() {
  bool is_prime[1001];
  fill_n(is_prime, 1001, true);

  // define 1 is a prime number
  primes[num_primes] = 1;
  num_primes++;

  for (int i = 2; i < 1001; i++) {
    if (is_prime[i]) {
      primes[num_primes] = i;
      num_primes++;
      for (int j = i+i; j < 1001; j+=i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  get_all_primes();
  // for (int i = 0; i < num_primes; i++) {
  //   cout << primes[i] << ' ';
  // }
  // cout << endl;
  int N, C, mid, end, p_start, p_end;
  // cout << num_primes << endl;
  while (cin >> N >> C) {
    end = upper_bound(primes, primes+num_primes, N) - primes;
    // if even number of prime numbers, print the 2C prime number from center
    if (end % 2 == 0) {
      mid = end / 2;
      p_start = mid - C;
      p_end = mid + C;
    }
    // if odd number of prime numbers, print the 2C - 1 prime number from center
    else {
      mid = end / 2;
      p_start = mid - C + 1;
      p_end = mid + C;
    }
    // if the size of the center list exceeds the limits of the prime numbers
    // between 1 and N, the list of prime numbers bettween 1 and N should be printed
    if (p_start < 0) {
      p_start = 0; p_end = end;
    }
    // show result
    cout << N << ' '<< C << ':';
    for (int i = p_start; i < p_end; i++) {
      cout << ' ' << primes[i];
    }
    cout << '\n' << endl;
  }


  return 0;
}
