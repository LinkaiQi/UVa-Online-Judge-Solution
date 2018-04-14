/* UVa problem: 191
 *
 * Topic: Geometry
 *
 * Level: challenging
 *
 * Brief problem description:
 *   Given a line segment and a rectangle, decide whether they are intersects.
 *
 * Solution Summary:
 *   First, check if the line segment is inside of the rectangle if yes, they
 *   must intersect.
 *   If not, compare each edge of the rectangle with the line segment, check
 *   if they are intersect. If the line segment intersect with any of the edge
 *   of the rectangle, they must intersect.
 *
 * Used Resources:
 *   line segments intersection algorithm and code reference:
 *    https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- Linkai Qi
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
  int x;
  int y;
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool on_segment(Point p, Point q, Point r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
    q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
    return true;
  return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0;  // colinear
  return (val > 0)? 1: 2; // clock or counterclock wise
}

// Code Reference: https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool do_intersect(Point p1, Point q1, Point p2, Point q2) {
  // Find the four orientations needed for general and
  // special cases
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  // General case
  if (o1 != o2 && o3 != o4)
    return true;

  // Special Cases
  // p1, q1 and p2 are colinear and p2 lies on segment p1q1
  if (o1 == 0 && on_segment(p1, p2, q1)) return true;
  // p1, q1 and q2 are colinear and q2 lies on segment p1q1
  if (o2 == 0 && on_segment(p1, q2, q1)) return true;
  // p2, q2 and p1 are colinear and p1 lies on segment p2q2
  if (o3 == 0 && on_segment(p2, p1, q2)) return true;
  // p2, q2 and q1 are colinear and q1 lies on segment p2q2
  if (o4 == 0 && on_segment(p2, q1, q2)) return true;

  return false; // Doesn't fall in any of the above cases
}

int main() {
  int K, xleft, ytop, xright, ybottom;
  struct Point start;
  struct Point end;
  // store 4 corners of the rectangle
  struct Point rectangle[4];

  cin >> K;
  for (int k = 0; k < K; k++) {
    cin >> start.x >> start.y >> end.x >> end.y;
    cin >> xleft >> ytop >> xright >> ybottom;
    // check if the line segment is inside of the rectangle
    // if yes, they must be intersect
    int x_max = max(xleft, xright); int x_min = min(xleft, xright);
    int y_max = max(ytop, ybottom); int y_min = min(ytop, ybottom);
    if (start.x > x_min && start.x < x_max && start.y > y_min && start.y < y_max) {
      cout << 'T' << endl;
      continue;
    }
    // assign coordinate (x,y) to each vertex of the rectangle
    rectangle[0].x = xleft; rectangle[0].y = ytop;
    rectangle[1].x = xright; rectangle[1].y = ytop;
    rectangle[2].x = xright; rectangle[2].y = ybottom;
    rectangle[3].x = xleft; rectangle[3].y = ybottom;
    // compare each edge of the rectangle with the line segment, check if they are intersect
    bool intersect = false;
    for (int i = 0; i < 4; i++) {
      int j = (i+1) % 4;
      if (do_intersect(start, end, rectangle[i], rectangle[j])) {
        intersect = true;
        break;
      }
    }
    // show result to stdout
    if (intersect) { cout << 'T' << endl; }
    else { cout << 'F' << endl; }
  }
  return 0;
}
