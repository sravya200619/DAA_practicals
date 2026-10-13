#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    int weight[100], profit[100];
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter profits: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    cout << "Enter knapsack capacity: ";
    cin >> W;
    int K[101][101];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(
                    profit[i - 1] + K[i - 1][w - weight[i - 1]],
                    K[i - 1][w]
                );
            else
                K[i][w] = K[i - 1][w];
        }
    }
    cout << "Maximum Profit = " << K[n][W] << endl;
    return 0;
}
