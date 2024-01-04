#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX_DIST=INT_MAX;

struct AdjNode {
  int dst;
  int weight;

  AdjNode(int d, int w) : dst(d), weight(w) {}
};

class Graph {
 private:
  vector<vector<AdjNode>> adj_list_;

 public:
  Graph(int vert_cnt) { adj_list_.resize(vert_cnt); }

  void add_edge(int src, int dst, int weight) {
    int max_v = max(src, dst);
    if (max_v >= static_cast<int>(adj_list_.size())) adj_list_.resize(max_v + 1);
    adj_list_[src].emplace_back(AdjNode(dst, weight));
  }

  void show(void) {
    for (int src = 0; src < static_cast<int>(adj_list_.size()); ++src) {
      for (auto &node : adj_list_[src]) {
        cout << src << " -> " << node.dst << ", weight=" << node.weight << endl;
      }
    }
  }

  bool is_edge(int u, int v, int &weight) {
    if (u < static_cast<int>(adj_list_.size())) {
      for (auto &n : adj_list_[u]) {
        if (n.dst == v) {
          weight = n.weight;
          return true;
        }
      }
    }
    weight = INT_MAX;
    return false;
  }

  //
  // Floyd-Warshall, dynamic programming:
  // M_k(u, v) = min ( M_k-1(u, s) + weight(s, v), M_k-1(u, v))
  //
  void shortest_path() {
    int vert_cnt = static_cast<int>(adj_list_.size());
    vector<vector<int>> M(vert_cnt, vector<int>(vert_cnt, INT_MAX));

    for (int u = 0; u < vert_cnt; ++u) {
      M[u][u] = 0;
      for (auto &n : adj_list_[u]) {
        M[u][n.dst] = n.weight;
      }
    }

    for (int k = 0; k < vert_cnt; ++k) {
      for (int u = 0; u < vert_cnt; ++u) {
        for (int v = 0; v < vert_cnt; ++v) {
          if (int weight; M[u][k] != INT_MAX && is_edge(k, v, weight)) {
            int new_cost = M[u][k] + weight;
            if (new_cost < M[u][v]) {
              M[u][v] = new_cost;
            }
          }
        }
      }
    }

    for (int u = 0; u < vert_cnt; ++u) {
      for (int v = 0; v < vert_cnt; ++v) {
        if (M[u][v] != INT_MAX) {
          cout << "M[" << u << "][" << v << "] = " << M[u][v] << endl;
        }
      }
    }
  }
};

int main() {
  Graph g(9);

  g.add_edge(0, 1, 4);
  g.add_edge(0, 7, 8);
  g.add_edge(1, 2, 8);
  g.add_edge(1, 7, 11);
  g.add_edge(2, 3, 7);
  g.add_edge(2, 8, 2);
  g.add_edge(2, 5, 4);
  g.add_edge(3, 4, 9);
  g.add_edge(3, 5, 14);
  g.add_edge(4, 5, 10);
  g.add_edge(5, 6, 2);
  g.add_edge(6, 7, 1);
  g.add_edge(6, 8, 6);
  g.add_edge(7, 8, 7);

  g.show();
  g.shortest_path();

  Graph g2(4);
  g2.add_edge(0, 1, 5);
  g2.add_edge(0, 3, 10);
  g2.add_edge(1, 2, 3);
  g2.add_edge(2, 3, 1);
  g2.show();
  g2.shortest_path();

  return 0;
}
