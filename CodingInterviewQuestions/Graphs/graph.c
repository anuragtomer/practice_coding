#include<stdio.h>
#include<assert.h>
#include<malloc.h>
int V;
int E;
int **graph;

int ** Graph(int v, int e) {
    graph = (int**) malloc(sizeof(int *) * v);
    for (int i = 0; i < v; i++) 
        graph[i] = (int *) malloc(sizeof(int) * v);

    for (int u = 0; u < V; u++) 
        for (int v = 0; v < V; v++) {
            graph[u][v] = 0;
        }
    return graph;
}
void addLink(int u, int v) {
    assert(u < V && v < V &&
            u >= 0 && v >= 0);
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void printgraph() {
    for (int u = 0; u < V; u++) 
        for (int v = 0; v < V; v++) 
            printf("%d ", graph[u][v]);
}
int main() {
    scanf("%d", &V);
    scanf("%d", &E);
    graph = Graph(V, E);
    printf("Enter links: ");
    int u, v;
    for(int j = 0; j < E; j++) {
        scanf("%d %d", &u, &v);
        addLink(u, v);
    }
    printgraph();
    for (int i = 0; i < V; i++) 
        free(graph[i]);
    free(graph);
}