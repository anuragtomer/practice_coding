#include<iostream>
#include<vector>
#include<list>
#include<cassert>

using namespace std;

// Very handy macro to iterate it over list.
#define FOR(it, list)  for ((it) = (list).begin(); \
(it) != (list).end(); \
++(it))

#define iPair pair<int, int>

class Graph{
/* Directional Weighted Graph implementation using adjacency list. */

private:    
    int V;
    list<iPair> *adjList;    

public:
    Graph(int v): V{v} {
        adjList = new list<iPair> [V];
    }
    
    void addLink(int u, int v, int cost) {
        assert(u >= 0 && u < V &&
               v >= 0 && v < V);
        adjList[u].push_back(make_pair(v, cost));
    }

    void deleteLink(int u, int v) {
        list<iPair>::iterator it;
        /* There is no find function in Vectors. So writing one using iterator it. */
        FOR (it, adjList[u]) {        
            if ((*it).first == v) {
                adjList[u].erase(it);
                break;
            }
        }
    }

    void printGraph() {
        list<iPair>::iterator it;
        for (int i = 0; i < V; i++) {
            cout << "Links from " << i << " : ";
            FOR (it, adjList[i]) {
                cout << "(" << (*it).first << ", "<< (*it).second << ") ->";
            }
            cout << endl;
        }
    }

    friend vector<int> shortestPath(Graph *, int);
    friend int closestNode(const Graph *,const int, vector<int> &, vector<bool> &);

    ~Graph() {
        /* We allocated using new. We should delete. */
        delete [] adjList;
    }
};

int closestNode(const Graph *graph, const int curr, vector<int> &distance, vector<bool> &visited) {
    list<iPair>::iterator it;
    /* Update the distance to each neighbor vertices. */
    FOR (it, graph->adjList[curr]) { // O(E)
        int weight = (*it).second;
        int v = (*it).first;
        if (distance[v] > distance[curr] + weight) {
            /* Keep below if you want verbose output.
            cout << "\nUpdating distance of " << v << " from " << distance[v]
                 << " to " << distance[curr] + weight << endl;
            */
            distance[v] = distance[curr] + weight;
        }
    }
    /* Find new nearest neighbor */
    int min = INT_MAX;
    int minNode = -1;
    for (int i = 0; i < graph->V; i++) { // O(V)
        if (visited[i] == false && distance[i] < min) {
            minNode = i;
            min = distance[i];
        }
    }
    /* Keep below if you want verbose output.
    cout << "Min node is : " << minNode << endl;
    */
    return minNode;
}

vector<int> shortestPath(Graph *graph, int curr) {
    vector<int> distance (graph->V, INT_MAX);
    vector<bool> visited (graph->V, false);
    distance[curr] = 0;
    while (curr != -1) { // O(V)
        visited[curr] = true;
        curr = closestNode(graph, curr, distance, visited);        
    }
    return distance;
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
        int u, v, cost;
        cout << "Link from? to? cost? ";
        cin >> u >> v >> cost;
        graph->addLink(u, v, cost);
    }

    // Lets' print to be sure if we entered the intended graph.
    graph->printGraph();
    
    int ver;
    cout << "Source vertex: ";
    cin >> ver;
    vector<int> shortest = shortestPath(graph, ver); /* O(max(V^2,VE). Can be reduced to ElogV 
                                                        by using heap(closest searching (O(1))).*/

    /* Print Shortest path to each node from source. */
    for(auto i: shortest) {
        cout << i << " ";
    }

    delete graph;
    return 0;
}