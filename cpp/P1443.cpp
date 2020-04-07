/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 15:52:26 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-12 15:52:26 
 */
#include <cmath>
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
struct xy
{
    int x, y;
} node, Top;
const int dx[4] = {1, -1, 2, -2};
const int dy[4] = {1, -1, 2, -2};
int a[401][401];
bool b[401][401];
int n, m;
void bfs(int x, int y, int step)
{
    a[x][y] = step;
    b[x][y] = false;
    queue<xy> Q;
    node.x = x;
    node.y = y;
    Q.push(node);
    while (!Q.empty())
    {
        Top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (abs(dx[i]) != abs(dy[j]))
                {
                    int NewX = Top.x + dx[i];
                    int NewY = Top.y + dy[j];
                    if (NewX < 1 || NewX > n || NewY < 1 || NewY > m)
                        continue;
                    if (b[NewX][NewY])
                    {
                        node.x = NewX;
                        node.y = NewY;
                        Q.push(node);
                        b[NewX][NewY] = false;
                        a[NewX][NewY] = a[Top.x][Top.y] + 1;
                    }
                }
    }
}
int main()
{
    memset(b, true, sizeof(b));
    memset(a, -1, sizeof(a));
    int x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    bfs(x, y, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%-5d", a[i][j]);
        printf("\n");
    }
    return 0;
}