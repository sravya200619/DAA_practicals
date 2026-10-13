#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    int p[100];
    cout << "Enter dimensions of matrices: ";
    cout << "\nFor n matrices, enter n+1 dimensions: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];
    int m[100][100];
    // Cost of multiplying one matrix is zero
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    // Chain length
    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k]
                         + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }
    cout << "Minimum number of scalar multiplications = "
         << m[1][n] << endl;
    return 0;
}
