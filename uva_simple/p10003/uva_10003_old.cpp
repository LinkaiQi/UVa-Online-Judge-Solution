#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

int L, N;
int CUT[52];

int dc(int s, int t) {
  // cout << s << ' ' << t << endl;
  int min, cost;
  // base case
  if (s+1 == t) {
    return 0;
  }
  // find best cut
  min = INT_MAX;
  for (int i = s+1; i < t; i++) {
    cost = dc(s, i) + dc(i, t) + (CUT[t] - CUT[s]);
    if (min > cost)
      min = cost;
  }
  return min;
}


int main() {
  while (cin >> L, L) {
    cin >> N;
    for (int i = 1; i < N+1; i++) {
      cin >> CUT[i];
    }
    CUT[0] = 0; CUT[N+1] = L;

    cout << "The minimum cutting is " << dc(0, N+1) << "." << endl;

  }

  return 0;
}
