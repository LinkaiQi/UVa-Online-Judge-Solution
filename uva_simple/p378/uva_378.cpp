/* UVa problem: 378
 *
 * Topic: Geometry
 *
 * Level: easy
 *
 * Brief problem description:
 *   Given two lines, a line through (x1,y1) and (x2,y2) and a line through
 *   (x3,y3) and (x4,y4). Find if they are intersected. If intersected, show
 *   the intersetion point of these two lines.
 *
 * Solution Summary:
 *   Convert the line into the format: a1x + b1y = c1, a2x + b2y = c2
 *   Intersection point would be:
 *    x = (c1b2 – c2b1) / (a1b2 – a2b1)
 *    y = (a1c2 - a2c1) / (a1b2 – a2b1)
 *   If there is no intersection point (a1b2 – a2b1) = determinant = 0
 *
 * Used Resources:
 *   Line intersection Algorithm reference:
 *   https://www.geeksforgeeks.org/program-for-point-of-intersection-of-two-lines/
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
#include <stdio.h>

using namespace std;

int x1, y1, x2, y2, x3, y3, x4, y4;


void get_Intersection() {
  // line section 1 represented as a1x + b1y = c1
  double a1 = y2 - y1;
  double b1 = x1 - x2;
  double c1 = a1*(x1) + b1*(y1);

  // line section 2 represented as a2x + b2y = c2
  double a2 = y4 - y3;
  double b2 = x3 - x4;
  double c2 = a2*(x3)+ b2*(y3);

  double det = a1*b2 - a2*b1;
  if (det == 0 && (a1*x3 + b1*y3-c1 == 0)) { cout << "LINE" << endl; return; }
  if (det == 0) { cout << "NONE" << endl; return; }

  double x = (b2*c1 - b1*c2)/det;
  double y = (a1*c2 - a2*c1)/det;
  printf("POINT %.2lf %.2lf\n",x,y);
}


int main() {
  int k;
  cin >> k;

  cout << "INTERSECTING LINES OUTPUT" << endl;
  for (int i = 0; i < k; i++) {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    get_Intersection();
  }
  cout << "END OF OUTPUT" << endl;

  return 0;
}
