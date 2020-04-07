#include <bits/stdc++.h>
using namespace std;
int n,l[105],b[105];
char a[105][255];
int pd(int x){
    int sa=1,sb=1;
    for(int i=0;i<l[x];++i){
        sa+=a[x][i]=='A';
    }
    for(int i=0;i<l[x];++i){
        sb+=a[x][i]=='B';
    }
    return -(sb*200/sa);
}
int main(){
    
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        l[i]=strlen(a[i]);
        b[i] = pd(i);
        //printf("%d\n", b[i]);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n-i;++j){
            if(b[j]<b[j+1]){
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
            }
        }
    }
    for(int i=1;i<=n;++i){
        printf("%s",a[i]);
    }
}