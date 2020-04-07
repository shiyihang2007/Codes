#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char W[15][10][10] =
    {
        {"XXX ",
         "X.X ",
         "X.X",
         "X.X",
         "XXX"},
        {"..X",
         "..X",
         "..X",
         "..X",
         "..X"},
        {"XXX",
         "..X",
         "XXX",
         "X..",
         "XXX"},
        {"XXX",
         "..X",
         "XXX",
         "..X",
         "XXX"},
        {"X.X",
         "X.X",
         "XXX",
         "..X",
         "..X"},
        {"XXX",
         "X..",
         "XXX",
         "..X",
         "XXX"},
        {"XXX",
         "X..",
         "XXX",
         "X.X",
         "XXX"},
        {"XXX",
         "..X",
         "..X",
         "..X",
         "..X"},
        {"XXX",
         "X.X",
         "XXX",
         "X.X",
         "XXX"},
        {"XXX",
         "X.X",
         "XXX",
         "..X",
         "XXX"}};
int n;
char s[110];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << W[s[j] - '0'][i][k];
            }
            if (j != n - 1)
                cout << '.';
        }
        cout << endl;
    }
    return 0;
}