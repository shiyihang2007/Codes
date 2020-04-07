/*
 * @Author: shiyihang 
 * @Date: 2020-03-19 16:01:13 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-19 16:01:13 
 */
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (b == 0)
        cout << a << endl;
    else
        cout << a - min(int(a), int(ceil(c / b))) << endl;
    return 0;
}