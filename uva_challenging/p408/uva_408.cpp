/* UVa problem: 406
 *
 * Topic: Number Theory
 *
 * Level: challenging
 *
 * Brief problem description:
 *   One way to generate pseudo-random number is via a function of the form:
 *    seed(x+1) = [seed(x) + STEP] % MOD
 *   Given STEP and MOD, find the seeds are uniformly distributed. (all of the
 *   numbers between and including 0 and MOD-1 will be generated every MOD
 *   iterations of the function.)
 *
 * Solution Summary:
 *   To solve the question, we only need to know whether the greatest common
 *   divisor(gcd) between STEP and MOD is 1. If STEP and MOD are relatively primes
 *   there won't be any gap between the generated 'seed' numbers.
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
 #include <iomanip>


 using namespace std;

 long gcd(long a, long b){
 	if(b == 0) { return a; }
 	else { return gcd(b, a % b); }
 }

 int main() {
   long STEP, MOD;
   while (cin >> STEP >> MOD) {
     // cout << STEP << ' ' << MOD << endl;
     cout << setw(10) << STEP << setw(10) << MOD << "    ";
     if (gcd(STEP, MOD) == 1) {
       cout << "Good Choice\n" << endl;
     } else {
       cout << "Bad Choice\n" << endl;
     }
   }
   return 0;
 }
