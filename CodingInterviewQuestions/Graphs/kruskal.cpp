#include<iostream>
#include<vector>
#include<list>
#include<cassert>
#include<queue>
#include<unordered_set>

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
        // Add bidirectional links.
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

    friend int kruskal(const Graph *, vector<iPair> &);

    ~Graph() {
        /* We allocated using new. We should delete. */
        delete [] adjList;
    }
};

struct triplet{
    int cost;
    int u;
    int v;
    triplet(int _cost, int _u, int _v): cost(_cost), u(_u), v(_v) {}
    friend bool operator> (const triplet obj1, const triplet obj2);
};

bool operator>(const triplet obj1, const triplet obj2) {
    if (obj1.cost > obj2.cost) 
        return true;
    else 
        return false;
}


int getParent(int i, const vector<int> parent) {
    while(i != parent[i])
        i = parent[i];
    return i;
}

void printheap(priority_queue<triplet, vector<triplet>, greater<triplet>> heap) {
    cout << heap.top().u << "-> " << heap.top().v << " with cost " << heap.top().cost << endl;
    heap.pop();
    printheap(heap);
}
int kruskal(const Graph *graph, vector<iPair> &distance) {
    priority_queue<triplet, vector<triplet>, greater<triplet>> heap;
    list<iPair>::iterator it;
    vector<iPair> inheap;

    /* Setup the heap to have cost, u, v so that we can pick up min cost edge in O(1). */
    for (int u = 0; u < graph->V; u++) {
        FOR (it, graph->adjList[u]) {
            int v = it->first;
            int cost = it->second;
            vector<iPair>::iterator it2;
            bool inserted = false;
            FOR(it2, inheap) {
                if ((it2->first == u && it2->second == v) ||
                    (it2->first == v && it2->second == u)) {
                    inserted = true;
                }
            }
            if (!inserted) {
                triplet t (cost, u, v);
                heap.push(t);
                inheap.push_back(make_pair(u, v));
            }
        }
    }

    // By now, we have made min heap. Lets find MST now.
    int added = 0;
    int cost = 0;
    vector<int> parent(graph->V); // This saves the smallest numbered parent.
    for(int i = 0; i < graph->V; i++)
        parent[i] = i; // Initialized to itself.

    while(added != graph->V-1) { // There can be max of V-1 edges in a tree of V nodes.
        triplet t = heap.top();
        heap.pop();
        int parentu = getParent(t.u, parent);
        int parentv = getParent(t.v, parent);
        if (parentu != parentv) {
            added++;
            // Both nodes are part of different disconnected components.
            cost += t.cost;
            distance.push_back(make_pair(t.u, t.v));
            // The following connects the 2 disconnected components.
            if (parentu < parentv)
                parent[parentv] = parentu;
            else
                parent[parentu] = parentv;
        }
    }
    return cost;
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
    vector<iPair> shortest;
    int cost = kruskal(graph, shortest); 

    /* Print Shortest path to each node from source. */
    for(auto &i: shortest) {
        cout << "Path from: "<< i.first << " to " << i.second << endl;
    }
    cout << "Total cost: " << cost;
    delete graph;
    return 0;
}