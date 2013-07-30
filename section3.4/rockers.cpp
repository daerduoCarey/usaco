/*
ID: 5120309052
LANG: C++
TASK: rockers
*/

#include<iostream>
#include<cstdio>
using namespace std;
int p[21]={0},n,t,m;
int f[21][21][21]={0};
int main()
{
    freopen("rockers.in","r",stdin);
    freopen("rockers.out","w",stdout);
    cin>>n>>t>>m;
    for(int i=1;i<=n;++i) cin>>p[i];
    for(int k=0;k<=t;++k) if(k>=p[1]) f[1][1][k]=1;
    for(int i=2;i<=n;++i)
        for(int j=0;j<=i;++j)
            for(int k=0;k<=t;++k)
            {
                if(k>=p[i]&&f[i-1][j][k-p[i]]) f[i][j][k]=f[i-1][j][k-p[i]]+1;
                if(f[i-1][j][k]>f[i][j][k]) f[i][j][k]=f[i-1][j][k];
                if(j>=1&&f[i-1][j-1][t]>=j-1&&k>=p[i]&&f[i-1][j-1][t]+1>f[i][j][k])
                    f[i][j][k]=f[i-1][j-1][t]+1;
                else if(j>=1&&f[i-1][j-1][t]>=j-1&&f[i-1][j-1][t]>f[i][j][k])
                    f[i][j][k]=f[i-1][j-1][t];
            }
    int max=0;
    for(int i=1;i<=m;++i)
        for(int j=0;j<=t;++j)
            if(f[n][i][j]>max) max=f[n][i][j];
    cout<<max<<endl;
    return 0;
}
