#include <iostream>
#include <climits>
using namespace std;
int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    int graph[100][100];
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    int parent[100];
    int key[100];
    bool visited[100];
    // Initialize
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    // Prim's Algorithm
    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX;
        int u = -1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    int totalCost = 0;
    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "Total cost of MST = " << totalCost << endl;
    return 0;
}
