#include <iostream>
#include <map>

using namespace std;

#define tr(container, it) \
    for (typeof(container.begin())it = container.begin(); \
         it != container.end(); \
         it++) 

#define all(container) container.begin(), container.end()

int main(void)
{
    map<string, int> M;

    M["Top"] = 1;
    M["Coder"] = 2;
    M["SRM"] = 10;

    int x = M["Top"] + M["Coder"];
    cout << "x = " << x << endl;

    cout << "Traversing map M:" << endl;
    tr(M, it) {
        cout << "   " << it->first << " => "<< it->second << endl;
    }

    if (M.find("SRM") != M.end()) {
        cout << "Found and erase it" << endl;
        M.erase("SRM");
    }

    map<string, int>::iterator found;
    found = M.find("Nothing");
    if (found != M.end()) {
        M.erase(found);
    }
    tr(M, it) {
        cout << "   " << it->first << " => "<< it->second << endl;
    }


    return 0;
}
