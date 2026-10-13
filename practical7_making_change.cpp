#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
    int n, amount;
    cout << "Enter number of coin denominations: ";
    cin >> n;
    int coins[100];
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    cout << "Enter amount: ";
    cin >> amount;
    int dp[1000];
    dp[0] = 0;
    // Initialize
    for (int i = 1; i <= amount; i++)
        dp[i] = INT_MAX;
    // Calculate minimum coins
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i],
                            1 + dp[i - coins[j]]);
            }
        }
    }
    if (dp[amount] == INT_MAX)
        cout << "Amount cannot be formed using given coins.";
    else
        cout << "Minimum number of coins = "
             << dp[amount] << endl;
    return 0;
}
