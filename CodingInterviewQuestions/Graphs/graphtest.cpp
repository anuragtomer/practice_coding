#include "graph.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    int u, v;
    Graph mygraph = Graph(V, E);
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        mygraph.addLink(u, v);
    }
    mygraph.print();
    return 0;
}