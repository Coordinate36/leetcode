#include <iostream>
#include <cstring>
using namespace std;

int maxWorth(int N, int V, int C[], int W[]) {
    int dp[N + 1][V + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; ++i) {
        for (int v = V; v >= C[i]; --v) {
            dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - C[i]] + W[i]);
            cout << dp[i][v] << " ";
        }
        cout << endl;
    }
    return dp[N][V];
}

int modifiedMaxWorth(int N, int V, int C[], int W[]) {
    int dp[V + 1];  // dp[v]代表这N件物品放入容量为v的背包中最大价值
    for (int i = 0; i <= V; ++i) {
        dp[i] = 0;
    }
    for (int i = 1; i <= N; ++i) {
        for (int v = V; v >= C[i]; --v) {
            dp[v] = max(dp[v], dp[v - C[i]] + W[i]);
        }
    }
    return dp[V];
}

int main()
{
    int C[] = {0, 2, 4, 3, 5, 8};
    int W[] = {0, 2, 5, 3, 6, 10};
    cout << maxWorth(5, 14, C, W) << endl;
    cout << modifiedMaxWorth(5, 14, C, W) << endl;
    return 0;
}

