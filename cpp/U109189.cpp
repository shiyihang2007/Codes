#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
using namespace std;
inline int read()
{
    int res = 0, f = 1;
    char ch;
    for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-')
            f = false;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        res = (res << 1) + (res << 3) + (ch ^ 48);
    return f ? res : -res;
}
int main()
{
    int n, a[2005], ans(0), k(0);
    n = read();
    for (register int i(1); i <= n; ++i)
        a[i] = read();
    for (register int i(1); i <= n; ++i)
        for (register int j(i + 1); j <= n; ++j)
            for (register int k(j + 1); k <= n; ++k)
                ans += (a[i] + a[j] < a[k]) + (a[i] + a[k] < a[j]) + (a[j] + a[k] < a[i]);
    cout << ans;
}
