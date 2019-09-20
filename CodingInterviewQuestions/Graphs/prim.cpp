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
/* Weighted Graph implementation using adjacency list. */

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
        adjList[v].push_back(make_pair(u, cost));
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

    friend vector<iPair> prim(Graph *);    

    ~Graph() {
        /* We allocated using new. We should delete. */
        delete [] adjList;
    }
};

vector<iPair> prim(Graph *graph) {
    /* distance saves (distance, node to-be taken to reach here) */
    vector<iPair> distance (graph->V, make_pair(INT_MAX, 0));
    distance[0] = make_pair(0, 0);
    vector<bool> visited (graph->V, false);
    priority_queue<iPair, vector<iPair>, greater<iPair>> queue; // min heap
    queue.push(distance[0]);
    while(queue.empty() == false) {
        int u = queue.top().second;
        queue.pop();
        visited[u] = true;
        list<iPair>::iterator it;
        FOR(it, graph->adjList[u]) {
            int v = it->first;
            int weight = it->second;
            if (visited[v] == false && distance[v].first > weight) {         
                distance[v].first = weight;
                distance[v].second = u;
                queue.push(make_pair(weight, v));
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

    /* Lets' print to be sure if we entered the intended graph. */
    graph->printGraph();

    vector<iPair> shortest = prim(graph); 

    /* Print Shortest path to each node from source. */
    int sum = 0;
    for(auto i: shortest) {
        sum += i.first;
        cout << i.second << " ";
    }
    cout << "Total cost: " << sum;
    delete graph;
    return 0;
}