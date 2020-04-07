#include <bits/stdc++.h>
using namespace std;
int pd(int n)
{
    if (n < 2)
        return -1;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int n, s(0), k(0);
    cin >> n;
    for (int i = 2; 1; ++i)
    {
        if (pd(i) && s + i <= n)
            s += i, ++k, printf("%d\n", i);
        if (s + i > n)
            break;
    }
    cout << k;
    return 0;
}