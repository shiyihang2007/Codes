#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, s(0), maxx(0), minn(10);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        s += a;
        maxx = max(maxx, a);
        minn = min(minn, a);
    }
    printf("%.2f",(s - maxx - minn) / (float)(n-2));
    return 0;
}