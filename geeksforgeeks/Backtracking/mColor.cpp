#include <iostream>
#include <vector>

using namespace std;

#define MAXVERT 10
#define MAXEDGE 45

class Solution {
public:
    void printVertexColor(int vertexColor[MAXVERT], int nVer) {
        for (int i = 0; i < nVer; i++) {
            cout << vertexColor[i] << " ";
        }
        cout << endl;
    }

    bool colorPossible(int graph[MAXVERT][MAXVERT], int nVer, int color, int vertexColor[MAXVERT], int vertex) {
        if (vertexColor[vertex] != 0)
            return false;
        for (int i = 0; i < nVer; i++) {
            if (graph[vertex][i] == 1) {
                if (vertexColor[i] == color)
                    return false;
            }
        }
        return true;
    }

    bool loopBack(int graph[MAXVERT][MAXVERT], int nVer, int vertexColor[MAXVERT], int currColor, int maxColor) {
         /* Base condition */
        bool doneAllVertices = true;
        for (int i = 0; i < nVer; i++) {
            if (vertexColor[i] == 0)
                doneAllVertices = false;
        }
        if (doneAllVertices == true) {
            printVertexColor(vertexColor, nVer);
            return true;
        }
        for (int i = 0; i < nVer; i++) {
            for (int j = 1; j <= maxColor; j++) {
                if (colorPossible(graph, nVer, j, vertexColor, i)) {
                    vertexColor[i] = j;
                    if (loopBack(graph, nVer, vertexColor, j + 1, maxColor)) {
                        return true;
                    }
                    vertexColor[i] = 0;
                }
            }
        }
        return false;
    }

    bool mColor(int graph[MAXVERT][MAXVERT], int nVer, int maxColor) {
        int vertexColor[MAXVERT];
        for (int i = 0; i < nVer; i++) {
            vertexColor[i] = 0;
        }
        vertexColor[0] = 1;
        return loopBack(graph, nVer, vertexColor, 1, maxColor);
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
    int maxColor;
    cin >> maxColor;
    if (!sol.mColor(graph, nVer, maxColor)) {
        cout << "No solution exists.";
    }
    return 0;
}
