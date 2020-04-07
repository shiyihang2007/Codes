/*
 * @Author: shiyihang 
 * @Date: 2020-03-19 16:24:36 
 * @Last Modified by: shiyihang
 * @Last Modified time: 2020-03-19 16:25:20
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << a[0] << " " << a[1] << " " << a[2];
}