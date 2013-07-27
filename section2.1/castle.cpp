/*ID: 5120309052
PROG: castle
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k=0;
int a[100][100]={0},b[100][100]={0},s[10000]={0};
bool ok(int x,int y,int d)
{
    if(d==1)
    {
        if(x>1) return true; else return false;
    }
    else if(d==2)
    {
        if(y<n) return true; else return false;
    }
    else if(d==3)
    {
        if(x<m) return true; else return false;
    }
    else
    {
        if(y>1) return true; else return false;
    }
}
bool you(int x,int y,int d)
{
    int t=a[x][y];
    if(d==4&&t%2) return true;
    t/=2;
    if(d==1&&t%2) return true;
    t/=2;
    if(d==2&&t%2) return true;
    t/=2;
    if(d==3&&t%2) return true;
    return false;
}
void dfs(int x,int y,int k)
{
    b[x][y]=k;++s[k];
    int t=a[x][y];
    if(t%2==0&&!b[x][y-1]) dfs(x,y-1,k);
    t/=2;
    if(t%2==0&&!b[x-1][y]) dfs(x-1,y,k);
    t/=2;
    if(t%2==0&&!b[x][y+1]) dfs(x,y+1,k);
    t/=2;
    if(t%2==0&&!b[x+1][y]) dfs(x+1,y,k);
}
int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(!b[i][j]) {++k;dfs(i,j,k);}
    cout<<k<<endl;
    int max=0;
    for(int i=1;i<=k;++i) if(s[i]>max) max=s[i];
    cout<<max<<endl;
    int maxx,maxy,maxdir;
    for(int j=1;j<=n;++j)
        for(int i=m;i>=1;--i)
    {
        for(int d=1;d<=4;++d)
            if(ok(i,j,d)&&you(i,j,d))
        {
            if(d==1&&s[b[i][j]]+s[b[i-1][j]]>max&&b[i][j]!=b[i-1][j]) {max=s[b[i][j]]+s[b[i-1][j]];maxdir=d;maxx=i;maxy=j;}
            if(d==2&&s[b[i][j]]+s[b[i][j+1]]>max&&b[i][j]!=b[i][j+1]) {max=s[b[i][j]]+s[b[i][j+1]];maxdir=d;maxx=i;maxy=j;}
            if(d==3&&s[b[i][j]]+s[b[i+1][j]]>max&&b[i][j]!=b[i+1][j]) {max=s[b[i][j]]+s[b[i+1][j]];maxdir=d;maxx=i;maxy=j;}
            if(d==4&&s[b[i][j]]+s[b[i][j-1]]>max&&b[i][j]!=b[i][j-1]) {max=s[b[i][j]]+s[b[i][j-1]];maxdir=d;maxx=i;maxy=j;}
        }
    }
    cout<<max<<endl;
    cout<<maxx<<" "<<maxy<<" ";
    if(maxdir==1) cout<<"N\n";
    else if(maxdir==2) cout<<"E\n";
    else if(maxdir==3) cout<<"S\n";
    else cout<<"W\n";
    return 0;
}
