#include <iostream>

using namespace std;

class MultiTable {
public:
    MultiTable(int num) : num_(num) {}
    friend ostream& operator<<(ostream& os, MultiTable& t);

protected:
    void print_header(ostream& os);
    void print_row(ostream& os, int row);

protected:
    int num_;
};

void MultiTable::print_header(ostream& os) {
    int col;

    os << "  | ";
    for (col = 1; col <= num_; ++col) {
        os << col << " ";
    }
    os << endl;

    os << "--+";
    for (col = 1; col <= num_; ++col) {
        os << "--";
    }
    os << endl;
}

void MultiTable::print_row(ostream& os, int row) {
    if (row < 0 || row > num_) return;

    os << row << " | ";
    for (int col = 1; col <= num_; ++col) {
       os << (row * col) << " ";
    }
    os << endl;
}

ostream& operator<<(ostream& os, MultiTable& t) {
    t.print_header(os);
    for (int row = 1; row <= t.num_; ++row) {
        t.print_row(os, row);
    }
    return os;
}

int main(void) {
    class MultiTable t(9);
    cout << t;
    return 0;
}
