#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  ifstream input("fileread.cc", ios::in | ios::binary);

  stringstream sstr;

  while (input >> sstr.rdbuf())
    ;
  cout << sstr.str() << endl;

  int sum = 0;
  char tmp_byte;
  input.clear();
  input.seekg(0);
  while (input.read(&tmp_byte, 1)) {
    // cout << tmp_byte;
    sum += tmp_byte;
  }
  cout << "----- file sum = 0x" << setw(4) << setfill('0') << hex << uppercase << sum << endl;

  return 0;
}
