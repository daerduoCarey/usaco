/*ID: 5120309052
PROG: shopping
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int s,b;
int y[100][1000]={0},yp[100]={0};
int f[6]={0},k[6]={0},p[6]={0};
int ff[1000]={0};
int an[6][6][6][6][6]={0};
int dfs(int a1,int a2,int a3,int a4,int a5)
{
    if(an[a1][a2][a3][a4][a5])
        return an[a1][a2][a3][a4][a5];
    int ans=0;
    int aa[6];
    aa[1]=a1;aa[2]=a2;aa[3]=a3;aa[4]=a4;aa[5]=a5;
    for(int i=1;i<=b;++i) ans+=p[i]*aa[i];
    for(int i=1;i<=s;++i)
    {
        int ff=1;
        for(int j=1;j<=b;++j) if(y[i][f[j]]>aa[j]) {ff=0;break;}
        if(ff)
        {
            int tmp=yp[i];
            if(tmp<ans) tmp+=dfs(aa[1]-y[i][f[1]],aa[2]-y[i][f[2]],aa[3]-y[i][f[3]],aa[4]-y[i][f[4]],aa[5]-y[i][f[5]]);
            if(tmp<ans) ans=tmp;
        }
    }
    return an[a1][a2][a3][a4][a5]=ans;
}
int main()
{
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    cin>>s;
    for(int i=1;i<=s;++i)
    {
        int x,z,yy;
        cin>>yy;
        for(int j=1;j<=yy;++j)
        {
            cin>>x>>z;
            y[i][x]=z;
        }
        cin>>yp[i];
    }
    cin>>b;
    for(int i=1;i<=b;++i) {cin>>f[i]>>k[i]>>p[i];ff[f[i]]=i;}
    cout<<dfs(k[1],k[2],k[3],k[4],k[5])<<endl;
    return 0;
}
