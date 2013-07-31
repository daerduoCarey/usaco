/*
ID: 5120309052
TASK: ditch
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const long long MAX_INT=3000000000;
int n,mm;long long ans=0;
long long a[201][201]={0};
int q[10000]={0},he,ta;
long long f[201]={0};
int m[201]={0},pre[201]={0};
long long min(long long x,long long y)
{
    if(x<y) return x; else return y;
}
int main()
{
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    cin>>mm>>n;int x,y,z;
    for(int i=1;i<=mm;++i)
    {
        cin>>x>>y>>z;
        a[x][y]+=z;
    }
    while(1)
    {
        memset(f,0,sizeof(f));memset(m,0,sizeof(m));memset(pre,0,sizeof(pre));
        he=ta=1;q[1]=1;m[1]=1;f[1]=MAX_INT;pre[1]=1;
        while(he<=ta)
        {
            int tt=q[he];++he;
            for(int i=1;i<=n;++i)
                if(a[tt][i]&&min(a[tt][i],f[tt])>f[i])
                {
                    f[i]=min(a[tt][i],f[tt]);
                    pre[i]=tt;
                    if(!m[i]) {q[++ta]=i;m[i]=1;}
                }
            m[tt]=0;
        }
        if(f[n])
        {
            ans+=f[n];
            int tmp=n;
            while(pre[tmp]!=tmp)
            {
                a[pre[tmp]][tmp]-=f[n];
                a[tmp][pre[tmp]]+=f[n];
                tmp=pre[tmp];
            }
        }
        else break;
    }
    cout<<ans<<endl;
    return 0;
}
