/* UVa problem: 11721
 *
 * Topic: Graph Algorithms
 *
 * Level: challenging
 *
 * Brief problem description:
 *   -
 *
 * Solution Summary:
 *   -
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
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M;
bool Graph[1000][1000];

struct Wormhole {
  int a, b;
  int cost;
} Wormholes[2000];


void dfs(int v, bool *visited) {
  visited[v] = true;
  for (int i = 0; i < N; i++) {
    if (Graph[v][i] == true && !visited[i]) {
      dfs(i, visited);
    }
  }
}


int get_unvisted_neg_circle_star(vector<int> neg_stars, bool *visited) {
  for (int v = 0; v < neg_stars.size(); v++) {
    if (!visited[neg_stars[v]]) {
      return v;
    }
  }
  return -1;
}


int bellman_ford() {
  int d[N];
  // int p[N];
  vector<int> neg_circle_stars;
  bool change;
  // fill(p, p + N, -1);
  // fill(d, d + N, INT_MAX);
  // d[Wormholes[0].a] = 0;   // start at any star

  for (int i = 0; i < N; i++) {
    change = false;
    for (int j = 0; j < M; j++) {
      struct Wormhole edge = Wormholes[j];
      if (d[edge.a] + edge.cost < d[edge.b]) {
        d[edge.b] = d[edge.a] + edge.cost;
        // p[edge.b] = edge.a;
        change = true;
        if (i == N-1) {
          neg_circle_stars.push_back(edge.b);
        }
      }
    }
    if (!change) { cout << " impossible" << endl; return 0; }
  }

  // search star that can reach the negative cycle
  bool visited[N];
  fill(visited, visited + N, false);
  int neg_v = get_unvisted_neg_circle_star(neg_circle_stars, visited);
  while (neg_v != -1) {
    // cout << neg_v << endl;
    // cout << "! " << visited[neg_v] << endl;
    dfs(neg_circle_stars[neg_v], visited);
    neg_v = get_unvisted_neg_circle_star(neg_circle_stars, visited);
  }
  for (int i = 0; i < N; i++) {
    if (visited[i]) {
      cout << ' ' << i;
    }
  }
  cout << endl;

  return 0;
}


void init_graph() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      Graph[i][j] = false;
    }
  }
}


int main() {
  int K, a, b, c;
  cin >> K;
  for (int k = 0; k < K; k++) {
    cin >> N >> M;
    init_graph();
    for (int m = 0; m < M; m++) {
      cin >> a >> b >> c;
      Wormholes[m].a = a;
      Wormholes[m].b = b;
      Wormholes[m].cost = c;
      Graph[b][a] = true;
    }

    cout << "Case " << k+1 << ':';
    bellman_ford();
  }

  return 0;
}
