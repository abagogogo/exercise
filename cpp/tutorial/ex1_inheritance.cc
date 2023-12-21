#include <iostream>

using namespace std;

class Shape {
 public:
  Shape(int w, int h) : width(w), height(h) {}

  void setWidth(int w) { width = w; }
  void setHeight(int h) { height = h; }

 protected:
  int width;
  int height;
};

class PaintCost {
 public:
  int getCost(int area) { return area * 70; }
};

class Rectangle : public Shape, public PaintCost {
 public:
  Rectangle(int w, int h) : Shape(w, h) {}

  int getArea(void) { return width * height; }
};

int main() {
  Rectangle rect{5, 7};
  int area = rect.getArea();
  cout << "Total area: " << rect.getArea() << endl;
  cout << "Total paint coast: $" << rect.getCost(area) << endl;

  return 0;
}
