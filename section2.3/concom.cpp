/*ID: 5120309052
PROG: concom
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;
int a[201][201]={0},n,b[201]={0},o[201]={0};
int c[200]={0},m[200]={0};
void dfs(int x)
{
    m[x]=1;
    for(int i=1;i<=n;++i)
        c[i]+=a[b[x]][b[i]];
    for(int i=1;i<=n;++i)
        if(c[i]>50&&!m[i]) dfs(i);
}
int main()
{
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    cin>>n;int x,y,z;
    for(int i=1;i<=n;++i)
    {
        cin>>x>>y>>z;
        a[x][y]=z;
        o[x]=1;o[y]=1;
    }
    n=0;
    for(int i=1;i<=100;++i) if(o[i]) b[++n]=i;
    for(int i=1;i<=n;++i)
    {
        memset(c,0,sizeof(c));
        memset(m,0,sizeof(m));
        dfs(i);
        for(int j=1;j<=n;++j)
            if(i!=j&&c[j]>50) cout<<b[i]<<" "<<b[j]<<endl;
    }
    return 0;
}
