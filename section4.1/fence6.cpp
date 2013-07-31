/*
ID: 5120309052
TASK: fence6
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_INT=1000000;
int n,tot=0,ans=MAX_INT;
int f[101][3]={0},tmp[10];
int a[200][200]={0};
int d[200][200]={0};
int main()
{
    freopen("fence6.in","r",stdin);
    freopen("fence6.out","w",stdout);
    cin>>n;int x,y,z,n1,n2;
    for(int i=1;i<=n;++i)
    {
        cin>>x>>y>>n1>>n2;
        if(f[x][0]==0)
        {
            f[x][0]=2;
            ++tot;f[x][1]=tot;
            ++tot;f[x][2]=tot;
            a[tot][tot-1]=a[tot-1][tot]=y;
            for(int j=1;j<=n1;++j)
            {
                cin>>z;
                ++f[z][0];
                f[z][f[z][0]]=tot-1;
            }
            for(int j=1;j<=n2;++j)
            {
                cin>>z;
                ++f[z][0];
                f[z][f[z][0]]=tot;
            }
        }
        else if(f[x][0]==1)
        {
            f[x][0]=2;int ff=0;
            ++tot;f[x][2]=tot;
            a[tot][f[x][1]]=a[f[x][1]][tot]=y;
            for(int j=1;j<=n1;++j)
            {
                cin>>tmp[j];z=tmp[j];
                if(f[z][0]==2) ff=1;
            }
            if(ff)
            {
                for(int j=1;j<=n2;++j)
                {
                    cin>>z;
                    ++f[z][0];
                    f[z][f[z][0]]=tot;
                }
            }
            else
            {
                for(int j=1;j<=n1;++j)
                {
                    z=tmp[j];
                    ++f[z][0];
                    f[z][f[z][0]]=tot;
                }
                for(int j=1;j<=n2;++j) cin>>z;
            }
        }
        else
        {
            a[f[x][1]][f[x][2]]=a[f[x][2]][f[x][1]]=y;
            for(int j=1;j<=n1;++j) cin>>z;
            for(int j=1;j<=n2;++j) cin>>z;
        }
    }
    for(int i=1;i<=tot;++i)
        for(int j=1;j<=tot;++j)
            if(a[i][j]) d[i][j]=a[i][j];
            else d[i][j]=MAX_INT;
    for(int k=1;k<=tot;++k)
    {
        for(int i=1;i<k;++i)
            for(int j=1;j<k;++j)
                if(i!=j&&a[i][k]&&a[k][j])
        {
            if(d[i][j]+a[i][k]+a[k][j]<ans)
                ans=d[i][j]+a[i][k]+a[k][j];
        }
        for(int i=1;i<=tot;++i)
            for(int j=1;j<=tot;++j)
                if(d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
    }
    cout<<ans<<endl;
    return 0;
}

