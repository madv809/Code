#define ll long long
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int INF = 3000001;
int dp[101][30000*100 + 1], a[101], b[101], ans, k, n;
bool vist[101][30000*100 + 1];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    for (int i = 1; i <= n; ++i)
    {
        k = 30000*i;
        for (int j = 0; j <= k; ++j) dp[i][j] = INF;
    }
    dp[1][a[1]] = 0;
    vist[1][a[1]] = 1;
    dp[1][0] = min(dp[1][0], b[1]);
    vist[1][0] = 1;
    for (int i = 1; i < n; ++i)
    {
        k = 30000*i;
        for (int j = 0; j <= k; ++j) if (vist[i][j])
        {
            dp[i + 1][j + a[i + 1]] = min(dp[i + 1][j + a[i + 1]], dp[i][j]);
            vist[i + 1][j + a[i + 1]] = 1;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b[i + 1]);
            vist[i + 1][j] = 1;
        }
    }
    ans = INF;
    for (int j = 0; j < ans; ++j) if ((vist[n][j]) && (max(j, dp[n][j]) < ans)) ans = max(j, dp[n][j]);
    printf("%d", ans);
}
