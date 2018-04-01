/* UVa problem: 10034
 *
 * Topic: Graph Algorithms
 *
 * Level: easy
 *
 * Brief problem description:
 *   Given a set of points(x, y) in a 2D plane. Find a way to connect the points,
 *   by the minimum length of edge. Edge could be a straight lines bwtween any
 *   pair of points.
 *
 * Solution Summary:
 *   Minimum Spanning Tree Algorithm.
 *   This problem can be solved by using greedy method. First calculate the
 *   length of all possible edges. The number of edges would be (n^2) if we have
 *   n points in total.
 *   Sort the edge based on its length in ascending order.
 *   Then, try to use the edge from length lower to higher. If a edge can
 *   link a un-connected point to a connected point, use the point.
 *   Repeat the above process, until all n points have been connnected.
 *
 * Used Resources:
 *   -
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
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

float X_axis[128], Y_axis[128];
bool Connected[128];
vector<pair<pair<int, int>, float> > Distance;


bool cmp(pair<pair<int, int>, float> d1, pair<pair<int, int>, float> d2) {
  return d1.second < d2.second;
}


float calc_distance(int p1, int p2) {
  float x_diff = (X_axis[p1] - X_axis[p2]);
  float y_diff = (Y_axis[p1] - Y_axis[p2]);
  float dist = sqrt(x_diff * x_diff + y_diff * y_diff);
  return dist;
}

int main() {
  int K, N;

  cin >> K;
  for (int k = 0; k < K; k++) {
    // read input
    cin >> N;
    for (int n = 0; n < N; n++) {
      cin >> X_axis[n] >> Y_axis[n];
      Connected[n] = false;
    }

    // get distance between each point
    Distance.clear();
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
        // Distance[(i, j)] = calc_distance(i, j);
        float dist = calc_distance(i, j);
        Distance.push_back(make_pair(make_pair(i, j), dist));
      }
    }

    // sort the distance in ascending order
    sort(Distance.begin(), Distance.end(), cmp);

    // Debug
    // for (int i = 0; i < Distance.size(); i++) {
    //   cout << Distance[i].second << ' ';
    // }
    // cout << endl;

    int num = 2;
    int a = Distance[0].first.first;
    int b = Distance[0].first.second;
    Connected[a] = true; Connected[b] = true;
    float min_dist = Distance[0].second;

    while (num < N) {
      for (int i = 0; i < Distance.size(); i++) {
        int a = Distance[i].first.first;
        int b = Distance[i].first.second;
        if ((!Connected[a] and Connected[b]) || (Connected[a] and !Connected[b])) {
          Connected[a] = true; Connected[b] = true;
          min_dist += Distance[i].second;
          num++;
          break;
        }
      }
    }

    cout << setprecision(2) << fixed << min_dist << endl;

    if (k != K-1)
      cout << endl;

  }

  return 0;
}
