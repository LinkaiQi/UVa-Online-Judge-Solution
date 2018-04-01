/* UVa problem: 10806
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
int G[128][128];

void initialize_graph() {
  for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 128; j++) {
      G[i][j] = 0;
    }
  }
}

int min_distance(int *dist, bool *spt_set) {
  int min = INT_MAX;
  int min_index = -1;
  for (int i = 1; i < N+1; i++) {
    if (!spt_set[i] && dist[i] != INT_MAX && dist[i] < min) {
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

int dijkstra(bool first_visted) {
  int s = 1;  // source node
  int t = N;  // end node
  // cout << "S T: " << s << ' ' << t << endl;

  int path[N+1];      // shortest path recorder
  int dist[N+1];      // distance from source to i
  bool spt_set[N+1];  // true if shortest distance from source to i is finalized

  // initialize all distances as INFINITE and 'spt_set' as false
  for (int i = 1; i < N+1; i++) {
    path[i] = -1; dist[i] = INT_MAX, spt_set[i] = false;
  }

  // distance of source vertex from itself is always 0
  dist[s] = 0;

  // Find shortest path for all vertices
  int u = s;
  while (u != -1) {
    // cout << "u: " << u << endl;
    // mark the picked vertex as processed
    spt_set[u] = true;
    // update dist value of the adjacent vertices of the picked vertex.
    for (int v = 1; v < N+1; v++) {
      // cout << "v: " << v << ' ' << G[u][v] << endl;
      if (!spt_set[v] && G[u][v] != 0 && dist[u] + G[u][v] < dist[v]) {
        dist[v] = dist[u] + G[u][v];
        path[v] = u;
      }
    }
    u = min_distance(dist, spt_set);
  }

  // if first visted, remove visited edge
  // since, we can not follow any of the same streets that we friend follows
  if (first_visted && path[t] != -1) {
    int current = t, next;
    while (current != s) {
      next = path[current];
      G[current][next] = 0;
      G[next][current] = 0;
      current = next;
    }
  }

  return dist[t];
}

int main() {
  int n1, n2, w, cost1, cost2;

  while (cin >> N, N) {
    // initialize graph
    initialize_graph();
    // read graph
    cin >> M;
    for (int i = 0; i < M; i++) {
      cin >> n1 >> n2 >> w;
      G[n1][n2] = w; G[n2][n1] = w;
    }

    // first dijkstra visit
    cost1 = dijkstra(true);
    if (cost1 == INT_MAX) {
      cout << "Back to jail" << endl;
      continue;
    }
    // second dijkstra visit
    cost2 = dijkstra(false);
    if (cost2 == INT_MAX) {
      cout << "Back to jail" << endl;
      continue;
    }

    cout << cost1 + cost2 << endl;

  }

  return 0;
}
