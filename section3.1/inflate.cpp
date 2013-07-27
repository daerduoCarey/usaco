/*ID: 5120309052
PROG: inflate
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,tot=0;
int f[10001]={0},c[10001]={0},w[10001]={0};
int cur[10001]={0};
int main()
{
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    cin>>m>>n;int x,y;
    for(int i=1;i<=n;++i)
    {
        cin>>x>>y;
        if(cur[x]&&cur[x]<y) continue;
        else
        {
            ++tot;
            cur[x]=y;
            c[tot]=y;w[tot]=x;
        }
    }
    //完全背包  不需要考虑k，已自动考虑
    for(int i=1;i<=tot;++i)
        for(int j=c[i];j<=m;++j)
            if(f[j-c[i]]+w[i]>f[j]) f[j]=f[j-c[i]]+w[i];
    cout<<f[m]<<endl;
    return 0;
}
