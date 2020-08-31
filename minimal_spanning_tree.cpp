#include "graph.h"
#include <vector>
#include <algorithm>

using namespace std;

bool mst(Graph &g) {
    // 1. Sort all edges in non-decreasing order of their weight.
    // 2. Pick the smallest edge. Check if it forms a cycle with the spanning tree.
    //    If not, include the edge; otherwise, discard it.
    // 3. Repeate 2 untill there are (V-1) edges in the spanning tree.
    int          vert_cnt = g.get_vert_cnt();
    Subset       cyc(vert_cnt);
    vector<Edge> mst;
    vector<Edge> sorted_edges(g.get_edges().begin(), g.get_edges().end());
    bool         found = false;

    sort(sorted_edges.begin(), sorted_edges.end(), Edge::comp);
    for (auto &e : sorted_edges) {
        int src_set = cyc.find(e.src());
        int dst_set = cyc.find(e.dst());
        if (src_set != dst_set) {
            cyc.unite(src_set, dst_set);
            mst.push_back(e);
            if (mst.size() == vert_cnt - 1) {
                found = true;
                break;
            }
        }
    }

    cout << (found ? "Found" : "NOT found");
    cout << " minimal spanning tree (" << mst.size() << "):" << endl;
    for (auto &e : mst) {
        cout << "(" << e.src() << ", " << e.dst() << ") = " << e.weight() << endl;
    }
    return found;
}

int main(void) {
    Graph g1;
    g1.add_edge(Edge(0, 1, 10));
    g1.add_edge(Edge(1, 2, 5));
    g1.add_edge(Edge(1, 4, 15));
    g1.add_edge(Edge(2, 0, 20));
    g1.add_edge(Edge(2, 3, 1));
    g1.show();

    mst(g1);
    return 0;
}
