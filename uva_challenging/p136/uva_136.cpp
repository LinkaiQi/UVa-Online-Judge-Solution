/* UVa problem: 136
 *
 * Topic: Data Structures
 *
 * Level: challenging
 *
 * Brief problem description:
 *
 *   Find the 1500th number whose only prime factors are 2, 3 or 5
 *   The sequence: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
 *    (By convention, 1 is included.)
 *   We call them 'ugly' numbers
 *
 * Solution Summary:
 *
 *   To solved this problem, we can try all different number of combinations of
 *   prime factors: '2', '3', '5'. Given a ugly number (whose only prime factors are 2, 3, 5),
 *   we can mulitple it by 2, 3, 5 to get a new number that is also a ugly number.
 *   Therefore, we can use a priority queue that pop the smallest number in the queue.
 *   Each time we find a ugly number k, we push 2k, 3k and 5k to the queue.
 *   Repeat to find the next smallest ugly number 1500 times, we will get the result.
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
#include <queue>

// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
//  find and print the 'NTH_UGLY_NUM'th ugly number
#define NTH_UGLY_NUM 1500

using namespace std;


int main() {
  // create min heap data structure to store potential 'ugly number'
  // c++ STL has max heap implemention in 'queue' library
  priority_queue <int, vector<int>, greater<int> > pq;

  // initial 'pq' with base factors '2', '3', '5'
  pq.push(2);
  pq.push(3);
  pq.push(5);

  int current = 1;
  int min_n;

  for (int i = 0; i < NTH_UGLY_NUM-1; i++) {

    min_n = pq.top(); pq.pop();
    while (min_n <= current) {
      min_n = pq.top(); pq.pop();
    }

    pq.push(min_n*2);
    pq.push(min_n*3);
    pq.push(min_n*5);

    current = min_n;
  }

  cout << "The " << NTH_UGLY_NUM << "'th ugly number is " << current << '.' << endl;

  return 0;
}
