#include <cstdio>
#include <iostream>
using namespace std;
long a[10001][10001];
int n;
int ans = 1, i, j;
int main()
{
    cin >> n;
    i = 1, j = n / 2 + 1;
    while (ans <= n * n)
    {
        a[i][j] = ans;
        if (ans % n == 0 && ++i)
        {
            if (i == n + 1)
                i = 1;
        }
        else
            --i, ++j;
        if (i == 0)
            i = n;
        if (j == n + 1)
            j = 1;
        ++ans;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}