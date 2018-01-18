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
