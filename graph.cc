#include "graph.h"

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    Graph g1;
    g1.add_edge(Edge(0, 1, 10));
    g1.add_edge(Edge(1, 2, 5));
    g1.add_edge(Edge(1, 4, 15));
    g1.add_edge(Edge(2, 0, 20));
    g1.add_edge(Edge(2, 3, 1));
    g1.show();

    g1.bfs(0);
    g1.dfs(0);
    g1.dfs_r(0);
    cout << "the graph" << (g1.has_cycle() ? "has cycle(s)" : "has no cycle") << endl;
    return 0;
}
