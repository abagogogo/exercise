#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverse_string(string &str) {
  size_t head = 0;
  size_t tail = str.length();
  while (head < tail) {
    swap(str[head], str[tail - 1]);
    head++;
    tail--;
  }
}

int main() {
  vector<string> strings{"abcde", "aecce", "aecae"};

  for (auto& str : strings) {
    auto ans = str;
    std::reverse(ans.begin(), ans.end());

    cout << "original: " << str << endl;
    reverse_string(str);
    if (str == ans) {
       cout << "[PASS] reversed: " << str << endl;
    } else {
       cout << "[FAIL] reversed: " << str << ", ans: " << ans << endl;
    }
  }
  return 0;
}
