#include <stdio.h>
#include <stdlib.h>

#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define MAX_DIST INT_MAX

struct AdjNode {
  int dst;
  int weight;

  AdjNode(int d, int w) : dst(d), weight(w) {}
};

class Graph {
 protected:
  vector<vector<AdjNode>> adj_list_;

 public:
  Graph(int vert_cnt) { adj_list_.resize(vert_cnt); }

  void add_edge(int src, int dst, int weight) {
    int max_v = max(src, dst);
    if (max_v >= adj_list_.size()) adj_list_.resize(max_v + 1);
    adj_list_[src].push_back(AdjNode(dst, weight));
  }

  void show(void) {
    for (int src = 0; src < adj_list_.size(); ++src) {
      for (auto& node : adj_list_[src]) {
        cout << src << " -> " << node.dst << ", weight=" << node.weight << endl;
      }
    }
  }

  void shortest_path(int src) {
    set<pair<int, int>> setds;
    vector<int> dist(adj_list_.size(), MAX_DIST);

    setds.insert(make_pair(0, src));
    dist[src] = 0;

    while (!setds.empty()) {
      pair<int, int> edge = *setds.begin();
      setds.erase(setds.begin());

      int u = edge.second;
      for (auto& node : adj_list_[u]) {
        int v = node.dst;

        if (dist[v] > dist[u] + node.weight) {
          if (dist[v] != MAX_DIST) {
            setds.erase(make_pair(dist[v], v));
          }
          dist[v] = dist[u] + node.weight;
          setds.insert(make_pair(dist[v], v));
        }
      }
    }

    cout << "Vertext\tDistance from source (" << src << "):" << endl;
    for (int i = 0; i < dist.size(); ++i) {
      cout << i << "\t" << dist[i] << endl;
    }
  }
};

int main(void) {
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
