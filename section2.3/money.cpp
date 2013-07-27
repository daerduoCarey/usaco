/*ID: 5120309052
PROG: money
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int v,n;
int a[50]={0};long long f[50][20000]={0};
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>v>>n;
    for(int i=1;i<=v;++i) cin>>a[i];
    f[0][0]=1;
    for(int i=1;i<=v;++i)
        for(int j=0;j<=n;++j)
    {
        int k=j;
        while(k>=0)
        {
            f[i][j]+=f[i-1][k];
            k-=a[i];
        }
    }
    cout<<f[v][n]<<endl;
    return 0;
}
