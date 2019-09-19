#include<iostream>
#include<vector>
#include<list>
#include<cassert>

using namespace std;

class Graph{
/* Bidirectional Graph implementation using adjacency graph. */

private:    
    int V;
    list<int> *adjList;    

public:
    Graph(int v): V{v} {
        adjList = new list<int> [V];
    }
    
    void addLink(int u, int v) {
        /* Its a bidirectional graph. An edge means we should add to both nodes' adjacency list. */
        assert(u >= 0 && u < V &&
               v >= 0 && v < V);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void deleteLink(int u, int v) {
        list<int>::iterator it;
        /* There is no find function in List. So writing one using iterator it. */
        for (it = adjList[u].begin(); it != adjList[u].end(); it++) {
            if (*it == v) {
                adjList[u].erase(it);
                break;
            }
        }
        /* Again, since it is a bidirectional graph, removing an edge means removing from both 
         * nodes.
         */
        for (it = adjList[v].begin(); it != adjList[v].end(); it++) {
            if (*it == u) {
                adjList[v].erase(it);
                break;
            }
        }
    }

    void printGraph() {
        list<int>::iterator it;
        for (int i = 0; i < V; i++) {
            cout << "Neighbors of " << i << ": ";
            for (it = adjList[i].begin(); it != adjList[i].end(); it++) {
                cout << *it << "->";
            }
            cout << endl;
        }
    }

    /** A friend function DFS to do DFS traversal. friend because it would need access to no of 
     *  vertices, and adjList.
     */
    friend void DFS(Graph *, vector<bool> &);
    friend void DFSTraversal(Graph *, int, vector<bool> &);

    ~Graph() {
        /* We allocated using new. We should delete. */
        delete [] adjList;
    }
};

/* Core function for traversal. Traverses only neighbors, connected components. */
void DFSTraversal(Graph * graph, int u, vector<bool> & visited) {
    visited[u] = true; // Mark this node visited.
    cout << "Visiting: " << u << endl;
    for(list<int>::iterator it = graph->adjList[u].begin(); it!= graph->adjList[u].end(); it++) {
        if (visited[*it] == false) {
            DFSTraversal(graph, *it, visited);
        }
    }
}

// DFS to traverse for each vertex. Handles even disconnected graph.
void DFS(Graph * graph, vector<bool> &visited) {
    for (int i = 0; i < graph->V; i++) {
        if (visited[i] == false)
            DFSTraversal(graph, i, visited);
    }
}

int main() {
    /* Driver function. */
    int V, E;
    cout << "No of nodes: ";
    cin >> V;
    Graph *graph = new Graph(V);
    cout << "No of vertices: ";
    cin >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cout << "Link from? ";
        cin >> u;
        cout << " to? ";
        cin >> v;
        graph->addLink(u, v);
    }

    // Lets print to be sure if we entered the intended graph.
    graph->printGraph();
    
    // Do the DFS traversal.
    vector<bool> visited(V, false);
    DFS(graph, visited);

    delete graph;
    return 0;
}