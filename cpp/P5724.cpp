#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, minn(1000), maxx(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        minn = min(a, minn);
        maxx = max(maxx, a);
    }
    cout << maxx - minn;
}