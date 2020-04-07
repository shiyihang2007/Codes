/*
 * @Author: shiyihang 
 * @Date: 2020-03-11 18:08:33 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-11 18:08:33 
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int r, c;
char map[1010][1010];
int fx[4] = {0, -1, 1, 0};
int fy[4] = {-1, 0, 0, 1};
int dfs(int x, int y)
{
    map[x][y] = '*';
    for (int i = 0; i < 4; i++)
    {
        if (x + fx[i] > 0 && x + fx[i] <= r && y + fy[i] > 0 && y + fy[i] <= c &&
            map[x + fx[i]][y + fy[i]] == '#')
            dfs(x + fx[i], y + fy[i]);
    }
} 
bool d(int i, int j)
{
    int c = 0;
    if (map[i][j] == '#')
        c++;
    if (map[i + 1][j] == '#')
        c++;
    if (map[i][j + 1] == '#')
        c++;
    if (map[i + 1][j + 1] == '#')
        c++;
    if (c == 3)
        return 0;
    return 1;
} 
int main()
{
    scanf("%d%d", &r, &c);
    register int i, j;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            cin >> map[i][j];
        }
    }
    int s = 0;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (i < r && j < c && d(i, j) == 0)
            {
                printf("Bad placement.");
                return 0; 
            }
        }
    }
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (map[i][j] == '#')
            {
                s++;
                dfs(i, j);
            } 
        }
    }
    printf("There are %d ships.", s);
    return 0;
}