/*ID: 5120309052
PROG: kimbits
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,l;long long k;
long long f[32][32]={0};
int ans[40]={0};
int main()
{
    freopen("kimbits.in","r",stdin);
    freopen("kimbits.out","w",stdout);
    cin>>n>>l>>k;
    f[1][0]=1;
    for(int i=0;i<=l;++i) f[0][i]=1;
    for(int i=1;i<=l;++i) f[1][i]=2;
    for(int i=2;i<=n;++i)
        for(int j=0;j<=l;++j)
            f[i][j]=f[i-1][j]+f[i-1][j-1];
    int j=l;
    for(int i=n;i>=1;--i)
    {
        //cout<<i<<" "<<j<<" "<<k<<" "<<f[i-1][j]<<endl;
        if(k<=f[i-1][j])
        {
            ans[i]=0;
        }
        else
        {
            ans[i]=1;
            k-=f[i-1][j];
            --j;
        }
    }
    for(int i=n;i>=1;--i) cout<<ans[i];
    cout<<endl;
    return 0;
}
