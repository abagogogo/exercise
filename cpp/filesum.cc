#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main() {
  string filename;
  int sum = 0;
  int num;

  cout << "Please enter the file path containing lines of int numbers: " << endl;
  getline(cin, filename);
  if (filename.empty()) {
    cout << "Using default filename" << endl;
    filename = "int_data.txt";
  }

  cout << "filename: " << filename << endl;
  filesystem::path filepath(filename);
  if (!filesystem::exists(filepath)) {
    cout << "File does not exists!" << endl;
    return 1;
  }

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
  cout << "sum = 0x" << hex << sum << endl;
  return 0;
}
