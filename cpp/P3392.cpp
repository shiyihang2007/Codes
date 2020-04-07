#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0x3f3f3f3f, c[55][4], b[55][55];
void dfs(int x, int y, int t)
{
    if (x + y >= n || b[x][y])
        return;
    b[x][y] = 1;
    dfs(x + 1, y, t + c[x + 1][1]);
    dfs(x, y + 1, t + c[n - y][3]);
    if (x > 0 && y > 0 && x + y < n)
    {
        int s = 0;
        for (int i = x + 1; i <= n - y; ++i)
            s += c[i][2];
        ans = min(ans, t + s);
    }
}
int main()
{
    int ch;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            do
                ch = getchar();
            while (int(ch) < 65);
            if (ch == 'W')
                c[i][2]++, c[i][3]++;
            if (ch == 'B')
                c[i][1]++, c[i][3]++;
            if (ch == 'R')
                c[i][1]++, c[i][2]++;
        }
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}