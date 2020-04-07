/*
 * @Author: shiyihang 
 * @Date: 2020-03-23 16:50:51 
 * @Last Modified by: shiyihang
 * @Last Modified time: 2020-03-23 16:51:22
 */
#include <bits/stdc++.h>
using namespace std;
int n, m, r, ans, dx[2] = {0, 1}, dy[2] = {1, 0};
char mp[105][105];
void dfs(int x, int y, int i, int j)
{
    if (j > r)
    {
        ++ans;
        return;
    }
    if (mp[x][y] != '.' || x < 0 || y < 0 || x >= n || y >= m)
        return;
    dfs(x + dx[i], y + dy[i], i, j + 1);
    return;
}
int main()
{
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
        cin >> mp[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mp[i][j] == '.')
                for (int k = 0; k < 2; k++)
                    dfs(i, j, k, 1);
    if (r == 1)
        ans /= 2;
    cout << ans << endl;
    return 0;
}