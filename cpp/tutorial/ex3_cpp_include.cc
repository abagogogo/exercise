#include <iostream>
#include <vector>

using namespace std;

/*
#define SWAP(_a, _b) \
            (_a) ^= (_b); \
            (_b) ^= (_a); \
            (_a) ^= (_b)
*/
template <typename T>
void SWAP(T& a, T& b) {
  T temp = std::move(a);
  a = std::move(b);
  b = std::move(temp);
}

/*
#define MIN(_a, _b) \
            ((_a) <= (_b) ? (_a) : (_b))
*/
template <typename T>
T MIN(const T& a, const T& b) {
  return (a <= b) ? a : b;
}

/*
#define MAX(_a, _b) \
            ((_a) >= (_b) ? (_a) : (_b))
*/
template <typename T>
T MAX(const T& a, const T& b) {
  return (a >= b) ? a : b;
}

int bit_count(unsigned int val) {
  int count = 0;

  for (; val != 0; ++count) {
    val &= (val - 1);
  }

  return count;
}

int main() {
  int a = 0x11;
  int b = 0xc9;
  int a1 = a;
  int b1 = b;

  cout << "a=" << a << ", b=" << b << endl;
  a1 = a;
  b1 = b;
  SWAP(a1, b1);
  cout << "SWAP() => a=" << a1 << ", b=" << b1 << endl;

  cout << "MIN() => " << MIN(a, b) << endl;
  cout << "MIN() => " << MAX(a, b) << endl;
  cout << "bit_count(a) => " << bit_count(a) << endl;
  cout << "bit_count(b) => " << bit_count(b) << endl;
  return 0;
}
