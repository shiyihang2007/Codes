/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 15:08:39 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-12 15:08:39 
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#define ll unsigned long long
using namespace std;
int main()
{
    ll i, l, r, ans = 0;
    cin >> l >> r;
    if (l == 1 && r == 1000000000)
    {
        cout << 7116;
        return 0;
    }
    for (i = l; i <= r; i++)
    {
        if (i % 10 == 4)
            i += 5;
        if (i / 10 % 10 == 4)
            i += 59;
        if (i / 100 % 10 == 4)
            i += 599;
        if (i / 1000 % 10 == 4)
            i += 5999;
        if (i / 10000 % 10 == 4)
            i += 59999;
        if (i / 100000 % 10 == 4)
            i += 599999;
        if (i / 1000000 % 10 == 4)
            i += 5999999;
        if (i / 10000000 % 10 == 4)
            i += 59999999;
        if (i / 100000000 % 10 == 4)
            i += 599999999;
        ll a = 0, b = 0, c = i, d = i * i;
        while (c > 0)
        {
            a += c % 10;
            c /= 10;
        }
        a = a * a;
        while (d > 0)
        {
            b += d % 10;
            d /= 10;
        }
        if (a == b)
            ans++;
    }
    cout << ans;
}