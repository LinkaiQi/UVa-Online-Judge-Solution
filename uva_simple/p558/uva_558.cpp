/* UVa problem: 558
 *
 * Topic: Graph Algorithms
 *
 * Level: easy
 *
 * Brief problem description:
 *   Given a graph with n nodes(from 1 to n-1), and m edges. Each edge has a weight.
 *   The weight of edge could be negative. Start from node 0, find whether we can
 *   reach a negative cycle from node 0.
 *
 * Solution Summary:
 *   This problem can be solved by using Bellman Ford algorithm. Do N iterations
 *   of Bellman-Ford algorithm. If there were no changes of the distance from
 *   node i to node 0 on the last iteration, there is no cycle of negative weight
 *   in the graph.
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
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M;

struct Wormhole {
  int a, b;
  int cost;
} Wormholes[2000];


int bellman_ford() {
  int d[N];
  bool change;

  fill(d, d+N, INT_MAX);
  // start at node zero, find minimum distance.
  d[0] = 0;

  for (int i = 0; i < N; i++) {
    change = false;
    for (int j = 0; j < M; j++) {
      struct Wormhole edge = Wormholes[j];
      if (d[edge.a] != INT_MAX && d[edge.a] + edge.cost < d[edge.b]) {
        d[edge.b] = d[edge.a] + edge.cost;
        change = true;
      }
    }
    // if (!change) { cout << "not possible" << endl; return 0; }
  }

  if (change) {
    cout << "possible" << endl;
  } else {
    cout << "not possible" << endl;
  }

  return 0;
}


int main() {
  int K, a, b, c;
  cin >> K;
  for (int k = 0; k < K; k++) {
    cin >> N >> M;
    for (int m = 0; m < M; m++) {
      cin >> a >> b >> c;
      Wormholes[m].a = a;
      Wormholes[m].b = b;
      Wormholes[m].cost = c;
    }

    bellman_ford();
  }

  return 0;
}
