#include <iostream>
#include <string>
#include <vector>


using namespace std;

long calc_mod(long B, long P, long M) {
  long mod[46340] = {0};

  long current = 1;
  vector<long> v;

  long i;
  for (i = 1; i <= P; i++) {
    current = (current * B) % M;
    // cout << "! " << current << endl;
    if (mod[current]) {
      break;
    }
    v.push_back(current);
    mod[current] = i;
  }

  if (i == P) {
    return current;
  }

  long start = mod[current];
  long end = i;

  long nth = (P - start) % (end - start);
  // cout << "nth: " << nth << endl;

  return v[start -1 + nth];
}

int main() {
  // bool read = true;
  long B, P, M;

  while (cin >> B) {
    // cout << B << ' '<< P << ' ' << M << endl;
    cin >> P >> M;
    cout << calc_mod(B, P, M) << endl;
  }

  return 0;
}
