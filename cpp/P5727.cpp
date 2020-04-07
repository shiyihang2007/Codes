/*
 * @Author: shiyihang 
 * @Date: 2020-03-19 17:01:36 
 * @Last Modified by: shiyihang
 * @Last Modified time: 2020-03-19 17:04:47
 */
#include <bits/stdc++.h>
using namespace std;
void function(int n)
{
    if (n == 1)
    {
        cout << 1;
        return;
    }
    if (n % 2)
        function(n * 3 + 1);
    else
        function(n / 2);
    cout << " " << n;
}
int main()
{
    int n;
    cin >> n;
    function(n);
    return 0;
}