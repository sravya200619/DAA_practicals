#include <iostream>
#include <climits>
using namespace std;
int n;
int cost[20][20];
bool visited[20];
int minCost = INT_MAX;
void TSP(int current, int count, int totalCost) {
    // All cities visited
    if (count == n) {
        // Return to starting city
        int finalCost = totalCost + cost[current][0];
        if (finalCost < minCost)
            minCost = finalCost;
        return;
    }
    // Visit unvisited cities
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            TSP(i,
                count + 1,
                totalCost + cost[current][i]);
            visited[i] = false;
        }
    }
}
int main() {
    cout << "Enter number of cities: ";
    cin >> n;
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    // Start from city 0
    visited[0] = true;
    TSP(0, 1, 0);
    cout << "\nMinimum travelling cost = "
         << minCost << endl;
    return 0;
}
