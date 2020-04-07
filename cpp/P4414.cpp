/*
 * @Author: shiyihang 
 * @Date: 2020-03-19 16:45:08 
 * @Last Modified by:   shiyihang 
 * @Last Modified time: 2020-03-19 16:45:08 
 */
#include <algorithm>
#include <iostream>
using namespace std;
int a[3];
char A, B, C;
int main()
{
    cin >> a[0] >> a[1] >> a[2];
    cin >> A >> B >> C;
    sort(a, a + 3);
    cout << a[A - 'A'] << " " << a[B - 'A'] << " " << a[C - 'A'];
    return 0;
}