/*
 * @Author: shiyihang 
 * @Date: 2020-03-14 20:01:49 
 * @Last Modified by: shiyihang
 * @Last Modified time: 2020-03-14 20:08:42
 */
#include <stdio.h>
#define N 1050017
int max(int x, int y)
{
    int M;
    M = x > y ? x : y;
    return M;
}
int w[N], v[N], f[N],t[N],c[N];
int main()
{
    int  n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d%d", &c[i], &t[i], &v[i], &w[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= 0;j--){
            if(j>=t[i])
                f[j] = max(f[j], f[j - t[i]] + c[i]);
            if(j>=w[i])
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}