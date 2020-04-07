/*
 * @Author: shiyihang 
 * @Date: 2020-03-19 16:58:32 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-19 16:58:32 
 */
#include <iostream>
#include <stdio.h>
using namespace std;
int n, k, sum;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = k; i <= n; i += k)
        sum += i;
    printf("%.1f ", double(sum) / (n / k));
    sum = (1 + n) * n / 2 - sum;
    printf("%.1f\n", double(sum) / (n - n / k));
    return 0;
}