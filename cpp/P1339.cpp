/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 14:52:35 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-12 14:52:35 
 */
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int const N = 100001, INF = 1e9;
int tot, n, m, s, t, f[N],
    target[N], prev[N], last[N], v[N];
void add(int a, int b, int c)
{
    target[++tot] = b;
    prev[tot] = last[a];
    last[a] = tot;
    v[tot] = c;
}
int main()
{
    int a, b, c;
    queue<int> qu;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    for (int i = 1; i <= n; i++)
        f[i] = INF;

    f[s] = 0;
    qu.push(s);
    while (qu.size())
    {
        int x = qu.front(), ptr = last[x];
        qu.pop();
        while (ptr)
        {
            int y = target[ptr];
            if (f[x] + v[ptr] < f[y])
            {
                f[y] = f[x] + v[ptr];
                qu.push(y);
            }
            ptr = prev[ptr];
        }
    }
    printf("%d\n", f[t]);
    return 0;
}