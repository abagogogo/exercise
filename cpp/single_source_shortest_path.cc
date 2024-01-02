#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX_DIST=INT_MAX;

struct AdjNode {
  int dst;
  int weight;
};

class Graph {
 private:
  vector<vector<AdjNode>> adj_list_;

 public:
  Graph(int vert_cnt) { adj_list_.resize(vert_cnt); }

  void add_edge(int src, int dst, int weight) {
    int max_v = max(src, dst);
    if (max_v >= static_cast<int>(adj_list_.size())) adj_list_.resize(max_v + 1);
    adj_list_[src].emplace_back(AdjNode{dst, weight});
  }

  void show() {
    for (int src = 0; src < static_cast<int>(adj_list_.size()); ++src) {
      for (const auto& [dst, weight] : adj_list_[src]) {
        cout << src << " -> " << dst << ", weight = " << weight << endl;
      }
    }
  }

  void shortest_path(int src) {
    set<pair<int, int>> pq;
    vector<int> dist(adj_list_.size(), MAX_DIST);

    pq.emplace(0, src);
    dist[src] = 0;

    while (!pq.empty()) {
      auto [_, u]  = *pq.begin();
      pq.erase(pq.begin());

      for (const auto& node : adj_list_[u]) {
        int v = node.dst;

        if (dist[v] > dist[u] + node.weight) {
          if (dist[v] != MAX_DIST) {
            pq.erase({dist[v], v});
          }
          dist[v] = dist[u] + node.weight;
          pq.emplace(make_pair(dist[v], v));
        }
      }
    }

    cout << "Vertext\tDistance from source (" << src << "):" << endl;
    for (int i = 0; i < static_cast<int>(dist.size()); ++i) {
      cout << i << "\t" << dist[i] << endl;
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
  g.shortest_path(0);

  return 0;
}
