/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 15:50:19 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-12 15:50:19 
 */
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 330;
int read()
{
    int x = 0, f = 0;
    char ch = 0;
    while (!isdigit(ch))
        f |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        (x *= 10) += (ch ^ 48), ch = getchar();
    return f ? -x : x;
}
int n, m, tot;
bool flag[MAXN];
int head[MAXN];
struct Edge
{
    int v;
    int nxt;
} edge[MAXN * MAXN];
struct Vil
{
    int high;
    int _id;
    bool operator<(const Vil &rhs) const
    {
        return high > rhs.high;
    }
} vill[MAXN];
bool cmp(Vil a, Vil b)
{
    return a._id < b._id;
}
void addedge(int u, int v)
{
    edge[++tot] = (Edge){
        v, head[u]};
    head[u] = tot;
}

void dfs(int x)
{
    flag[x] = 1; //标记该点已经来过
    for (int i = head[x]; i; i = edge[i].nxt)
        dfs(edge[i].v);
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        vill[i].high = read(), vill[i]._id = i;

    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read();
        if (vill[a].high > vill[b].high)
            addedge(a, b);
        else if (vill[a].high < vill[b].high)
            addedge(b, a);
    }

    sort(vill + 1, vill + n + 1);
    int s = vill[1]._id;
    sort(vill + 1, vill + n + 1, cmp);
    dfs(s);
    for (int i = 1; i <= n; i++)
        if (!flag[i])
            return printf("Non\n"), 0;
    printf("Oui, j'ai trouve la solution.\n%d\n", s);
    return 0;
}