#include <algorithm>
#include <deque>
#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "subset.h"

using namespace std;

class Edge {
 public:
  Edge(int src, int dst, int weight) : src_(src), dst_(dst), weight_(weight) {}

  void show(void) {
    cout << "src = " << src_;
    cout << ", dst = " << dst_;
    cout << ", weight = " << weight_ << endl;
  }

  int src() const { return src_; }
  int dst() const { return dst_; }
  int weight() const { return weight_; }

  static bool comp(const Edge &e1, const Edge &e2) {
    return e1.weight() < e2.weight();
  }

 protected:
  int src_;
  int dst_;
  int weight_;
};

class Graph {
 public:
  void add_edge(Edge e) {
    int v = max(e.src(), e.dst());
    edges_.emplace_back(e);
    if (v > vert_cnt_) vert_cnt_ = v + 1;
    adj_list_[e.src()].emplace_back(e.dst());
  }

  void show(void) {
    for (auto &e : edges_) e.show();
  }

  unordered_map<int, vector<int>> &get_adj_list() { return adj_list_; }
  vector<Edge> &get_edges() { return edges_; }
  int get_vert_cnt() { return vert_cnt_; }

  void bfs_old(int start) {
    deque<int> queue;
    unordered_map<int, bool> visited;

    queue.push_back(start);
    visited[start] = true;
    while (!queue.empty()) {
      int curr = queue.front();
      queue.pop_front();
      cout << "BFS old: do something to " << curr << endl;

      for (auto &neighbor : adj_list_[curr]) {
        if (!visited[neighbor]) {
          queue.push_back(neighbor);
          visited[neighbor] = true;
        }
      }
    }
  }

  void bfs(int start) {
    deque<int> queue;
    vector<bool> visited(vert_cnt_, false);

    queue.emplace_back(start);
    visited[start] = true;
    while (!queue.empty()) {
      int curr = queue.front();
      queue.pop_front();
      cout << "BFS: do something to " << curr << endl;

      for (int neighbor : adj_list_[curr]) {
        if (!visited[neighbor]) {
          queue.emplace_back(neighbor);
          visited[neighbor] = true;
        }
      }
    }
  }

  void dfs_old(int start) {
    stack<int> stack;
    unordered_map<int, bool> visited;

    stack.push(start);
    while (!stack.empty()) {
      int curr = stack.top();
      stack.pop();

      if (!visited[curr]) {
        visited[curr] = true;
        for (auto &neighbor : adj_list_[curr]) {
          if (!visited[neighbor]) stack.push(neighbor);
        }
        cout << "DFS old: do something to " << curr << endl;
      }
    }
  }

  void dfs(int start) {
    stack<int> stack;
    vector<bool> visited(vert_cnt_, false);

    stack.push(start);
    visited[start] = true;
    while (!stack.empty()) {
      int curr = stack.top();
      stack.pop();

      cout << "DFS: do something to " << curr << endl;
      for (int neighbor : adj_list_[curr]) {
        if (!visited[neighbor]) {
          stack.push(neighbor);
          visited[neighbor] = true;
        }
      }
    }
  }

  void dfs_r(int start) {
    unordered_map<int, bool> visited;
    dfs_r(start, visited);
  }

  void dfs_r(int curr, unordered_map<int, bool> &visited) {
    if (visited[curr]) return;

    visited[curr] = true;
    cout << "DFS_r: do something to " << curr << endl;
    for (auto &neighbor : adj_list_[curr]) {
      dfs_r(neighbor, visited);
    }
  }

  bool has_cycle(void) {
    // a disjoint set
    // for each edge (u, v)
    //   if find(u) == find(v) return true
    Subset set(adj_list_.size());
    int u, v;

    for (auto &e : edges_) {
      u = e.src();
      v = e.dst();
      int set_u = set.find(u);
      int set_v = set.find(v);
      if (set_u == set_v) return true;
      set.unite(set_u, set_v);
    }
    return false;
  }

 protected:
  unordered_map<int, vector<int>> adj_list_;
  vector<Edge> edges_;
  int vert_cnt_;
};
