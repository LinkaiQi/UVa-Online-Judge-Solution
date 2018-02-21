/* UVa problem: 10815
 *
 * Topic: Data structures
 *
 * Level: challenging
 *
 * Brief problem description:
 *
 *   After read text file, print all words that occur in that text file
 *   in alphabet order
 *
 * Solution Summary:
 *
 *   Using the The trie starts out with a root node which points to the
 *   start letter nodes of the alphabet. If you add a new word, find the
 *   first letter of the node and keep adding node for that specific letter
 *   as you go down in the trie. Once you reach the end, tag the specific
 *   node you have reached to denote the path to this node is a word.
 *
 *   If we do a inorder traversal on this tree and keep track of the
 *   nodes passed we can get an alphabetically sorted list of words.
 *
 * Used Resources:
 *
 *   Reference: http://www.algorithmist.com/index.php/Trie
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
#include <sstream>

#define ALPHABETS_LEN 26

using namespace std;

struct Node {
  struct Node *nextLetter[ALPHABETS_LEN];
  bool endOfWord;
};

struct Node *createNode() {
  struct Node *newNode = new struct Node;
  newNode->endOfWord = false;
  for (int i = 0; i < ALPHABETS_LEN; i++) {
    newNode->nextLetter[i] = NULL;
  }
  return newNode;
}

void add_word(struct Node *root, string word) {
  struct Node *currentNode = root;
  for (int i = 0; i < word.length(); i++) {
    int index = word[i] - 'a';
    if (!currentNode->nextLetter[index]) {
      currentNode->nextLetter[index] = createNode();
    }
    currentNode = currentNode->nextLetter[index];
  }
  currentNode->endOfWord = true;
}

void get_sorted_dictionary(struct Node *node, string *prefix) {
  if (node->endOfWord) {
    cout << *prefix << endl;
  }
  for (int index = 0; index < ALPHABETS_LEN; index++) {
    struct Node *next = node->nextLetter[index];
    if (next) {
      char letter = 'a' + index;
      prefix->push_back(letter);
      get_sorted_dictionary(next, prefix);
      prefix->pop_back();
    }
  }
}

bool isLetter(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}


int main() {
  // create Trie tree root node
  struct Node *root = createNode();
  // read input
  string text;
  while (cin >> text) {
    // remove punctuations
    for (int i = 0; i < text.length(); i++) {
      if (!isLetter(text[i])) {
        text[i] = ' ';
      }
    }

    std::stringstream ss;
    ss << text;
    string word;
    while (ss >> word) {
      // convert all uppercase letters to lowercase
      for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
          word[i] = word[i] - 'A' + 'a';
        }
      }
      // insert the word to Trie tree
      add_word(root, word);
    }
  }
  // inorder traversal on the trie tree to get an alphabetically sorted list of words.
  string prefix;
  get_sorted_dictionary(root, &prefix);
  return 0;
}
