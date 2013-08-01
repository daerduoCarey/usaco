/*
ID: 5120309052
TASK: stall4
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,mm,tot,ans=0;
int a[402][402]={0};
int q[402]={0},he,ta;
int m[402]={0},pre[402]={0};
int main()
{
    freopen("stall4.in","r",stdin);
    freopen("stall4.out","w",stdout);
    cin>>n>>mm;tot=n+mm+1;
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x;
        a[0][i]=1;
        for(int j=1;j<=x;++j)
        {
            cin>>y;
            a[i][n+y]=1;
        }
    }
    for(int i=n+1;i<=n+mm;++i) a[i][tot]=1;
    while(1)
    {
        memset(m,0,sizeof(m));
        memset(pre,0,sizeof(pre));
        q[1]=0;he=ta=1;m[0]=1;pre[0]=0;
        while(he<=ta)
        {
            int tt=q[he++];
            for(int i=0;i<=tot;++i)
                if(a[tt][i]&&!m[i])
                    {q[++ta]=i;m[i]=1;pre[i]=tt;}
        }
        if(!m[tot]) break;
        ++ans;
        int kk=tot;
        while(pre[kk]!=kk)
        {
            a[pre[kk]][kk]-=1;
            a[kk][pre[kk]]+=1;
            kk=pre[kk];
        }
    }
    cout<<ans<<endl;
    return 0;
}
