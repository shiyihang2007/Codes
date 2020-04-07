/*
 * @Author: shiyihang 
 * @Date: 2020-03-19 16:07:24 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-19 16:07:24 
 */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int x;
bool a, b;
int main()
{
    scanf("%d", &x);
    a = !(x & 1), b = (x > 4 && x <= 12);
    printf("%d %d %d %d", a & b, a | b, (a && !b || b && !a), !a && !b);
}