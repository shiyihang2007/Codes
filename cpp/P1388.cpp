/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 15:45:45 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-12 15:45:45 
 */
#include <algorithm>
#include <cstdio>
using namespace std;
int dp[16][16], n, i, j, k, l, a[16], sum[17];
int main()
{
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        dp[i][0] = sum[i] = sum[i - 1] + a[i];
        dp[1][i] = a[i];
    }
    for (i = 2; i <= n; i++)
        for (j = 1; j <= min(k, i - 1); j++)
            for (l = j; l <= i - 1; l++)
                dp[i][j] = max(dp[i][j], dp[l][j - 1] * (sum[i] - sum[l]));
    printf("%d", dp[n][k]);
    return 0;
}