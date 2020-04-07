#include <cstdio>
#include <iostream>
using namespace std;
int n, len[25], num[25];
string s[25];
bool pd(int x, int y)
{
    int i = num[x], j = num[y];
    while (i < len[x] && j < len[y])
    {
        if (s[x][i] < s[y][j])
            return true;
        else if (s[x][i] > s[y][j])
            return false;
        ++i, ++j;
    }
    if (j == len[y])
        return true;
    else
        return false;
}
int main()
{
    while (cin >> s[++n])
        len[n] = s[n].length();
    while (1)
    {
        int f = 0, d;
        for (int i=1; i <= n; ++i)
            if (num[i] < len[i])
                if (!f || pd(i, d))
                    d = i, f = 1;
        printf("%c", s[d][num[d]]);
        num[d]++;
        int p = 0;
        for (int i=1; i <= n; ++i)
            if (num[i] < len[i])
                p = 1;
        if (!p)
            break;
    }
}
