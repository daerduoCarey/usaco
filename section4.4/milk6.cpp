/*
ID: 5120309052
TASK: milk6
LANG: C++
*/

#include<iostream>
#include<cstdio>

using namespace std;

int n,m,totm=0,num,totb=0;
long long ans1,ans2;
long long a[33][33]={0},aa[33][33]={0},f[50]={0};
int q[50]={0},he,ta,d[50]={0},pre[50]={0};
int bx[1001]={0},by[1001]={0},bq[1001]={0},ca[33][33]={0};

long long min(long long x,long long y) {if(x<y) return x; return y;}

long long zuidaliu()
{
    long long ans=0;
    while(1)
    {
        for(int i=1;i<=n;++i) {d[i]=0;pre[i]=0;}
        q[1]=1;he=ta=1;d[1]=1;pre[1]=1;
        while(he<=ta)
        {
            int tt=q[he++];
            for(int i=1;i<=n;++i)
                if(!d[i]&&a[tt][i]>0)
                {
                    if(tt>1) f[i]=min(a[tt][i],f[tt]);
                    else f[i]=a[tt][i];
                    pre[i]=tt;
                    q[++ta]=i;
                    d[i]=1;
                }
        }
        if(pre[n])
        {
            int tt=n;long long tmp=f[n];
            ans+=tmp;
            while(pre[tt]!=tt)
            {
                a[pre[tt]][tt]-=tmp;
                a[tt][pre[tt]]+=tmp;
                tt=pre[tt];
            }
        }
        else break;
    }
    return ans;
}

int main()
{
    freopen("milk6.in","r",stdin);
    freopen("milk6.out","w",stdout);
    cin>>n>>m;int zz,xx,yy;
    for(int i=1;i<=m;++i)
    {
        cin>>xx>>yy>>zz;
        bx[i]=xx;by[i]=yy;bq[i]=zz;
        a[xx][yy]+=zz;++ca[xx][yy];
        aa[xx][yy]+=zz;
    }
    ans1=zuidaliu();
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) a[i][j]=aa[i][j]*10000+ca[i][j];
    ans2=zuidaliu();
    num=ans2%10000;
    cout<<ans1<<" "<<num<<endl;
    for(int k=1;k<=m;++k)
    {
        int x=bx[k],y=by[k];
        long long q=bq[k];
        for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) a[i][j]=aa[i][j]*10000+ca[i][j];
        a[x][y]-=q*10000+1;
        long long tmpans=zuidaliu();
        if(q*10000+1==ans2-tmpans)
        {
            ++totb;
            if(totb>num) break;
            cout<<k<<endl;
        }
    }
    return 0;
}
