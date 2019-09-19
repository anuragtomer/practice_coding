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
        /* There is no find function in List. So writing one using iterator it. */
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

    /* A friend function topological to do topological traversal. 'friend' because it would need 
     * access to no of vertices in graph and their adjList.
     */
    friend void topologicalSort(const Graph *);
    friend void adjustInflow(const Graph *, const int, queue<int> &, vector<int> &);

    ~Graph() {
        /* We allocated using new. We should delete. */
        delete [] adjList;
    }
};

void adjustInflow(const Graph *graph, const int curr, queue<int> &queue, vector<int> &inflow) {
    list<int>::iterator it;
    for (it = graph->adjList[curr].begin();
         it != graph->adjList[curr].end();
         it++) {
        inflow[*it]--;
        if (inflow[*it] == 0) {
            queue.push(*it);
        }
    }
}

void topologicalSort(const Graph *graph) {
    vector<int> inflow(graph->V, 0);
    queue<int> queue;

    // Calculate inflows of each node.
    for (int i = 0; i < graph->V; i++) {
        list<int>::iterator it;
        for (it = graph->adjList[i].begin();
             it != graph->adjList[i].end();
             it++) {
            inflow[*it]++;
        }
    }
    
    // Put all the elements in the queue which have no inflow. They can basically get done.
    for (int i= 0; i < graph->V; i++) {
        if (inflow[i] == 0) {
            queue.push(i);
        }
    }

    while(queue.empty() == false) {
        int curr = queue.front();
        queue.pop();
        cout << curr << " ";
        adjustInflow(graph, curr, queue, inflow);
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

    // Lets' print to be sure if we entered the intended graph.
    graph->printGraph();
    
    // Prerequisite: Graph must be acyclical.
    topologicalSort(graph);
    
    delete graph;
    return 0;
}