/*
 * @Author: shiyihang 
 * @Date: 2020-03-19 16:12:39 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-19 16:12:39 
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    cout << ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) ? 1 : 0;
    return 0;
}