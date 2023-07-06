#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(void) {
#if 0
    ifstream input("int_data.txt", ios::in | ios::binary);

    int sum = 0;
    char tmp;
    while (input.read(&tmp, sizeof(tmp))) {
        cout << tmp;
        sum += tmp;
    } 
    cout << "----- file sum = " << sum << endl;
    return 0;
#endif

  string filename;
  int sum = 0;
  int num;

  cout << "Please enter the interger file to parse: " << endl;
  getline(cin, filename);
  if (filename.empty()) {
    cout << "use defautl filename" << endl;
    filename = "int_data.txt";
  }

  cout << "filename: " << filename << endl;
  ifstream input(filename.c_str(), ios::in | ios::binary);

#if 0  // ifstream getline()
    for (string line; getline(input, line);) {
        num = std::stoi(line); // C++11
        //sscanf(line.c_str(), "%d", &num); // C sytle
        cout << line << " => " << num << endl;
        sum += num;
    }
#else
  while (input >> num) sum += num;
#endif
  cout << "sum = " << sum << endl;
  return 0;
}
