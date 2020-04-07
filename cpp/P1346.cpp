/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 14:54:15 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-12 14:54:15 
 */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100 + 10;
const int inf = 1e+8;
int g[maxn][maxn];
int n, m, k, f, t;
int main()
{
    scanf("%d%d%d", &n, &f, &t);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = inf;
            g[i][i] = 0;
        }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        for (int j = 1; j <= k; j++)
        {
            int a;
            scanf("%d", &a);
            if (j == 1)
                g[i][a] = 0;
            else
                g[i][a] = 1;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    if (g[f][t] == inf)
        puts("-1");
    else
        printf("%d", g[f][t]);
}