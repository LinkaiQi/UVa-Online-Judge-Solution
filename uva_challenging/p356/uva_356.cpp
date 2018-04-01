/* UVa problem: 356
 *
 * Topic: Geometry
 *
 * Level: challenging
 *
 * Brief problem description:
 *   "A circle 2n − 1 units in diameter has been drawn centered on a 2n by 2n chessboard.
 *   Write a program that will determine the number of cells of the board which
 *   contain a segment of the circle and the number of cells of the board which
 *   lie entirely inside the circle." -- UVa_online_Judge
 *
 * Solution Summary:
 *   Since a circle is symmetric in both up-bottom and left-right direction, we
 *   only need to consider the 1/4 of the circle, (e.g top-right corner).
 *   Each cell in the chessboard is a square which has upper right and lower left
 *   vertice. If only the lower left vertix (x, y) of the cell is inside the circle
 *   (x^2 + y^2 < r^2), we can say that the cell contain a segment of the circle.
 *   If both lower left vertix (x, y), and upper right vertix (x+1, y+1) of the
 *   cell is inside the circle, the cell lie entirely inside the circle.
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
 #include <algorithm>

 using namespace std;

 bool in_circle(int x, int y, float r_sq) {
   return (x*x + y*y) < r_sq;
 }

 int main() {
   int n; bool first_case = true;
   while (cin >> n) {
     // print blank line to separate your output for successive inputs
     if (first_case) { first_case = false; }
     else { cout << endl; }
     // check each cell's upper right and lower left vertice
     float r_sq = (n - 0.5) * (n - 0.5);
     int in = 0; int on = 0;
     for (int x = 0; x < n; x++) {
       for (int y = 0; y < n; y++) {
         if (in_circle(x, y, r_sq)) {
           if (in_circle(x+1, y+1, r_sq)) {
             in++;
           } else {
             on++;
           }
         }
       }
     }
     // cout << n << ' ' << in << ' ' << on << endl;
     cout << "In the case n = " << n << ", " << on*4 <<  " cells contain segments of the circle.\n";
     cout << "There are " << in*4 << " cells completely contained in the circle." << endl;
   }
   return 0;
 }
