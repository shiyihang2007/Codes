/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 15:55:27 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-12 15:55:27 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int dp1[5001], dp2[5001];
char str1[5001], str2[5001];
int main()
{
    scanf("%s", str1 + 1);
    n = strlen(str1 + 1);
    for (int i = 1; i <= n; i++)
        str2[i] = str1[n - i + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (str1[i] == str2[j])
                dp1[j] = dp2[j - 1] + 1;
            else
                dp1[j] = max(dp1[j - 1], dp2[j]);
        memcpy(dp2, dp1, sizeof(dp1));
    }
    printf("%d\n", n - dp1[n]);
    return 0;
}