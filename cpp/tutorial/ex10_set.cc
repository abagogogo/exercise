#include <iostream>
#include <set>
#include <vector>
#include <array>
#include <numeric> // for std::accumulate

using namespace std;

int main() {
  set<int> s;

  for (int i = 0; i < 100; i++) {
    s.insert(i);  // insert 100 elements, [0...99].
  }

  if (auto [it, inserted] = s.insert(42); !inserted) {
    cout << "42 already exists, size = " << s.size() << endl;
  }

  if (auto search = s.find(42);  search != s.end()) {
    cout << "Found " << (*search) << endl;
  } else {
    cout << "Not found" << endl;
  }

  for (int i = 0; i < 100; i += 2) {
    s.erase(i);  // erase even values
  }
  cout << "erase() even values => size = " << s.size() << endl;

  if (auto search = s.find(42); search != s.end()) {
    cout << "Found " << (*search) << endl;
  } else {
    cout << "Not found" << endl;
  }

  // calculate sum of elements in set
  /*
  int sum = 0;
  for (auto it = s.begin(); it != s.end(); it++) {
    sum += *it;
  }
  */
  int sum = accumulate(s.begin(), s.end(), 0);
  cout << "Sum in the set = " << sum << endl;

  /*
  int data[5] = {5, 1, 4, 2, 3};
  set<int> s_init(data, data + 5);
  */
  set<int> s_init = {5, 1, 4, 2, 4}; // Using list initialization instead.
  cout << "s_init: " << endl;
  for (const auto& element : s_init) {
    cout << element << " ";
  }
  cout << endl;

  vector<int> sorted_v(s_init.begin(), s_init.end());
  cout << "sorted_v: " << endl;
  for (const auto& element : sorted_v) {
    cout << element << " ";
  }
  cout << endl;

  /*
  double data_d[] = {5.1, 1.0, 4.0f, 2.0, 3.0};
  set<double> s_d(data_d, data_d + 5);
  */
  array<double, 5> data_d = {5.1, 1.0, 4.0f, 2.0, 3.0}; // Replacing raw array with std::array.
  set<double> s_d(data_d.begin(), data_d.end());
  cout << "s_d: " << endl;
  for (const auto& element : s_d) {
    cout << element << " ";
  }
  cout << endl;

  return 0;
}
