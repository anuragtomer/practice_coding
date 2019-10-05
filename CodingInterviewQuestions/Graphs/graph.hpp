#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Graph{
    int V;
    int E;
    vector<vector<int>> graph;
public:
    Graph(int v, int e): V{v}, E{e}, graph{v, vector<int>{v, 0}} {}
    void addLink(int u, int v) {
        assert(u < V && v < V &&
               u >= 0 && v >= 0);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    void print() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << " " << graph[i][j];
            }
            cout << endl;
        }
    }
};