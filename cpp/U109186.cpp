/*
 * @Author: shiyihang 
 * @Date: 2020-03-14 10:43:46 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-14 10:43:46 
 */
#include <map>
#include <math.h>
#include <stdio.h>
using namespace std;
int a[2][10] = {{0, 1, 2, 3, 1, 0, 1, 2, 3, 1},
                {0, 0, 0, 0, 1, 1, 1, 1, 1, 0}};
int main()
{
    map<char, int> m; //记录出现的次数
    map<int, char> n; //记录顺序
    int t, i, j, k, k1;
    while (~scanf("%d", &t))
    {
        m['I'] = 0;
        m['V'] = 0;
        m['X'] = 0;
        m['L'] = 0;
        m['C'] = 0;
        m['D'] = 0;
        m['M'] = 0;
        n[1] = 'I';
        n[2] = 'V';
        n[3] = 'X';
        n[4] = 'L';
        n[5] = 'C';
        n[6] = 'D';
        n[7] = 'M';
        for (i = 1; i <= t; i++)
        {
            k1 = i;
            k = (int)log10(i) + 1;
            if (k > 3)
            {
                m['M'] += a[0][i / 1000];
                k1 -= i / 1000 * 1000;
                j = k1;
            }
            else
                j = k1;
            if (j >= 100 && j < 1000)
            {
                m['C'] += a[0][j / 100];
                m['D'] += a[1][j / 100];
                if (j > 900 && j < 1000)
                    m['M']++;
                j -= j / 100 * 100;
            }
            m['I'] += a[0][j % 10];
            m['V'] += a[1][j % 10];
            if (j >= 10 && j < 100)
            {
                if (j % 10 == 9)
                    m['X']++;
                m['X'] += a[0][j / 10];
                m['L'] += a[1][j / 10];
                if (j > 90)
                    m['C']++;
            }
            if (j == 9)
                m['X']++;
            if (j == 90)
                m['C']++;
            if (i == 900 || i == 1999 || i == 2900)
                m['M']++;
        }
        for (i = 1; i <= 7; i++)
        {
            if (m[n[i]] != 0)
                printf("%c %d\n", n[i], m[n[i]]);
        }
    }
    return 0;
}
