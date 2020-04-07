/*
 * @Author: shiyihang 
 * @Date: 2020-03-14 17:11:58 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-14 17:11:58 
 */
#include <cstdio>
using namespace std;
long long X, Y, A, B;
inline long long min(long long x, long long y) { return x < y ? x : y; }
int main()
{
    while (scanf("%lld%lld%lld%lld", &X, &Y, &A, &B) != EOF)
    {
        A = min(X, A);
        B = min(Y, B);
        if (A == 0)
            printf("%lld\n", B);
        else if (B == 0)
            printf("%lld\n", A);
        else if ((X + 1) * B < Y)
            printf("%lld\n", (X + 1) * B + X);
        else if ((Y + 1) * A < X)
            printf("%lld\n", (Y + 1) * A + Y);
        else
            printf("%lld\n", X + Y);
    }
    return 0;
}