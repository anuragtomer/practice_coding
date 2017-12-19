#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    public:
        vector <vector <int>> nodes;
        vector <int> reach;
        vector <bool> visited;
        Graph(int n) :  nodes(n, vector<int> (0)), reach(n), visited(n) {
        }

        void add_edge(int u, int v) {
            nodes.at(u).push_back(v);
            nodes.at(v).push_back(u);            
        }

        vector<int> shortest_reach(int start) { 
            queue <int> q;
            q.push_back(start);
            visited[start] = true;
            while(!q.isempty()) {
                int node = q.front();
                for (auto i = nodes[node].start(); i < nodes[node].end(); i++) {
                    if (!visited[i])
                        
                }
                q.pop();
            }
            return reach;
        }

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        uint startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (uint i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
