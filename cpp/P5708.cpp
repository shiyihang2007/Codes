/*
 * @Author: shiyihang 
 * @Date: 2020-03-19 15:59:48 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-19 15:59:48 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c, p;
    scanf("%lf %lf %lf", &a, &b, &c);
    p = (a + b + c) / 2.0;
    printf("%.1lf", sqrt(p * (p - a) * (p - b) * (p - c)));
    return 0;
}