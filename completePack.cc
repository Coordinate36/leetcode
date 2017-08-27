#include <iostream>
#include <cstring>
using namespace std;

/*int maxWorth(int N, int V, int C[], int W[]) {
    int dp[N + 1][V + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; ++i) {
        for (int v = C[i]; v <= V; ++v) {
            dp[i][v] = max(dp[i - 1][v], dp[i][v - C[i]] + W[i]);
            cout << dp[i][v] << " ";
        }
        cout << endl;
    }
    return dp[N][V];
}*/
// dp[i][v] = max{dp[i - 1][v - k * C[i]] + k * W[i] | 0 <= k * C[i] <= v};
// 但当dp[i][v] = dp[i - 1][v - k * C[i]] + k * W[i]最大时，dp[i][v - C[i]]不一定等于dp[i - 1][v - (k - 1) * C[i]] + (k - 1) * W[i]，可能腾出2+个C[i]的空间可以装下等空间下价格更大的物品。


int modifiedMaxWorth(int N, int V, int C[], int W[]) {
    int dp[V + 1];  // dp[v]代表这N件物品放入容量为v的背包中最大价值
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; ++i) {
        for (int v = C[i]; v <= V; ++v) {
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

