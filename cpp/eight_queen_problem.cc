#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Queen {
public:
    Queen(void) {
        row_ = col_ = 0;
    }

    bool isValid(const vector<Queen*> &settled_queens) {
        for (auto &p : settled_queens) {
            if (p->col_ == col_ || 
                abs(p->col_ - col_) == abs(p->row_ - row_)) {
                return false;
            }
        }
        return true;
    }

    static void resetQueens(vector<Queen> &queens) {
        int row = 0;
        for (auto &q : queens) {
            q.row_ = row++;
            q.col_ = 0;
        }

    }

    static void printQueens(const vector<Queen> &queens) {
        int i = 0;
        for (auto &q : queens) {
            cout << "Queen[" << i << "] = " << q.row_ << ", " << q.col_ << endl;
            ++i;
        }
    }

    static bool addQueen(vector<Queen*> &settled_queens, Queen *next_queen, int total_queen_num) {
        while (next_queen->col_ < total_queen_num) {
            if (next_queen->isValid(settled_queens)) {
                settled_queens.push_back(next_queen);
                return true;
            } else {
                next_queen->col_++;
            }
        }
        next_queen->col_ = 0;
        return false;
    }

    static void rollback(vector<Queen*> &settled_queens) {
        Queen *q = settled_queens.back();
        q->col_++;
        settled_queens.pop_back();
    }

protected:
    int row_;
    int col_;
};

int main(void) {
    int            total_queen_num = 8;
    vector<Queen>  queens(total_queen_num);
    vector<Queen*> settled_queens;
    Queen* next_queen;

    Queen::resetQueens(queens);
    settled_queens.push_back(&queens[0]);

    while( !settled_queens.empty() && settled_queens.size() < total_queen_num) {
        next_queen = &queens[settled_queens.size()];
        if (!Queen::addQueen(settled_queens, next_queen, total_queen_num)) {
            Queen::rollback(settled_queens);
        }
    }

    Queen::printQueens(queens);
    return 0;
}
