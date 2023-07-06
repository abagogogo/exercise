#include <algorithm>
#include <iostream>

using namespace std;

int mul(int m, int n) {
  int sum = 0;
  if (m < n) swap(m, n);

  while (n) {
    if ((n & 0x1)) {
      sum += m;
    }
    n >>= 1;
    m <<= 1;
  }
  return sum;
}

int power(int a, int r) {
  int sum = 1;
  int pow = a;
  while (r) {
    if ((r & 0x1)) {
      sum *= pow;
    }
    pow *= pow;
    r >>= 1;
  }
  return sum;
}

int main() {
  int m = 88;
  int n = 99;
  cout << m << " * " << n << " = " << mul(m, n) << endl;

  int a = 2;
  int r = 9;
  cout << "power(" << a << ", " << r << ") = " << power(a, r) << endl;
  return 0;
}
