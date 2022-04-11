#include <iostream>

using namespace std;

#define swap_char(_a, _b) \
    do { \
        char tmp = _a; \
        (_a) = (_b); \
        (_b) = tmp; \
    } while (0)

void reverse_string(string &str) {
    size_t head = 0; 
    size_t tail = str.length() -1;
    while (head < tail) {
        swap_char(str[head], str[tail]);
        head++; 
        tail--;
    }
}


        // II: abcde
        // NG: aecce
        // ??: aecae
        //
int main(void) {
    string str = "abcde";

    cout << "original: " << str << endl;
    reverse_string(str);
    cout << "reversed: " << str << endl;
    return 0;
}

