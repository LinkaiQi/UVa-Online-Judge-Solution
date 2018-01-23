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
