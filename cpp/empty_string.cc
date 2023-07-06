#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1;
  string s2 = "";

  cout << "s1.empty() = " << s1.empty() << endl;
  cout << "s1.length() = " << s1.length() << endl;
  cout << "s1.size() = " << s1.size() << endl;

#if 0
    cout << "s2.empty() = " << s2.empty() << endl;
    cout << "s2.length() = " << s2.length() << endl;
    /* stack overflow for string::length() returns size_t which is unsigned int */
    for (size_t i = 0; i < s2.length() - 1; ++i) {
        cout << i << ":" << s2[i] << endl;
        if (i > 2) break;
    }
#endif

  return 0;
}
