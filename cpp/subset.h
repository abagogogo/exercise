#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

#define FIND_COMPRESSION 1

class Subset {
public:
    Subset(int size) {
        parent_.resize(size);
        rank_.resize(size);
        for (int i = 0; i < size; ++i) {
            parent_[i] = -1;
            rank_[i] = 1;
        }
    }

    int find(int element) {
        assert(element >= 0 && element < parent_.size());

        // Find the subset where the element belongs to (oldest parent)
        int parent = parent_[element];
        if (parent == -1) return element;
#if !FIND_COMPRESSION
        return find(parent);
#else
        parent_[element] = find(parent);
        return parent_[element];
#endif
    }

    void unite(int u, int v) {
        assert(u >= 0 && u < parent_.size());
        assert(v >= 0 && v < parent_.size());

        int set_u = find(u);
        int set_v = find(v);

        // union by rank.
        if (rank_[set_u] < rank_[set_v]) {
            parent_[set_u] = set_v;
        } else if (rank_[set_u] > rank_[set_v]) {
            parent_[set_v] = set_u;
        } else {
            parent_[set_v] = set_u;
            rank_[set_u]++;
        }
    }

protected:
    vector<int> parent_;
    vector<int> rank_;
};
