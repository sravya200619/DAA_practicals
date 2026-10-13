#include <iostream>
#include <queue>
using namespace std;
int graph[100][100];
bool visited[100];
int n;
// DFS
void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i])
            DFS(i);
    }
}
// BFS
void BFS(int start) {
    bool visitedBFS[100] = {false};
    queue<int> q;
    visitedBFS[start] = true;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visitedBFS[i]) {
                visitedBFS[i] = true;
                q.push(i);
            }
        }
    }
}
int main() {
    int edges, u, v, start;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> edges;
    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;   // Undirected graph
    }
    cout << "Enter starting vertex: ";
    cin >> start;
    cout << "\nDFS Traversal: ";
    for (int i = 0; i < n; i++)
        visited[i] = false;
    DFS(start);
    cout << "\nBFS Traversal: ";
    BFS(start);

    return 0;
}
