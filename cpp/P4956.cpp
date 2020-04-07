#include <bits/stdc++.h>
using namespace std;
#define work()                                     \
    int n;                                         \
    cin >> n;                                      \
    for (int k = 1; k <= n; ++k)                   \
        for (int x = 1; x <= 100; ++x)             \
            if (x * 7 * 52 + k * 21 * 52 == n)     \
            {                                      \
                cout << x << "\n";                 \
                cout << k;                         \
                return 0;                          \
            }                                      \
            else if (x * 7 * 52 + k * 21 * 52 > n) \
                break;                             
int main()
{
    work();
}