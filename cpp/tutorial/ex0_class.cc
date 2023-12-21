#include <iostream>

using namespace std;

class Box {
 public:
  double length;
  double breadth;
  double height;

  Box(double l, double b, double h) : length(l), breadth(b), height(h) {}

  double volume() const {
      return length * breadth * height;
  }
};

int main() {
  // Use uniform initialization for direct initialization.
  Box box1{5.0, 6.0, 7.0};
  Box box2{10.0, 12.0, 13.0};

  cout << "volume of box1 : " << box1.volume() << endl;
  cout << "volume of box2 : " << box2.volume() << endl;
  return 0;
}
