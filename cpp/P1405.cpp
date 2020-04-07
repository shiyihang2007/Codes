/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 16:02:12 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-12 16:02:12 
 */
#include <bits/stdc++.h>
using namespace std;
long long n;
long long ask(long long m)
{
    long long anss = m;
    for (long long i = 2; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            anss = anss / i * (i - 1);
            while (m % i == 0)
                m /= i;
        }
    }
    if (m > 1)
        anss = anss / m * (m - 1);
    return anss;
}
long long a[10001000];
long long power(long long x, long long y, long long mod)
{
    long long anss = 1, res = x;
    while (y)
    {
        if (y % 2)
            anss = anss * res % mod;
        res = res * res % mod;
        y >>= 1;
    }
    return anss;
}
long long gcd(long long aa, long long bb)
{
    if (bb == 0)
        return aa;
    return gcd(bb, aa % bb);
}
long long dfs(long long x, long long mod)
{
    if (x == n)
    {
        return a[x] = a[x] % mod;
    }
    long long kkk = ask(mod);
    long long kk = dfs(x + 1, kkk);
    if (gcd(a[x], mod) == 1)
        return a[x] = power(a[x], kk, mod);
    else
    {
        if (a[x + 1] > kkk)
            return a[x] = power(a[x], kk + kkk, mod);
        return a[x] = power(a[x], a[x + 1], mod);
    }
}
int main()
{
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    printf("%lld\n", dfs(1, 10007));
    return 0;
}