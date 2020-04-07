#include <iostream>
#include <string>
using namespace std;
int main(){
    int l,k;
    string s;
    cin>>s;
    l=s.size();
    k=l-1;
    for(int i=1;i<l;++i)
        if(s[i]==s[i-1]) k--;
    if(s[l-1]=='0') ++k;
    cout<<k;
    //getchar();getchar();
    return 0;
}