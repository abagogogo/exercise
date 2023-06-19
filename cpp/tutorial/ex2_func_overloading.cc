#include <iostream>
using namespace std;

class printData {
 public:
  void print(int i) const { cout << "Printing int: " << i << endl; }
  void print(double d) const { cout << "Printing double: " << d << endl; }
  void print(const char *c) const {
    cout << "Printing character: " << c << endl;
  }
};

int main() {
  printData pd;

  pd.print(5);
  pd.print(500.263);
  pd.print("Hello C++");

  return 0;
}
