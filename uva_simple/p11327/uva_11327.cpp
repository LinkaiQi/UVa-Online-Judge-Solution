/* UVa problem: 11327
 *
 * Topic: Number Theory
 *
 * Level: easy
 *
 * Brief problem description:
 *   Enumerating all rational numbers in order of:
 *   0/1, 1/1, 1/2, 1/3, 2/3, 1/4, 3/4, 1/5, 2/5, 3/5, 4/5, 1/6, 5/6, 1/7, ......
 *   Find the k-th rational number.
 *
 * Solution Summary:
 *   Using Euler's phi function to find the denominator of the rational numbers.
 *   Euler's phi function can give how many positive integers up to n that are
 *   relatively prime to n. Use this proporty we can find how many rational
 *   numbers with the denominator n.
 *   After we get the denominator, we can go through all possible numerators that
 *   does not share common factors with the denominator to find the result (gcd -> 1).
 *
 * Used Resources:
 *   Phi function code reference:
 *    https://github.com/Diusrex/UVA-Solutions/blob/master/
 *          11327%20Enumerating%20Rational%20Numbers.cpp
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
#include <math.h>

#define MAX_INT 32767

using namespace std;

int num_primes = 0;
int primes[4096];

// get all primes that is less than 32767 (maximum value of int)
void get_all_primes() {
  // 0 and 1 is not a prime number
  bool is_prime[MAX_INT];
  fill_n(is_prime, MAX_INT, true);
  // not_prime[0] = false;
  // not_prime[1] = false;

  for (int i = 2; i < MAX_INT; i++) {
    if (is_prime[i]) {
      primes[num_primes] = i;
      num_primes++;
      for (int j = i+i; j < MAX_INT; j+=i) {
        is_prime[j] = false;
      }
    }
  }
}

// Code Reference: https://github.com/Diusrex/UVA-Solutions/blob/master/
//  11327%20Enumerating%20Rational%20Numbers.cpp
int phi(int n) {
  long long PF_idx = 0, PF = primes[PF_idx], ans = n;

  while (PF * PF <= n)
  {
      if (n % PF == 0) ans -= ans / PF;
      while (n % PF == 0) n /= PF;
      PF = primes[++PF_idx];
  }

  if (n != 1) ans -= ans / n;

  return ans;
}

/*
// The Euler Phi Function
int phi(int n) {
  // find all prime factors of n
  vector<int> factors, power;

  for (int i = 0; i < num_primes; i++) {
    if (n % primes[i] == 0) {
      factors.push_back(primes[i]);
      int p = 0;
      while (n % primes[i] == 0) {
        n = n / primes[i];
        p++;
      }
      power.push_back(p);
    }
    if (n == 1) {
      // cout << "call break in: " << primes[i] << endl;
      break;
    }
  }

  // Equation refer:
  //  https://www.whitman.edu/mathematics/higher_math_online/section03.08.html
  // ϕ(2^3 * 3^4 * 7^2) = ϕ(2^3)ϕ(3^4)ϕ(7^2)=(2^3−2^2)(3^4−3^3)(7^2−7^1)

  // prime number
  if (factors.size() == 0) {
    return n-1;
  }

  int res = 1;
  for (int i = 0; i < factors.size(); i++) {
    res = res * (pow(factors[i], power[i]) - pow(factors[i], power[i]-1));
  }

  return res;
}
*/

int gcd(long a, long b){
	if(b == 0) { return a; }
	else { return gcd(b, a % b); }
}


int main() {
  long long accumulate_phi[200002];

  get_all_primes();


  accumulate_phi[0] = 0;
  accumulate_phi[1] = 1;
  accumulate_phi[2] = 3;
  for (long i = 3; i < 200002; i++) {
    accumulate_phi[i] = accumulate_phi[i-1] + phi(i-1);
  }


  // ---- debug -----
  // for (int i = 0; i < 100; i++) {
  //   cout << primes[i] << ' ';
  // }
  // cout << endl;
  // cout << num_primes << endl;
  //
  // cout << phi(23454) << endl;
  // ----- end ------

  long long k;
  cin >> k;
  while (k) {
    // cout << "# "<< k << endl;
    if (k == 1 || k == 2) {
      cout << k-1 << "/1" << endl;
    } else {
      long i;
      for (i = 1; i < 200002; i++) {
        if (accumulate_phi[i] > k) {
          break;
        }
      }
      long denominator = i-1;

      long long offset = k - accumulate_phi[denominator];
      long numerator = 1;
      while (offset != 0) {
        numerator++;
        if (gcd(numerator, denominator) == 1) {
          offset--;
        }
      }
      // output
      cout << numerator << '/' << denominator << endl;
    }

    cin >> k;
  }

  return 0;
}
