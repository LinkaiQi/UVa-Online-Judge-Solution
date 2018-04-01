/* UVa problem: 811
 *
 * Topic: Geometry
 *
 * Level: challenging
 *
 * Brief problem description:
 *   We have n trees, each of the tree has 4 parameters: X, Y, V, L.
 *   X, Y is the position of the tree in the plane, V is its value, and L is the
 *   length of fence that can be built using the wood of the tree. We need to cut
 *   some trees to make a fence for the rest trees.
 *   Come up a cutting solution that can minimize the total value of the cutted tree,
 *   and maximize the number of remaining trees.
 *
 *
 * Solution Summary:
 *   Since the N is no more than 15, we can enumerate all possibilities of cutting combinations.
 *   For each possibility, calculate the if length of the convex hull of remaining trees is
 *   less than the total length of cutted trees. If yes, add it to the solution.
 *   Find the best solution that minimizes the total value of the cutted tree,
 *   and maximizes the number of remaining trees.
 *
 *
 * Used Resources:
 *   Convex Hull Algorithm Reference: (Jarvis’s Algorithm or Wrapping)
 *    https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
 *   Enumerate Tree Cuts Code Reference:
 *    https://github.com/morris821028/UVa/blob/master/volume008
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
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <limits.h>

using namespace std;

int N;
int X[16], Y[16], V[16], L[16];

struct Tree {
  int x, y, v, l;
} Trees[16];
vector<struct Tree> R_trees;


// bool cmp(struct Tree t1, struct Tree t2) {
//   if (t1.x != t2.x) {
//     return t1.x < t2.x;
//   }
//   return t1.y < t2.y;
// }
double dist(struct Tree t1, struct Tree t2) {
  return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(struct Tree p, struct Tree q, struct Tree r){
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0;  // colinear
  return (val > 0)? 1: 2; // clock or counterclock wise
}

// Convex Hull Algorithm Reference: (Jarvis’s Algorithm or Wrapping)
//  https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
double calc_convex_hull() {
  int n = R_trees.size();
  // Initialize Result
  vector<struct Tree> hull;

  // Find the leftmost point
  int l = 0;
  for (int i = 1; i < n; i++) {
    if (R_trees[i].x == R_trees[l].x) {
      if (R_trees[i].y < R_trees[l].y) {
        l = i;
      }
    }
    if (R_trees[i].x < R_trees[l].x)
      l = i;
  }

  // Debug
  // cout << "------------ calc_convex_hull ------------" << endl;
  // for (int i = 1; i < n; i++) {
  //   cout << '(' << R_trees[i].x << ',' << R_trees[i].y << ") ";
  // }
  // cout << endl;

  // Start from leftmost point, keep moving counterclockwise
  // until reach the start point again.  This loop runs O(h)
  // times where h is number of points in result or output.
  int p = l, q;
  do {
    // Add current point to result
    hull.push_back(R_trees[p]);

    // Search for a point 'q' such that orientation(p, x, q) is
    // counterclockwise for all points 'x'.
    q = (p + 1) % n;
    for (int i = 0; i < n; i++) {
      // If i is more counterclockwise than current q, then update q
      if (orientation(R_trees[p], R_trees[i], R_trees[q]) == 2)
        q = i;
    }

    // Now q is the most counterclockwise with respect to p
    // Set p as q for next iteration, so that q is added to result 'hull'
    p = q;
  } while (p != l);  // While we don't come to first point

  // calculate length of the convex hull.
  double ch_length = 0;
  for (int i = 0; i < hull.size()-1; i++) {
    ch_length += dist(hull[i], hull[i+1]);
  }
  ch_length += dist(hull[hull.size()-1], hull[0]);
  return ch_length;
}


int main() {
  int k = 0;
  while (cin >> N, N) {
    if (k) { cout << endl; }
    k++;
    // read input
    for (int i = 0; i < N; i++) {
      cin >> Trees[i].x >> Trees[i].y >> Trees[i].v >> Trees[i].l;
    }
    // initialize value
    double min_value = 0xffffff, extra_wood;
    int min_cuts = INT_MAX, state;
    // enumerate all different cut combinations
    for (int i = 0; i < (1<<N); i++) {
      double total_length = 0, total_value = 0, cuts = 0;
      R_trees.clear();
      // get cut trees
      for(int j = 0; j < N; j++) {
        if((i>>j)&1) {
          total_value += Trees[j].v;
          total_length += Trees[j].l;
          cuts++;
        } else {
          R_trees.push_back(Trees[j]);
        }
      }
      if (total_value > min_value) { continue; }
      // get minimum fence length
      double need_length = calc_convex_hull();
      if (need_length < total_length) {
        if (total_value == min_value && cuts > min_cuts) {
          continue;
        }
        min_value = total_value;
        min_cuts = cuts;
        state = i;
        extra_wood = total_length - need_length;
      }
    }
    // show result to stdout
    cout << "Forest " << k << endl;
    cout << "Cut these trees:";
    for(int i = 0; i < N; i++) {
      if((state>>i)&1)
        cout << ' ' << i+1;
    }
    printf("\nExtra wood: %.2f\n", extra_wood);
    // cout << "\nExtra wood: " << extra_wood << endl;
  }
  return 0;
}
