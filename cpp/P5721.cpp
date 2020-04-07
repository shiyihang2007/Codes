#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n-i+1;++j)
            printf("%02d",++k);
        putchar('\n');
    }
}