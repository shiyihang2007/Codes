#include <bits/stdc++.h>
using namespace std;
int n, a[15], b[15];
void print()
{
    for (int i = 1; i <= n; ++i)
        printf("%5d", a[i]);
    puts("");
}
void dfs(int d)
{
    if (d > n)
    {
        print();
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!b[i])
        {
            b[i] = 1;
            a[d] = i;
            dfs(d + 1);
            b[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}