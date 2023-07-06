#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n < 2) return n;

    int fn;
    int fn_2 = 0;
    int fn_1 = 1;
    for (int i = 2; i <= n; ++i) {
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }
    return fn;
} 

int main() {
    int n;
    int fn;

    cout << "input n: ";
    cin >> n;

    fn = fibonacci(n);
    cout << "f(" << n << ") = " << fn << endl;
    return 0;
}
