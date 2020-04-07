/*
 * @Author: shiyihang 
 * @Date: 2020-03-19 16:22:43 
 * @Last Modified by: shiyihang
 * @Last Modified time: 2020-03-19 16:23:05
 */
#include <iostream>
#include <stdio.h>
using namespace std;
double m, h, bmi;
int main()
{
    cin >> m >> h;
    bmi = m / (h * h);
    if (bmi < 18.5)
        cout << "Underweight" << endl;
    if (bmi >= 18.5 && bmi < 24)
        cout << "Normal";
    if (bmi >= 24)
        cout << bmi << endl,
            cout << "Overweight" << endl;
    return 0;
}