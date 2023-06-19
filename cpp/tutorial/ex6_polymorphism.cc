#include <iostream>
using namespace std;

class Shape {
 protected:
  int width, height;

 public:
  Shape(int a = 0, int b = 0) {
    cout << "Shape constructor" << endl;
    width = a;
    height = b;
  }
  virtual ~Shape() { cout << "Shape destructor" << endl; }
  virtual int area() const {
    cout << "Parent class area :" << endl;
    return 0;
  }
};

class Triangle : public Shape {
 public:
  Triangle(int a = 0, int b = 0) : Shape(a, b) {
    cout << "Triangle constructor" << endl;
  }
  virtual ~Triangle() override { cout << "Triangle destructor" << endl; }
  virtual int area() const override {
    cout << "Triangle class area :" << endl;
    return (width * height / 2);
  }
};

class Rectangle : public Shape {
 public:
  Rectangle(int a = 0, int b = 0) : Shape(a, b) {
    cout << "Rectangle constructor" << endl;
  }
  virtual ~Rectangle() override { cout << "Rectangle destructor" << endl; }
  virtual int area() const override {
    cout << "Rectangle class area :" << endl;
    return (width * height);
  }
};

int main() {
  Shape *shape;

  Rectangle rect(10, 7);
  Triangle tri(10, 5);

  shape = &rect;
  shape->area();

  shape = &tri;
  shape->area();

  shape = new Rectangle(3, 5);
  shape->area();
  delete shape;
  return 0;
}
