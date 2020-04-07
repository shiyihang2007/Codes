/*
 * @Author: shiyihang 
 * @Date: 2020-03-12 15:34:02 
 * @Last Modified by: shiyihang
 * @Last Modified time: 2020-03-12 15:37:49
 */
#include <bits/stdc++.h>
using namespace std;
long long N;
long long O, I2;
long long n, sum, i;
long long maxs;
string s, ss;
int main()
{
    cin >> n;
    cin >> s;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'I')
            I2++;
    }
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'N')
            N++;
        if (s[i] == 'O')
            sum += N * I2;
        if (s[i] == 'I')
            I2--;
        maxs = max(maxs, N * I2);
    }
    long long mmax = sum + maxs;

    n++;
    ss = s;
    s = 'N' + ss;
    sum = 0;
    N = 0;
    I2 = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'I')
            I2++;
    }
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'N')
            N++;
        if (s[i] == 'O')
            sum += N * I2;
        if (s[i] == 'I')
            I2--;
    }
    mmax = max(mmax, sum);
    s = ss + 'I';
    sum = 0;
    N = 0;
    I2 = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'I')
            I2++;
    }
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'N')
            N++;
        if (s[i] == 'O')
            sum += N * I2;
        if (s[i] == 'I')
            I2--;
    }
    mmax = max(mmax, sum);
    //cout<<sum<<endl;
    cout << mmax;
    return 0;
}