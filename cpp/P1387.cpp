/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 15:41:17 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-12 15:41:17 
 */
#include <cstdio>
#include <iostream>
using namespace std;
int a[101][101], n, m, f[101][101], ans;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
                f[i][j] = min(min(f[i][j - 1], f[i - 1][j]), f[i - 1][j - 1]) + 1;
            ans = max(ans, f[i][j]);
        }
    printf("%d", ans);
}