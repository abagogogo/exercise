#include <iostream>
#include <vector>

using namespace std;

template <class T>
class MyStack {
 public:
  void push(const T &new_one) { elems.push_back(new_one); }
  void pop(void) {
    if (elems.empty()) {
      cout << "pop an empty stack!" << endl;
      return;
    }
    elems.pop_back();
  }
  T top(void) {
    if (elems.empty()) {
      cout << "peeking at empty stack!" << endl;
    }
    return elems.back();
  }

 private:
  vector<T> elems;
};

int main(void) {
  MyStack<int> int_stack;
  MyStack<string> string_stack;

  int_stack.push(7);
  int_stack.push(6);
  int_stack.push(5);
  cout << int_stack.top() << endl;
  int_stack.pop();
  cout << int_stack.top() << endl;
  int_stack.pop();
  cout << int_stack.top() << endl;
  int_stack.pop();

  string_stack.push("hello");
  cout << string_stack.top() << endl;
  string_stack.pop();
  string_stack.pop();
  cout << "string_stack.top(): " << string_stack.top() << endl;
  return 0;
}
