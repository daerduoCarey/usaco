/*ID: 5120309052
PROG: subset
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;long long f[50][5000]={0};
int main()
{
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    cin>>n;
    f[1][1]=1;f[1][0]=1;
    for(int i=2;i<=n;++i)
        for(int j=0;j<=i*(i+1)/2;++j)
    {
        f[i][j]=f[i-1][j];
        if(j-i>=0) f[i][j]+=f[i-1][j-i];
        //cout<<f[i][j]<<' ';
    }
    //cout<<endl;}
    if((n*(n+1))%4==0)cout<<f[n][n*(n+1)/4]/2<<endl;
    else cout<<0<<endl;
    return 0;
}
