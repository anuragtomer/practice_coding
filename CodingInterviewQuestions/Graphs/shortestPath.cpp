#include<iostream>
#include<vector>
#include<list>
#include<cassert>
#include<queue>

using namespace std;

class Graph{
/* Directional Graph implementation using adjacency list. */

private:    
    int V;
    list<int> *adjList;    

public:
    Graph(int v): V{v} {
        adjList = new list<int> [V];
    }
    
    void addLink(int u, int v) {
        assert(u >= 0 && u < V &&
               v >= 0 && v < V);
        adjList[u].push_back(v);
    }

    void deleteLink(int u, int v) {
        list<int>::iterator it;
        /* There is no 'find' function in List. So writing one using iterator it. */
        for (it = adjList[u].begin(); it != adjList[u].end(); it++) {
            if (*it == v) {
                adjList[u].erase(it);
                break;
            }
        }
    }

    void printGraph() {
        list<int>::iterator it;
        for (int i = 0; i < V; i++) {
            cout << "Link from " << i << " : ";
            for (it = adjList[i].begin(); it != adjList[i].end(); it++) {
                cout << *it << "->";
            }
            cout << endl;
        }
    }

    friend vector<vector<int> > shortestPath(Graph *, int );
    ~Graph() {
        /* We allocated using new. We should delete. */
        delete [] adjList;
    }
};

vector<vector<int> > shortestPath(Graph *graph, int ver) {
    vector<vector<int>> path(graph->V, vector<int>(2, -1));
    queue<int> queue; // Keeps track of nodes we saw but not yet visited.
    queue.push(ver);
    // Starting vertex is at 0 hops.
    path[ver][0] = 0;
    path[ver][1] = ver;
    while(queue.empty() == false) {
        int curr = queue.front();
        queue.pop();
        list<int>::iterator it;
        for(it = graph->adjList[curr].begin(); 
            it != graph->adjList[curr].end();
            it++) {
            if (path[*it][0] == -1) {
                // We have not seen this before. Lets update its path and add it to queue.
                path[*it][0] = path[curr][0] + 1;
                path[*it][1] = curr;
                queue.push(*it);
            }
        }
    }
    return path;
}

int main() {
    /* Driver function. */
    int V, E;
    cout << "No of nodes: ";
    cin >> V;
    Graph *graph = new Graph(V);
    cout << "No of edges: ";
    cin >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cout << "Link from? ";
        cin >> u;
        cout << " to? ";
        cin >> v;
        graph->addLink(u, v);
    }

    // Lets' print to be sure if we entered the intended graph.
    graph->printGraph();

    cout << "Enter source vertex: ";
    int ver;
    cin >> ver;
    /* Vector shortest keeps 2 items for each vertex: 
     * - min hops to that node
     * - Previous node via which we came to this node making the shortest hop.
     */
    vector<vector<int>> shortest = shortestPath(graph, ver);

    cout << "Shortest Path vector:\n";
    for(auto temp: shortest) {
        cout << "Hops: "<< temp[0] << ", via: " << temp[1] << endl;
    }
    
    delete graph;
    return 0;
}