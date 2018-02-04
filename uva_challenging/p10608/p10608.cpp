/* UVa problem: 10608
 *
 * Topic: Data structures
 *
 * Level: challenging
 *
 * Brief problem description:
 *
 *   Following the rule: "If A and B are friends and B and C are friends,
 *   then A and C are friends too". Get list of friend list, count how
 *   many people there are in the largest group of friends.
 *
 * Solution Summary:
 *
 *   Solved by the Union Find algorithm. Each people has a pointer points
 *   to its "parent". If two peoples point to the same parent, then they
 *   are in the same set.
 *
 * Used Resources:
 *
 *   Reference: https://en.wikipedia.org/wiki/Disjoint-set_data_structure
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- Linkai Qi
 */

#include <iostream>
using namespace std;

int parent[30001];
int size[30001];

int get_head(int p) {
  while (parent[p]!=0) {
    p = parent[p];
  }
  return p;
}

int union_set(int a, int b) {
  int h1 = get_head(a);
  int h2 = get_head(b);
  if (h1 != h2) {
    // merge two different set
    parent[h2] = h1;
    size[h1] = size[h1] + size[h2];
  }
  return 0;
}

int main() {
  // read the number of datasets
  int data_set, N, M;
  cin >> data_set;
  for (int i = 0; i < data_set; i++) {
    cin >> N >> M;
    // initialize
    for (int n = 1; n <= N; n++) {
      parent[n] = 0;
      size[n] = 1;
    }
    // read friend relations
    for (int m = 0; m < M; m++) {
      int a, b;
      cin >> a >> b;
      union_set(a, b);
    }
    // get largest set size
    int max_size = 0;
    for (int n = 1; n <= N; n++) {
      if (size[n] > max_size) {
        max_size = size[n];
      }
    }
    cout << max_size << endl;
  }

  return 0;
}
