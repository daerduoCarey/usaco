/*ID: 5120309052
PROG: cowtour
LANG: C++
*/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k=0;
int a[251][251]={0};
double f[251][251]={0};
int x[251]={0},y[151]={0},m[251]={0};
double ma[251]={0};
double dis(int xx,int yy)
{
    double tmp;
    tmp=1.0*((x[xx]-x[yy])*(x[xx]-x[yy])+(y[xx]-y[yy])*(y[xx]-y[yy]));
    return sqrt(tmp);
}
void dfs(int x,int kk)
{
    m[x]=kk;
    for(int i=1;i<=n;++i)
        if(m[i]==0&&a[x][i]) dfs(i,kk);
}
void calc(int kk)
{
    double ff[251][251]={0},mm[251][251]={0};int li[251]={0},l=0;
    for(int i=1;i<=n;++i) if(m[i]==kk) {li[++l]=i;}
    for(int i=1;i<=l;++i)
        for(int j=1;j<=l;++j)
            if(a[li[i]][li[j]]) {ff[i][j]=dis(li[i],li[j]);mm[i][j]=1;}
    for(int k=1;k<=l;++k)
        for(int i=1;i<=l;++i)
            for(int j=1;j<=l;++j)
    if(i!=j)
    {
        if(!mm[i][j])
        {
            if(mm[i][k]&&mm[k][j]) {mm[i][j]=1;ff[i][j]=ff[i][k]+ff[k][j];}
        }
        else
        {
            if(mm[i][k]&&mm[k][j]&&ff[i][k]+ff[k][j]<ff[i][j])
                ff[i][j]=ff[i][k]+ff[k][j];
        }
    }
    double maxx=0;
    for(int i=1;i<=l;++i)
        for(int j=1;j<=l;++j)
    {
        f[li[i]][li[j]]=ff[i][j];
        if(ff[i][j]>maxx) maxx=ff[i][j];
    }
    ma[kk]=maxx;
}
int main()
{
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i];
    getchar();
    for(int i=1;i<=n;++i)
        {for(int j=1;j<=n;++j)
            {
                char c=getchar();
                if(c=='0') a[i][j]=0; else a[i][j]=1;
            }
            getchar();}
    for(int i=1;i<=n;++i)
        if(!m[i])
        {
            ++k;
            dfs(i,k);
        }
    for(int i=1;i<=k;++i)
    {
        calc(i);
    }
    double ans=-1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j&&m[i]!=m[j])
            {
                double tmp=ma[m[i]];
                if(ma[m[j]]>tmp) tmp=ma[m[j]];
                double t1=0;
                for(int kk=1;kk<=n;++kk)
                    if(m[kk]==m[i]&&f[kk][i]>t1) t1=f[kk][i];
                double t2=0;
                for(int kk=1;kk<=n;++kk)
                    if(m[kk]==m[j]&&f[kk][j]>t2) t2=f[kk][j];
                if(t1+t2+dis(i,j)>tmp) tmp=t1+t2+dis(i,j);
                if(ans<0||tmp<ans) ans=tmp;
            }
    printf("%.6f\n",ans);
    return 0;
}
