#include<iostream>
#include<vector>
#include<list>
#include<cassert>
#include<queue>

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
    list<iPair> *adjList; // A list of (neighbor node, distance to neighbor node) 

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

    friend vector<int> dijkstra(Graph *, int);    

    ~Graph() {
        /* We allocated using new. We should delete. */
        delete [] adjList;
    }
};

vector<int> dijkstra(Graph *graph, int source) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> minHeap;
    vector<int> distance (graph->V, INT_MAX);
    distance[source] = 0;
    minHeap.push(make_pair(0, source));
    while(minHeap.empty() == false) {
        int closestNode = minHeap.top().second;
        minHeap.pop();
        list<iPair>::iterator it;
        FOR(it, graph->adjList[closestNode]) {
            int v = (*it).first;
            int weight = (*it).second;
            // If you find smaller distance, update it.
            if (distance[v] > distance[closestNode] + weight) {
                distance[v] = distance[closestNode] + weight;
                // push this into priority_queue since we changed the distance.
                minHeap.push(make_pair(distance[v], v));
            }
        }
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
    
    int source;
    cout << "Source vertex: ";
    cin >> source;
    vector<int> shortest = dijkstra(graph, source); 

    /* Print Shortest path to each node from source. */
    for(auto i: shortest) {
        cout << i << " ";
    }

    delete graph;
    return 0;
}