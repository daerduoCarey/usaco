/*ID: 5120309052
PROG: agrinet
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int a[101][101]={0};
int ans=0;
int f[101]={0},m[101]={0};
int main()
{
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin>>a[i][j];
    for(int i=1;i<=n;++i) f[i]=1000000;
    int t=1;
    for(int i=1;i<n;++i)
    {
        m[t]=1;
        for(int j=1;j<=n;++j)
            if(a[t][j]&&a[t][j]<f[j]) f[j]=a[t][j];
        int minm=1000000,mint;
        for(int j=1;j<=n;++j)
            if(!m[j]&&f[j]<minm) {minm=f[j];mint=j;}
        ans+=minm;
        t=mint;
    }
    cout<<ans<<endl;
    return 0;
}
