/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 15:39:33 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-12 15:39:33 
 */
#include <bits/stdc++.h>
#define REP(A, B, I) for (int I = (A); I <= (B); I++)
#define PER(A, B, I) for (int I = (A); I >= (B); I--)
#define LL long long
#define N 1000010
#define M 100
#define mod 1000000007
using namespace std;
long long quickmul(long long a, long long b)
{
    a %= mod;
    b %= mod;
    long long c = (long long)a * b / mod;
    long long ans = a * b - c * mod;
    if (ans < 0)
        ans += mod;
    else if (ans >= mod)
        ans -= mod;
    return ans;
}
long long quickpow(long long a, long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
long long n;
int main()
{
    //read(1)
    //write(1)
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long ans1 = 1, ans2 = 1, ans3 = 1, fina = 1;
    REP(1, 2 * n, i)
    {
        if (i <= n)
            ans2 = quickmul(ans2, i);
        if (i <= n + 1)
            ans3 = quickmul(ans3, i);
        ans1 = quickmul(ans1, i);
    }
    ans2 = quickmul(ans2, ans3);
    fina = quickmul(ans1, quickpow(ans2, mod - 2));
    cout << fina << endl;
    return 0;
}