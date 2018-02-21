/* UVa problem: 10026
 *
 * Topic: Sorting
 *
 * Level: easy
 *
 * Brief problem description:
 *   "We are to help an overburdened shoemaker who must pay a fee for everyday
 *   that he has not finished a job. He has N <= 1000 jobs, the ith job takes
 *   a time T_{i} to complete and has daily unfinished cost of S_{i}.
 *   We must help the shoemaker minimize the amount of fines that he must pay
 *   by finding the optimal order in which to make the shoes." --- algorithmist
 *
 * Solution Summary:
 *   This problem can be solved by using greedy method. Do the job that has
 *   highest fine/time ratio first is the optimal solution.
 *   Proof:
 *      Suppose the optionl solution is OPT = .. + S_{i} * (.. + T_{i-1}) +
 *        S_{i+1} * (.. + T_{i-1} + T_{i}) + ...
 *      If we switch the order of job_i and  job_i+1, the cost will be:
 *        C = .. + S_{i+1} * (.. + T_{i-1}) + S_{i} * (.. + T_{i-1} + T_{i+1}) + ...
 *      Since OPT is the optional solution, OPT <= C， S_{i+1}*T_{i } <= S_{i}*T_{i+1}
 *      Therefore S_{i+1} / T_{i+1} <= S_{i} / T_{i}
 *
 * Used Resources:
 *
 *   Reference: http://www.algorithmist.com/index.php/UVa_10026
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


struct Job {
  int index;
  float ratio;  // fine/time ratio
};

bool cmp(struct Job L, struct Job R) {
  if (L.ratio > R.ratio) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int n_test, n_job, t, s;
  string line;
  // get the number of test case
  cin >> n_test;

  for (int i = 0; i < n_test; i++) {
    cin >> n_job;
    vector<struct Job> v;
    for (int j = 0; j < n_job; j++) {
      cin >> t >> s;
      // cout << t << ' ' << s << endl;
      Job temp_job;
      temp_job.index = j+1;
      temp_job.ratio = (float) s / (float) t;
      v.push_back(temp_job);
    }
    // sort job according to fine/time ratio
    sort(v.begin(), v.end(), cmp);
    // print result to stdout
    // for(vector<struct Job>::iterator it = v.begin(); it != v.end(); ++it) {
    //   cout << it->index;
    // }
    cout << v[0].index;
    for (int k = 1; k < v.size(); k++) {
      cout << ' ' << v[k].index;
    }
    cout << endl;
    // print a blank line
    if (i+1 != n_test) {
      cout << endl;
    }

  }
  return 0;
}
