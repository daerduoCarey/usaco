/*
ID: 5120309052
PROG: milk
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int p[5001]={0},w[5001]={0};
int n,m;
int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    cin>>n>>m;int x,y;
    for(int i=1;i<=m;++i)cin>>p[i]>>w[i];
    for(int i=1;i<m;++i)
        for(int j=i+1;j<=m;++j)
            if(p[i]>p[j])
    {
        int tmp=p[i];p[i]=p[j];p[j]=tmp;
        tmp=w[i];w[i]=w[j];w[j]=tmp;
    }
    int ans=0;int k=1;
    while(n>0)
    {
        if(n-w[k]>=0)
        {
            ans+=w[k]*p[k];
            n-=w[k];++k;
        }
        else
        {
            ans+=n*p[k];
            ++k;
            n=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
