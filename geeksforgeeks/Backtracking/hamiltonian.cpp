#include <iostream>
#include <vector>

using namespace std;

#define MAXVERT 10

class Solution {
public:
    void printPath(int path[MAXVERT], int nVer) {
        cout << "Path exists:";
        for (int i = 0; i < nVer; i++) {
            cout << path[i] << " ";
        }
        cout << path[0];
        cout << endl;
    }

    bool pathPossible(int graph[MAXVERT][MAXVERT], int nVer, int vertex, int path[MAXVERT], int pathLen) {
        for (int i = 0; i < pathLen; i++) {
            if (path[i] == vertex)
                return false;
        }
        if (graph[vertex][path[pathLen - 1]] == 1) {
            return true;
        }
        return false;
    }

    bool loopBack(int graph[MAXVERT][MAXVERT], int nVer, int path[MAXVERT], int pathLen) {
         /* Base condition */
        if (pathLen == nVer) {
            if (graph[path[pathLen - 1]][path[0]] == 1) {
                printPath(path, pathLen);
                return true;
            }
            return false;
        }
        for (int vertex = 0; vertex < nVer; vertex++) {
            if (pathPossible(graph, nVer, vertex, path, pathLen)) {
                path[pathLen] = vertex;
                if (loopBack(graph, nVer, path, pathLen + 1)) {
                    return true;
                }
                path[pathLen] = -1;
            }

        }
        return false;
    }

    bool hamiltonian(int graph[MAXVERT][MAXVERT], int nVer) {
        int path[MAXVERT];
        int pathLen = 0;
        for (int i = 0; i < nVer; i++)
            path[i] = -1;
        return loopBack(graph, nVer, path, pathLen);
    }
};

int main(){
    Solution sol;
    int nVer;
    int graph[MAXVERT][MAXVERT];
    cin >> nVer;
    for (int i = 0; i < nVer; i++) {
        for (int j = 0; j < nVer; j++) {
            cin >> graph[i][j];
        }
    }
    if (!sol.hamiltonian(graph, nVer)) {
        cout << "No solution exists.";
    }
    return 0;
}
