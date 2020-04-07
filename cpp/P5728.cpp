#include <bits/stdc++.h>
using namespace std;
int n,a[1005][5];
int main(){
    cin>>n;
    for (int i = 1;i<=n;++i){
        cin >> a[i][1]>> a[i][2]>> a[i][3];
        a[i][0] = a[i][1] + a[i][2] + a[i][3];
    }
    for (int i = 1; i <= n;++i)
        for (int j = i + 1; j <= n;++j)
            if(abs(a[i][1]-a[j][1])<6&&abs(a[i][2]-a[j][2])<6&&abs(a[i][3]-a[j][3])<6&&abs(a[i][0]-a[j][0])<11)
                ++a[0][0];
    cout << a[0][0];
    return 0;
}