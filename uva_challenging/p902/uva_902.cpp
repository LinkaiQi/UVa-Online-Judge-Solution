/* UVa problem: 902
 *
 * Topic: Other (String / Data Structures)
 *
 * Level: challenging
 *
 * Brief problem description:
 *   Given a string, find the most frequent substring with N characters
 *
 * Solution Summary:
 *   Enumerate all substrings with length N. Use these substrings to build
 *   a trie tree. Every leaf nodes in the trie tree represent a unique substring.
 *   Each time we insert a substring, we increment the counter(n) in the leaf node
 *   which represent the frequency of the substring.
 *   To get the most frequenct substring, we only need to do a tree traversal,
 *   find the largest counter(n) in the leaf node with its key(substring).
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

#define ALPHABET_LEN 26

using namespace std;


string Res;
int Max_frequency, N;


struct Node {
  struct Node *children[ALPHABET_LEN];
  int n;
};


void insert(struct Node *root, string key) {
  struct Node *current = root;
  for (int i = 0; i < key.size(); i++) {
    int index = key[i] - 'a';
    if (!current->children[index]) {
      current->children[index] = new struct Node();
    }
    current = current->children[index];
  }
  current->n++;
}


void get_max_substring(int depth, struct Node *node, string *prefix) {
  // base case: reach a leaf node
  if (depth == N) {
    if (node->n > Max_frequency) {
      Max_frequency = node->n;
      Res = *prefix;
    }
    delete node;
    return;
  }

  for (int i = 0; i < ALPHABET_LEN; i++) {
    struct Node *next = node->children[i];
    if (next) {
      char letter = 'a' + i;
      prefix->push_back(letter);
      get_max_substring(depth+1, next, prefix);
      prefix->pop_back();
    }
  }

  delete node;
  return;
}


int main() {
  string msg;
  struct Node *root;

  while (cin >> N >> msg) {
    root = new struct Node();

    for (int i = 0; i < msg.size()-N+1; i++) {
      // cout << msg.substr(i,N) << endl;
      insert(root, msg.substr(i,N));
    }

    string prefix;
    Max_frequency = 0;
    get_max_substring(0, root, &prefix);

    cout << Res << endl;

  }
  return 0;
}
