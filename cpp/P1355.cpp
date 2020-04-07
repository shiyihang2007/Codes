/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 15:04:52 
 * @Last Modified by: shiyihang
 * @Last Modified time: 2020-03-12 15:06:49
 */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

inline int read()
{
    int x = 0, f = 0;
    char s = getchar();
    while (!isdigit(s))
        f |= s == '-', s = getchar();
    while (isdigit(s))
        x = (x << 1) + (x << 3) + (s - 48), s = getchar();
    return f ? -x : x;
}
struct point
{
    int x, y;
} p[11];

inline int mul(point p1, point p2, point p0)
{
    int x1 = p1.x - p0.x, y1 = p1.y - p0.y;
    int x2 = p2.x - p0.x, y2 = p2.y - p0.y;
    return x1 * y2 - x2 * y1;
}

int main()
{
    for (int i = 1; i <= 3; i++)
        p[i].x = read(), p[i].y = read();
    p[0].x = read(), p[0].y = read();
    int tt;
    tt = 0;
    for (int i = 1; i <= 3; i++)
        if (p[0].x == p[i].x && p[0].y == p[i].y)
        {
            tt = i;
            break;
        }
    if (tt != 0)
    {
        printf("4\n");
        return 0;
    }
    if (mul(p[2], p[0], p[1]) * mul(p[0], p[3], p[1]) >= 0 &&
        mul(p[1], p[0], p[2]) * mul(p[0], p[3], p[2]) >= 0 &&
        mul(p[1], p[0], p[3]) * mul(p[0], p[2], p[3]) >= 0)
    {
        for (int i = 1; i <= 3; i++)
        {
            tt = i + 1;
            if (tt == 4)
                tt = 1;
            if (mul(p[i], p[tt], p[0]) == 0)
            {
                printf("3\n");
                return 0;
            }
        }
        printf("1\n");
        return 0;
    }
    printf("2\n");
    return 0;
    return 0;
}