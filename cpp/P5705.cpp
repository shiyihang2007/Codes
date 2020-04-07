/*
 * @Author: shiyihang 
 * @Date: 2020-03-19 15:53:04 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-19 15:53:04 
 */
#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
    cin >> a;
    int len = a.size();
    for (int i = len - 1; i >= 0; i--)
        cout << a[i];
    return 0;
}