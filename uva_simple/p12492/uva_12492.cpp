/* UVa problem: 12492
 *
 * Topic: Combinatorics
 *
 * Level: easy
 *
 * Brief problem description:
 *   "An interesting property of the Rubik’s Cube is that any sequence of
 *   movements, if applied repeatedly, causes the cube to return to its
 *   original state".
 *   Given a sequence of movements, determines the minimum number of complete
 *   applications of that sequence to make the cube return to its original
 *   state.
 *
 * Solution Summary:
 *   Assign each cell of the cube a number with inital value that correspond to
 *   the cube original state.
 *   Then apply the sequence of the move repeately and check if the cube back
 *   to its orignal state.
 *   F: 0 1 2
 *      3 * 4
 *      5 6 7
 *
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


using namespace std;

/*
0 1 2
3 * 4
5 6 7
*/

void clockwise_rotate(int* pos,int front, int *side) {
  // rotate front panel
  int temp0 = pos[front];
  int temp1 = pos[front+1];
  int temp2 = pos[front+2];

  pos[front+2] = pos[front];
  pos[front+1] = pos[front+3];
  pos[front+0] = pos[front+5];

  pos[front] = pos[front+5];
  pos[front+3] = pos[front+6];
  pos[front+5] = pos[front+7];

  pos[front+5] = pos[front+7];
  pos[front+6] = pos[front+4];
  pos[front+7] = pos[front+2];

  pos[front+7] = temp2;
  pos[front+4] = temp1;
  pos[front+2] = temp0;

  // rotate side panels
  temp0 = pos[side[0]]; temp1 = pos[side[1]]; temp2 = pos[side[2]];

  pos[side[0]] = pos[side[9]];
  pos[side[1]] = pos[side[10]];
  pos[side[2]] = pos[side[11]];

  pos[side[9]] = pos[side[6]];
  pos[side[10]] = pos[side[7]];
  pos[side[11]] = pos[side[8]];

  pos[side[6]] = pos[side[3]];
  pos[side[7]] = pos[side[4]];
  pos[side[8]] = pos[side[5]];

  pos[side[3]] = temp0;
  pos[side[4]] = temp1;
  pos[side[5]] = temp2;
}

void F(int* pos) {
  int side[12] = {13, 14, 15, 16, 19, 21, 42, 41, 40, 31, 28, 26};
  clockwise_rotate(pos, 0, side);
}

void f(int* pos) {
  int side[12] = {13, 14, 15, 16, 19, 21, 42, 41, 40, 31, 28, 26};
  clockwise_rotate(pos, 0, side);
  clockwise_rotate(pos, 0, side);
  clockwise_rotate(pos, 0, side);
}

void L(int* pos) {
  // cout << 'L' << endl;
  int side[12] = {8, 11, 13, 0, 3, 5, 40, 43, 45, 39 ,36, 34};
  clockwise_rotate(pos, 24, side);
}

void l(int* pos) {
  int side[12] = {8, 11, 13, 0, 3, 5, 40, 43, 45, 39 ,36, 34};
  clockwise_rotate(pos, 24, side);
  clockwise_rotate(pos, 24, side);
  clockwise_rotate(pos, 24, side);
}

void R(int* pos) {
  // cout << 'R' << endl;
  int side[12] = {15, 12, 10, 32, 35, 37, 47, 44, 42, 7, 4, 2};
  clockwise_rotate(pos, 16, side);
}

void r(int* pos) {
  // cout << 'r' << endl;
  int side[12] = {15, 12, 10, 32, 35, 37, 47, 44, 42, 7, 4, 2};
  clockwise_rotate(pos, 16, side);
  clockwise_rotate(pos, 16, side);
  clockwise_rotate(pos, 16, side);
}

void U(int* pos) {
  int side[12] = {34, 33, 32, 18, 17 ,16 , 2, 1, 0, 26, 25, 24};
  clockwise_rotate(pos, 8, side);
}

void u(int* pos) {
  int side[12] = {34, 33, 32, 18, 17 ,16 , 2, 1, 0, 26, 25, 24};
  clockwise_rotate(pos, 8, side);
  clockwise_rotate(pos, 8, side);
  clockwise_rotate(pos, 8, side);
}

void B(int* pos) {
  int side[12] = {10, 9, 8, 24, 27, 29, 45, 46, 47, 23, 20, 18};
  clockwise_rotate(pos, 32, side);
}

void b(int* pos) {
  int side[12] = {10, 9, 8, 24, 27, 29, 45, 46, 47, 23, 20, 18};
  clockwise_rotate(pos, 32, side);
  clockwise_rotate(pos, 32, side);
  clockwise_rotate(pos, 32, side);
}

void D(int* pos) {
  int side[12] = {5, 6, 7, 21, 22, 23, 37, 38, 39, 29, 30, 31};
  clockwise_rotate(pos, 40, side);
}

void d(int* pos) {
  int side[12] = {5, 6, 7, 21, 22, 23, 37, 38, 39, 29, 30, 31};
  clockwise_rotate(pos, 40, side);
  clockwise_rotate(pos, 40, side);
  clockwise_rotate(pos, 40, side);
}


bool check(int *pos) {
  for (int i = 0; i < 48; i++) {
    if (pos[i] != i) {
      return false;
    }
  }
  return true;
}

int main() {
  string str;
  int pos[48];
  while (cin >> str) {
    // cout << "! " << str << endl;
    // initalize position
    int repeat = 0;
    for (int i = 0; i < 48; i++)
      pos[i] = i;
    // repeat the sequence until we reach the inital position again
    while (true) {
      for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
          case 'F': F(pos); break;
          case 'f': f(pos); break;
          case 'D': D(pos); break;
          case 'd': d(pos); break;
          case 'L': L(pos); break;
          case 'l': l(pos); break;
          case 'R': R(pos); break;
          case 'r': r(pos); break;
          case 'B': B(pos); break;
          case 'b': b(pos); break;
          case 'U': U(pos); break;
          case 'u': u(pos); break;
        }

        // debug ---
        // for (int i = 0; i < 48; i++) {
        //   cout << pos[i] << ' ';
        // }
        // cout << endl;
        // end ---

      }

      repeat++;
      if (check(pos)) {
        cout << repeat << endl;
        break;
      }
    }
  }
  return 0;
}
