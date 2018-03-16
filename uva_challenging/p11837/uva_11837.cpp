/* UVa problem: 11837
 *
 * Topic: Strings
 *
 * Level: challenging
 *
 * Brief problem description:
 *   Given a text(original song) and a pattern(snippet), find if the pattern
 *   occurs in the text, by shifting its alphabet(musical notes)
 *
 * Solution Summary:
 *   We only to consider the distance between the alphabets in the text and
 *   the alphabets in the pattern. If the distances are all the same, the we
 *   have found a match. We can speed up this program by using KMP substring
 *   matching algorithm, which has been implemented in uva_10679.
 *
 * Used Resources:
 *   KMP algorithm reference:
 *    https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
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

using namespace std;


void calc_prefix(int *P, int p_len, int *prefix) {
  prefix[0] = 0;
  int j = 0;
  for (int i = 1; i < p_len; i++) {
    while (j>=0 && P[j]!=P[i]) {
      if (j >= 1) {
        j = prefix[j-1];
      } else {
        j--;
      }
    }
    j++;
    prefix[i] = j;
  }
}

// KMP algorithm reference:
//  https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
bool search_pattern(int *S, int n_S, int *P, int n_P, int *prefix) {
  int i = 0;
  int j  = 0;
  while (i < n_S) {
    if (P[j] == S[i]) {
      j++;
      i++;
    }

    if (j == n_P) {
      return true;
    }

    else if (i < n_S && P[j] != S[i]) {
      if (j != 0)
        j = prefix[j-1];
      else
        i = i+1;
    }
  }
  return false;
}


int main() {
  int song[1000000];
  int snippet[100000];
  int prefix[100000];

  std::map<char,int> semitone;
  semitone['A'] = 1;
  semitone['B'] = 3;
  semitone['C'] = 4;
  semitone['D'] = 6;
  semitone['E'] = 8;
  semitone['F'] = 9;
  semitone['G'] = 11;

  int M, T, prev;
  cin >> M >> T;
  while (M and T) {
    string notes;
    // read notes of the song
    prev = 0;
    for (int i = 0; i < M; i++) {
      cin >> notes;
      int n = semitone[notes[0]];
      if (notes.length() == 2) {
        if (notes[1] == '#') {
          n++;
        } else {
          n--;
        }
      }
      if (i) {
        song[i-1] = (n + 12 - prev) % 12;
      }
      prev = n;
    }
    // read node of supspect snippet
    prev = 0;
    for (int i = 0; i < T; i++) {
      cin >> notes;
      int n = semitone[notes[0]];
      if (notes.length() == 2) {
        if (notes[1] == '#') {
          n++;
        } else {
          n--;
        }
      }
      if (i) {
        snippet[i-1] = (n + 12 - prev) % 12;
      }
      prev = n;
    }

    calc_prefix(snippet, T-1, prefix);

    // print to stdout
    if (T == 1 || search_pattern(song, M-1, snippet, T-1, prefix)) {
      cout << "S\n";
    } else {
      cout << "N\n";
    }

    // read next test case
    cin >> M >> T;
  }

  return 0;
}
