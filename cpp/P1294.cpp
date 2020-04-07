/*
 * @Author: shiyihang 
 * @Date: 2020-03-11 17:58:10 
 * @Last Modified by: shiyihang
 * @Last Modified time: 2020-03-11 17:58:42
 */
#include<bits/stdc++.h>
using namespace std;
int Edge[21][21],n,s,an,t,ans,b[100000];
int x,y,c;
int dfs(int k,int su)
{
    ans=max(ans,su);
    for(int i=1;i<=t;i++)
    {
        if(Edge[k][i]>0&&b[i]==0)
        {
            b[i]=1;
            dfs(i,su+Edge[k][i]);
            b[i]=0;
        }
    }
}
int main()
{
    cin>>t>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>c;
        Edge[x][y]=c;
        Edge[y][x]=c;
    }
    for(int i=1;i<=t;i++)
    {
        b[i]=1;
        dfs(i,0);
        an=max(an,ans);
        memset(b,0,sizeof(b));
    }
    cout<<an;
}