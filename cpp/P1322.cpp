/*
 * @Author: shiyihang 
 * @Date: 2020-03-11 18:04:25 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-11 18:04:25 
 */
#include <bits/stdc++.h>
using namespace std;
int dg()
{
    string s;
    char c;
    int k, l = 0, v;
    while (cin >> c)
    {
        if (c == ']')
            break;
        cin >> s >> k;
        if (c == 'R')
        {
            v = getchar();
            l += k * dg();
            v = getchar();
        }
        if (c == 'B')
            v = getchar(), l -= k;
        if (c == 'F')
            v = getchar(), l += k;
        if (v == int(']'))
            break;
    }
    return l;
}
int main()
{
    cout << abs(dg());
    return 0;
}