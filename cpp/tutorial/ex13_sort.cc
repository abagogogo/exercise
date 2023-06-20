#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  array<int, 3> a = {2, 1, 3};
  vector<int> v(a.begin(), a.end());

  cout << "original: " << endl;
  for (const auto& element : a) {
    cout << element << ",";
  }
  cout << endl;

  sort(v.begin(), v.end());
  cout << "sorted: " << endl;
  for (const auto& element : v) {
    cout << element << ",";
  }
  cout << endl;
  return 0;
}
