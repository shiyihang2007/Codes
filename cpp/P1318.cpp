/*
 * @Author: shiyihang 
 * @Date: 2020-03-11 18:02:20 
 * @Last Modified by: shiyihang
 * @Last Modified time: 2020-03-11 18:02:55
 */
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

int n, h;
int x[10002][5002], maxx = -1;
int ans = 0;
int flag1, flag2;

void left(int a)
{
    int b = 1;
    while (a - b > 0)
    {
        if (x[a - b][maxx] > x[a][maxx])
        {
            flag1 = 1;
            return;
        }
        b++;
    }
    flag1 = 0;
}

void right(int a)
{
    int b = 1;
    while (a + b < n)
    {
        if (x[a + b][maxx] > x[a][maxx])
        {
            flag2 = 1;
            return;
        }
        b++;
    }
    flag2 = 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> h;
        if (h == 0)
            continue;
        for (int j = 1; j <= h; j++)
            x[i][j] = 1;
        if (h > maxx) maxx = h;
    }
    while (maxx > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (x[i][maxx] == 1)
                continue;
            left(i);
            right(i);
            if (flag1 == 1 && flag2 == 1)
                ans++;
        }
        maxx--;
    }
    printf("%d", ans);
    return 0;
}