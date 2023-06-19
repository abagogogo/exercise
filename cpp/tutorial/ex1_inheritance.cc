#include <iostream>

using namespace std;

class Shape {
 public:
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
  int getArea(void) { return width * height; }
};

int main() {
  Rectangle rect;
  int area;

  rect.setWidth(5);
  rect.setHeight(7);
  area = rect.getArea();

  cout << "Total area: " << rect.getArea() << endl;
  cout << "Total paint coast: $" << rect.getCost(area) << endl;

  return 0;
}
