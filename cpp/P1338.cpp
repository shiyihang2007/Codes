/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 14:49:04 
 * @Last Modified by: shiyihang
 * @Last Modified time: 2020-03-12 14:49:32
 */
#include <cstdio>
#include <vector>
using namespace std;
long long n, m, s, i, j, k;
bool use[50005];
int main()
{
    scanf("%lld %lld", &n, &m);
    s = (n * (n - 1)) >> 1;
    for (i = 1; i <= n; i++)
    {
        s -= (n - i);
        if (m > s)
        {
            printf("%lld ", i + m - s);
            use[i + m - s] = true;
            break;
        }
        printf("%lld ", i);
        use[i] = true;
    }
    for (j = n, k = n; j > i; j--, k--)
    {
        if (use[k])
        {
            j++;
            continue;
        }
        printf("%lld ", k);
    }
    return 0;
}