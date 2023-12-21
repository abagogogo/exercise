#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template <class T>
class Stack {
 protected:
  vector<T> elems;

 public:
  void push(const T& elem) { elems.push_back(elem); }

  void pop() {
    if (elems.empty()) {
      throw out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();
  }

  const T top() const {
    if (elems.empty()) {
      throw out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();
  }

  bool empty() const { return elems.empty(); }
};

int main() {
  try {
    Stack<int> intStack;
    Stack<string> stringStack;

    intStack.push(7);
    cout << intStack.top() << endl;

    stringStack.push("hello");
    cout << stringStack.top() << endl;
    stringStack.pop();
    stringStack.top();
  } catch (const exception& ex) {
    cerr << "Exception: " << ex.what() << endl;
    return -1;
  }
  return 0;
}
