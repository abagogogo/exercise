#include <cassert>
#include <iostream>
#include <optional>
#include <vector>

constexpr bool FIND_COMPRESSION = true;

class Subset {
 public:
  Subset(int size) : parent_(size, std::nullopt), rank_(size, 1) {}

  int find(int element) {
    assert(element >= 0 && element < static_cast<int>(parent_.size()));

    // Find the subset where the element belongs to (oldest parent)
    auto parent = parent_.at(element);
    if (!parent) return element;

    if (FIND_COMPRESSION) {
      parent_.at(element) = find(*parent);
    } else {
      return find(*parent);
    }

    return *parent_.at(element);
  }

  void unite(int u, int v) {
    assert(u >= 0 && u < static_cast<int>(parent_.size()));
    assert(v >= 0 && v < static_cast<int>(parent_.size()));

    int set_u = find(u);
    int set_v = find(v);

    // union by rank.
    if (rank_.at(set_u) < rank_.at(set_v)) {
      parent_.at(set_u) = set_v;
    } else if (rank_.at(set_u) > rank_.at(set_v)) {
      parent_.at(set_v) = set_u;
    } else {
      parent_.at(set_v) = set_u;
      rank_.at(set_u)++;
    }
  }

 private:
  std::vector<std::optional<int>> parent_;
  std::vector<int> rank_;
};
