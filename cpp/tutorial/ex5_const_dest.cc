#include <iostream>

using namespace std;

class Father {
 public:
  Father() { cout << "Father constructor" << endl; }
  virtual ~Father() { cout << "Father destructor" << endl; }
};

class Mother {
 public:
  Mother() { cout << "Mother constructor" << endl; }
  virtual ~Mother() { cout << "Mother destructor" << endl; }
};

class Child : public Father, public Mother {
 public:
  Child() { cout << "Child constructor" << endl; }
  ~Child() override { cout << "Child destructor" << endl; }
};

int main() {
  { Child obj1; }

  cout << "end of main" << endl;
}
