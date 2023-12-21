#include <iostream>
#include <string>
using namespace std;

template <typename T>
const T& MyMax(const T& a, const T& b) {
  return (a < b) ? b : a;
}

template <typename T>
const T& MyMin(const T& a, const T& b) {
  return (a < b) ? a : b;
}

int main() {
  int i = 39;
  int j = 20;
  cout << "MyMax(" << i << ", " << j << "): " << MyMax(i, j) << endl;

  double f1 = 13.5;
  double f2 = 20.7;
  cout << "MyMax(" << f1 << ", " << f2 << "): " << MyMax(f1, f2) << endl;
  cout << "MyMin(" << f1 << ", " << f2 << "): " << MyMin(f1, f2) << endl;

  return 0;
}
