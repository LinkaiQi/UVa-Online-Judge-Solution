#include <iostream>
#include <vector>

using namespace std;

int find_insert_pos(vector<int> v, int num) {
  int l = v.size();
  if (l == 0) { return 0; }
  int min = 0;
  int max = l - 1;

  while (min < max) {
    int mid = (min + max) / 2;
    if (v[mid] < num) {
      min = mid + 1;
    } else if (v[mid] > num) {
      max = mid - 1;
    } else {
      return mid + 1;
    }
  }

  if (v[min] > num) {
    return min;
  } else {
    return min + 1;
  }

  return 0;
}


int main() {
  int num;
  vector<int> v;
  while (cin >> num) {
    // using binary search to find the position to insert the new number
    // keep the vector sorted
    int pos = find_insert_pos(v, num);
    if (pos < 0) { v.push_back(num); }
    else { v.insert(v.begin()+pos, num); }

    // print to stdout
    // for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
    //   cout << *i << ' ';
    // cout << endl;
    int len_v = v.size();
    if (len_v % 2 == 0) {
      cout << (v[(len_v/2)-1] + v[len_v/2])/2  << endl;
    } else {
      cout << v[len_v/2]  << endl;
    }
  }
  return 0;
}
