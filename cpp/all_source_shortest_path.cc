#include <algorithm>
#include <climits>
#include <iostream>
#include <limits>
#include <optional>
#include <tuple>
#include <vector>

using namespace std;

class Graph {
public:
  struct Edge {
    int dst;
    int weight;

    constexpr Edge(int d, int w) : dst(d), weight(w) {};
  };

 private:
  vector<vector<Edge>> adj_list_;
  static constexpr auto INF = std::numeric_limits<int>::max();

 public:
  explicit Graph(size_t vert_cnt) : adj_list_(vert_cnt) {};

  void add_edge(int src, int dst, int weight) {
    const auto max_v = max(src, dst);
    if (max_v >= static_cast<int>(adj_list_.size())) {
      adj_list_.resize(max_v + 1);
    }
    adj_list_[src].emplace_back(dst, weight);
  }

  void show() {
    for (size_t src = 0; src < adj_list_.size(); ++src) {
      for (const auto& edge : adj_list_[src]) {
        cout << src << " -> " << edge.dst
            << ", weight=" << edge.weight << endl;
      }
    }
  }

  [[nodiscard]]
  optional<int> get_edge_weight(int u, int v) const {
    if (u >= static_cast<int>(adj_list_.size())) {
      return nullopt;
    }

    const auto it = find_if(
      adj_list_[u].begin(), 
      adj_list_[u].end(),
      [v](const auto& edge) { return edge.dst == v; }
    );

    return it != adj_list_[u].end()
      ? optional{it->weight}
      : nullopt;
  }

  //
  // Floyd-Warshall, dynamic programming:
  // M_k(u, v) = min ( M_k-1(u, s) + weight(s, v), M_k-1(u, v))
  //
  void shortest_path() const {
    const auto vert_cnt = adj_list_.size();
    vector<vector<int>> M(vert_cnt, vector<int>(vert_cnt, INF));

    for (size_t u = 0; u < vert_cnt; ++u) {
      M[u][u] = 0;
      for (const auto &edge : adj_list_[u]) {
        M[u][edge.dst] = edge.weight;
      }
    }

    for (size_t k = 0; k < vert_cnt; ++k) {
      for (size_t u = 0; u < vert_cnt; ++u) {
        for (size_t v = 0; v < vert_cnt; ++v) {
          if (M[u][k] != INF) {
            if (const auto weight = get_edge_weight(k, v); weight) {
              M[u][v] = min(
                M[u][v],
                M[u][k] + *weight);
            }
          }
        }
      }
    }

    for (size_t u = 0; u < vert_cnt; ++u) {
      for (size_t v = 0; v < vert_cnt; ++v) {
        if (M[u][v] != INF) {
          cout << "M[" << u << "][" << v << "] = "
              << M[u][v] << endl;
        }
      }
    }
  }
};

int main() {
  // Test case 1
  Graph g1(9);
  const vector<tuple<int, int, int>> edges1 = {
    {0, 1, 4},  {0, 7, 8},  {1, 2, 8},  {1, 7, 11},
    {2, 3, 7},  {2, 8, 2},  {2, 5, 4},  {3, 4, 9},
    {3, 5, 14}, {4, 5, 10}, {5, 6, 2},  {6, 7, 1},
    {6, 8, 6},  {7, 8, 7}
  };
   
  for (const auto& [src, dst, weight] : edges1) {
    g1.add_edge(src, dst, weight);
  }

  cout << "Graph 1" << endl;
  g1.show();
  g1.shortest_path();

  // Test case 1
  Graph g2(4);
  const vector<tuple<int, int, int>> edges2 = {
    {0, 1, 5}, {0, 3, 10}, {1, 2, 3}, {2, 3, 1}
  };

  for (const auto& [src, dst, weight] : edges2) {
    g2.add_edge(src, dst, weight);
  }

  g2.show();
  g2.shortest_path();

  return 0;
}
