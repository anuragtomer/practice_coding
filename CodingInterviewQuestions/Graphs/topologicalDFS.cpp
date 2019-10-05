#include<iostream>
#include<vector>
#include<list>
#include<cassert>
#include<stack>

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
    friend void topologicalSort(Graph *);
    friend void topologicalSortDFS(Graph *, int, vector<bool> &, vector<bool> &, stack<int> &);

    ~Graph() {
        /* We allocated using new. We should delete. */
        delete [] adjList;
    }
};

void topologicalSortDFS(Graph *graph, 
                        int v, 
                        vector<bool> &seeingCurrently, 
                        vector<bool> &processed, 
                        stack<int> &st) {
    /* So, we are starting to process this node. */
    seeingCurrently[v] = true;
    list<int>::iterator it;
    for (it = graph->adjList[v].begin(); 
         it != graph->adjList[v].end(); 
         it++) {
        /* If seeingCurrently is true, and processed is false, that means there is cyclic 
         * loop here. We are going in circles with an aim of finish processing a node.*/
        if (seeingCurrently[*it] == false && processed[*it] == false) {
            topologicalSortDFS(graph, *it, seeingCurrently, processed, st);
        }
    }
    /* We have seen all its children. Lets mark this done and push it to our output stack. */
    seeingCurrently[v] = false;
    processed[v] = true;
    st.push(v);
}

void topologicalSort(Graph * graph) {
    vector<bool> seeingCurrently(graph->V, false);
    vector<bool> processed(graph->V, false);
    stack<int> st;
    /* Find out which nodes are not done yet and then process them. */
    for (int i = 0; i < graph->V; i++) {
        if (processed[i] == false) {
            topologicalSortDFS(graph, i, seeingCurrently, processed, st);
        }
    }
    vector<int> output;
    while(st.empty() == false) {
        output.push_back(st.top());
        st.pop();
    }
    for (int i: output) {
        cout << i << " ";
    }
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
    
    // Prerequisite: Graph must be acyclical.
    topologicalSort(graph);
    
    delete graph;
    return 0;
}