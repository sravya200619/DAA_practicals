#include <iostream>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, weight;
};
int parent[100];
// Find parent of a vertex
int findParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}
// Union two sets
void unionSet(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b)
        parent[b] = a;
}
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Edge edges[100];
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }
    // Sort edges by weight
    sort(edges, edges + E, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });
    // Initialize parent
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int totalCost = 0;
    int count = 0;
    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (findParent(u) != findParent(v)) {
            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;
            totalCost += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }
    cout << "Total cost of MST = "
         << totalCost << endl;
    return 0;
}
