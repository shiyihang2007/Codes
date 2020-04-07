#include <bits/stdc++.h>
using namespace std;
int n,m;
int d[105][105],t[105][105];
int a,b,c;
int main(){
    
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>d[i][j];
        }
    }
    cin>>a>>b>>c;
    for(int i=0;i<c;++i){
        for(int j=0;j<c;++j){
            t[a+j][b+c-i]=d[a+i][b+j];
        }
    }
    for(int i=0;i<c;++i){
        for(int j=0;j<c;++j){
            d[a+i][b+j]=t[a+i][b+c-j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            printf("%d ",d[i][j]);
        }
        puts("");
    }
}