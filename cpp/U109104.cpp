#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int main()
{
    int n, a[1005] = {}, s[1005];
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i] = q.front();
        q.pop();
        for (int j = 1; j <= i; ++j)
        {
            q.push(q.front());
            q.pop();
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        s[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << s[i] << " ";
    }
}