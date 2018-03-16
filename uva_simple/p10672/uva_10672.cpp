/* UVa problem: 10672
 *
 * Topic: Sorting
 *
 * Level: easy
 *
 * Brief problem description:
 *   "We are given a rooted tree with n vertices. For each vertex v, we are
 *   given m marbles which rest on v. In total, there are n marbles. Our goal
 *   is to equally distribute the n marbles, such that we minimize the number
 *   of marble movements needed to reach equilibrium." -- Algorithmist
 *
 * Solution Summary:
 *   While the tree has more than one node, we take a leaf, move all but one of
 *   its marbles to its parent, and remove the leaf. Let the number of marbles
 *   rest on the leaf is m, the number of marbles need to move up to its parent
 *   equals to m-1 (can be negative, which means move in opposite direction).
 *   Add |m-1| to the number of movement (accumulator).
 *   Repeat the process until we only have root node(vertix) in the tree.
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
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>        // std::abs

using namespace std;

int N, Moves;
int Parent[10001];
int Marbles[10001];
map <int, vector<int> > Children;


void dfs(int v) {
  vector<int> children = Children[v];
  for (int i = 0; i < children.size(); i++) {
    dfs(children[i]);
  }

  int p = Parent[v];
  if (p) {
    Marbles[p] += Marbles[v] - 1;
    Moves += abs(Marbles[v] - 1);
  }
}

int main() {
  int v, m, d, c;

  while (cin >> N, N) {
    // clear tree
    Children.clear();
    Moves = 0;
    for (int i = 1; i < N+1; i++) {
      Parent[i] = 0;
    }

    // read input
    for (int i = 0; i < N; i++) {
      cin >> v >> m >> d;
      Marbles[v] = m;
      for (int j = 0; j < d; j++) {
        cin >> c;
        Parent[c] = v;
        Children[v].push_back(c);
      }
    }

    // find the root (no parent)
    for (int i = 1; i < N+1; i++) {
      if (!Parent[i]) {
        // run dfs traversal
        // cout << i << endl;
        dfs(i);
        break;
      }
    }

    // print result to stdout
    cout << Moves << endl;

  }

  return 0;
}
