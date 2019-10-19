#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct Graph {
    int V;
    vector<int> *adjList;  // A list of (neighbor node, distance to neighbor node) 

    Graph(int v): V{v} {
        adjList = new vector<int> [v];
    }

    void insert(int u, int v) {
        adjList[u].push_back(v);
    }
};

void printGraph(Graph graph) {
    for (int i = 0; i < graph.V; ++i) {
        cout << i << "->";
        for (vector<int>::iterator it = graph.adjList[i].begin();
             it != graph.adjList[i].end();
             ++it)
            cout << *it << ", ";
        cout << "\n";
    }
}

vector<int>
BuildOrder(vector<pair<int, int>> order) {
    int max = 0;

    // Find how many nodes are there in the graph.
    for (int i= 0; i < order.size(); ++i) {
        if (order[i].first > max)
            max = order[i].first;
        if (order[i].second > max)
            max = order[i].second;
    }

    cout << max;
    // Init the graph.
    Graph graph(max+1);
    
    cout << "Graph created.";
    // Read each link and to graph.
    for (int i= 0; i < order.size(); ++i) {
        graph.insert(order[i].first, order[i].second);
    }
    printGraph(graph);
    // By now, our graph should be ready to be processed.
    vector<int> output;
    queue<int> q;
    vector<int> inlinks(graph.V, 0);

    // Count how many incoming links are there for each node.
    for (int i = 0; i < graph.V; i++) {
        for (vector<int>::iterator it = graph.adjList[i].begin();
             it != graph.adjList[i].end();
             ++it)
            inlinks[*it]++;
    }

    /*
     * Add the nodes for which incoming link is 0. Those are the orders that can be completely 
     * right away.
     */
    for (int i = 0; i < graph.V; ++i) {
        if (inlinks[i] == 0)
            q.push(i);
    }

    while(q.empty() == false) {
        int top = q.front();
        q.pop();
        output.push_back(top);
        for (vector<int>::iterator it = graph.adjList[top].begin();
             it != graph.adjList[top].end();
             ++it) {
            /*
             * Since this project is done, reduce the dependencies count from all the neighbors of 
             * this node.
             */
            inlinks[*it]--;
            if (inlinks[*it] == 0)
                /*
                 * If all the dependencies for this project are done, add this to queue to be 
                 * processed.
                 */
                q.push(*it);
        }
    }
    return output;
}

int main() {
    int e;
    cin >> e;
    vector<pair<int, int>> order;
    int u, v;
    while(e--) {
        cin >> u >> v;
        order.push_back(make_pair(u, v));
    }
    vector<int> output = BuildOrder(order);

    for (auto v: output)
        cout << v << " ";
    
    return 0;
}