#include <iostream>
using namespace std;

class Box {
 public:
  Box(double l, double b, double h) : length(l), breadth(b), height(h) {}
  Box() = default;
  double getVolume(void) const { return length * breadth * height; }
  void setLength(double l) { length = l; }
  void setBreadth(double b) { breadth = b; }
  void setHeight(double h) { height = h; }

  // Overload + operator to add two Box objects.
  Box operator+(const Box& b) {
    Box new_box{
        this->length + b.length,
        this->breadth + b.breadth,
        this->height + b.height};
    return new_box;
  }

 protected:
  double length;
  double breadth;
  double height;
};

int main() {
  Box box1{6.0, 7.0, 5.0};
  Box box2{12.0, 13.0, 10.0};
  Box box3; // Initialized with default values.

  cout << "Volume of box1 : " << box1.getVolume() << endl;
  cout << "Volume of box2 : " << box2.getVolume() << endl;

  box3 = box1 + box2;
  cout << "Volume of box3 : " << box3.getVolume() << endl;

  return 0;
}
