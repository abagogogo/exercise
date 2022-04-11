#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(void) {
    ifstream input("fileread.cc", ios::in | ios::binary);

    stringstream sstr;

    while (input >> sstr.rdbuf());
    cout << sstr.str() << endl;

    int sum = 0;
    char tmp_byte;
    input.clear();
    input.seekg(0);
    while (input.read(&tmp_byte, 1)) {
        //cout << tmp_byte;
        sum += tmp_byte;
    }
    cout << "----- file sum = " << sum << endl;

    return 0;
}
