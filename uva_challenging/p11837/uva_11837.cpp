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
 *   have found a match
 *
 * Used Resources:
 *
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

using namespace std;


bool check_plag(int *song, int *snippet, int i, int T) {
  // cout << "call check_plag " << i << endl;
  int diff, pre_diff = -1;
  for (int j = 0; j < T; j++) {
    if (snippet[j] >= song[j+i]) {
      diff = snippet[j] - song[j+i];
    } else {
      diff = 10 - song[j+i] + snippet[j] + 2;
    }
    // cout << "diff: " << diff << ' ' << j << ' ' << j+i << endl;
    if (pre_diff >= 0 && diff != pre_diff) {
      return false;
    }
    pre_diff = diff;
  }
  return true;
}

int main() {
  int song[1000000];
  int snippet[100000];

  std::map<char,int> semitone;
  semitone['A'] = 0;
  semitone['B'] = 2;
  semitone['C'] = 3;
  semitone['D'] = 5;
  semitone['E'] = 7;
  semitone['F'] = 8;
  semitone['G'] = 10;

  int M, T;
  cin >> M >> T;
  while (M and T) {
    string notes;
    // read notes of the song
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
      song[i] = n;
    }
    // read node of supspect snippet
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
      snippet[i] = n;
    }

    // search plagiarization
    bool is_plag = false;
    for (int i = 0; i <= M-T; i++) {
      if (check_plag(song, snippet, i, T)) {
        is_plag = true;
        break;
      }
    }
    // print to stdout
    if (is_plag) {
      cout << "S\n";
    } else {
      cout << "N\n";
    }

    // read next test case
    cin >> M >> T;
  }

  return 0;
}
