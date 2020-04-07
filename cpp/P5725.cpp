#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    k = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%02d", ++k);
        }
        puts("");
    }
    k = 0;
    puts("");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n - i; ++j)
        {
            printf("  ");
        }
        for (int j = 1; j <= i; ++j)
        {
            printf("%02d", ++k);
        }
        puts("");
    }
}