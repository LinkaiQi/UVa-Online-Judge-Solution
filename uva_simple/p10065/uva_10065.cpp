/* UVa problem: 10065
 *
 * Topic: Geometry
 *
 * Level: esay
 *
 * Brief problem description:
 *   Given a set of points. We can connect these points to form a polygon.
 *   The area wasted is defined in the questions as the area not covered by the
 *   points but by the convex hull of these points. Find the percentage of the
 *   wasted area.
 *
 * Solution Summary:
 *   This is a straightforward Convex Hull question. First, find the convex hull by
 *   using Jarvis’s Algorithm. And then calculate the area of the convex hull 'AC' and
 *   the original polygon 'AO'. The percentage of wasted space is:
 *     (AC - AO) / AC * 100%
 *   The area of polygon is: 0.5 * the sum the cross products around each its vertex.
 *
 * Used Resources:
 *   Convex Hull Algorithm Reference: (Jarvis’s Algorithm or Wrapping)
 *    https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
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
#include <stdlib.h>   /* abs */

using namespace std;

int N;


struct Point {
  int x, y;
  Point(int a, int b) { x = a; y = b; }
};


int orientation(struct Point p, struct Point q, struct Point r){
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0;  // colinear
  return (val > 0)? 1: 2; // clock or counterclock wise
}

// Convex Hull Algorithm Reference: (Jarvis’s Algorithm or Wrapping)
//  https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
void calc_convex_hull(vector<struct Point> tile, vector<struct Point> &hull) {
  int n = tile.size();
  // Find the leftmost point
  int l = 0;
  for (int i = 1; i < n; i++) {
    if (tile[i].x == tile[l].x) {
      if (tile[i].y < tile[l].y) {
        l = i;
      }
    }
    if (tile[i].x < tile[l].x)
      l = i;
  }

  // Start from leftmost point, keep moving counterclockwise
  // until reach the start point again.  This loop runs O(h)
  // times where h is number of points in result or output.
  int p = l, q;
  do {
    // Add current point to result
    hull.push_back(tile[p]);

    // Search for a point 'q' such that orientation(p, x, q) is
    // counterclockwise for all points 'x'.
    q = (p + 1) % n;
    for (int i = 0; i < n; i++) {
      // If i is more counterclockwise than current q, then update q
      if (orientation(tile[p], tile[i], tile[q]) == 2)
        q = i;
    }

    // Now q is the most counterclockwise with respect to p
    // Set p as q for next iteration, so that q is added to result 'hull'
    p = q;
  } while (p != l);  // While we don't come to first point
}


double calc_area(vector<struct Point> polygon) {
  double area = 0;
  int j, n = polygon.size();
  for (int i = 0; i < n; i++) {
    j = (i+1) % n;
    area += (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y);
  }
  return 0.5 * abs(area);
}


int main() {;
  int a, b, k = 0;
  vector<struct Point> Tile, Packer;

  while (cin >> N, N) {
    k++;
    Tile.clear();
    Packer.clear();

    for (int i = 0; i < N; i++) {
      cin >> a >> b;
      Tile.push_back(Point(a, b));
    }

    calc_convex_hull(Tile, Packer);

    double tile_area = calc_area(Tile);
    // cout << "tile_area: " << tile_area << endl;
    double packer_area = calc_area(Packer);
    // cout << "packer_area: "<< packer_area << endl;

    cout << "Tile #" << k << endl;
    printf("Wasted Space = %.2f %%\n\n", (packer_area - tile_area) / packer_area * 100);
  }
  return 0;
}
