#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

int main() {
  // std::array is a safer and modern container in c++ than c array.
  array<int, 3> a = {1, 2, 3};

  do {
    cout << a[0] << "," << a[1] << "," << a[2] << endl;
  } while (next_permutation(a.begin(), a.end()));
  return 0;
}
