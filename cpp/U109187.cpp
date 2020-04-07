/*
 * @Author: shiyihang 
 * @Date: 2020-03-15 15:28:37 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-15 15:28:37 
 */
#include <cstdio>
#include <iostream>
using namespace std;
const int INF = 30;
long long n, vis[INF], m, data[INF][INF], ans = 1000;
int ans1[INF], ans11[INF];
inline bool check()
{
    for (int i = 1; i <= n; i++)
        if (vis[i] > 0)
            return false;
    return true;
}
inline void DFS(int k, int sum)
{
    if (k > m && check())
    {
        if (ans > sum)
        {
            for (int i = 1; i <= sum; i++)
                ans11[i] = ans1[i];
            ans = sum;
            return;
        }
        return;
    }
    if (k > m)
        return;
    for (int i = 1; i <= n; i++)
        vis[i] = vis[i] - data[k][i];
    ans1[sum + 1] = k;
    DFS(k + 1, sum + 1);
    for (int i = 1; i <= n; i++)
        vis[i] = vis[i] + data[k][i];
    ans1[sum + 1] = 0;
    DFS(k + 1, sum);
    return;
}
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &vis[i]);
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld", &data[i][j]);
    DFS(1, 0);
    printf("%lld", ans == 1000 ? 0 : ans);
    for (int i = 1; i <= ans; i++)
        printf(" %d", ans11[i]);
    return 0;
}