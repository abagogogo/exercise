#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define tr(c, it) \
        for (typeof(c.begin())it = c.begin(); it != c.end(); it++)

#define all(c) \
        c.begin(), c.end()

int main(void) 
{
    int data[] = {2, 1, 3};
    vector<int> v(data, data+3);

    cout << "original: " << endl;
    tr(v, it) {
        cout << *it << ",";
    }
    cout << endl;

    sort(all(v));
    cout << "sorted: " << endl;
    tr(v, it) {
        cout << *it << ",";
    }
    cout << endl;

    return 0;
}
