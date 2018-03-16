#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int Max_height[180];


struct Block {
  int b1, b2;
  int height;

  bool operator<(Block B) const {
    if((b1<B.b1 && b2<B.b2)) {
      return true;
    }
    return false;
  }
} B[90];


bool cmp(const Block& a, const Block& b) {
  if (a.b1 == b.b1) {
    return a.b2 < b.b2;
  }
  return a.b1 < b.b1;
}


void add_block(struct Block *block, int b1, int b2, int h) {
  block->b1 = b1;
  block->b2 = b2;
  block->height = h;
}

int LIS(int n) {
  // Initialize LIS values
  // fill(Max_height, Max_height+3*n, 1);
  for (int i = 0; i < 6*n; i++) {
    Max_height[i] = B[i].height;
  }

  // Compute LIS values
  for (int i = 1; i < 6*n; i++) {
    for (int j = 0; j < i; j++) {
      if (B[j] < B[i] && Max_height[i] < Max_height[j] + B[i].height) {
        Max_height[i] = Max_height[j] + B[i].height;
      }
    }
  }

  // find the maximum LIS value
  int max = 0;
  for (int i = 0; i < 6*n; i++) {
    // cout << Max_height[i] << ' ';
    if (Max_height[i] > max) {
      max = Max_height[i];
    }
  }
  // cout << endl;

  return max;
}


int main() {
  int n, x, y, z;
  int k = 0;
  while (cin >> n, n) {
    k++;

    for (int i = 0; i < n; i++) {
      cin >> x >> y >> z;
      add_block(&B[i*6], x, y, z);
      add_block(&B[i*6+1], x, z, y);
      add_block(&B[i*6+2], y, x, z);
      add_block(&B[i*6+3], y, z, x);
      add_block(&B[i*6+4], z, x, y);
      add_block(&B[i*6+5], z, y, x);
    }

    sort(B, B+6*n, cmp);

    // for (int i = 0; i < 6*n; i++) {
    //   cout << B[i].b1 << ' ' << B[i].b2 << ' ' << B[i].height << endl;
    // }

    cout << "Case " << k << ": maximum height = " << LIS(n) << endl;

  }
  return 0;
}
