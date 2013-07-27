/*ID: 5120309052
PROG: nocows
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,f[400][200]={0};
int main()
{
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    f[1][1]=1;
    cin>>n>>k;
    for(int i=2;i<=k;++i)
        for(int j=2*i-1;j<=200;++j)
    {
        for(int kk=1;kk<=j-1;++kk)
        {
            int tmp=0;
            for(int p=1;p<i-1;++p) tmp=(tmp+f[p][j-kk-1])%9901;
            f[i][j]=(f[i][j]+f[i-1][kk]*tmp*2)%9901;
        }
        for(int kk=1;kk<=j-1;++kk)
        {
            f[i][j]=(f[i][j]+f[i-1][kk]*f[i-1][j-1-kk])%9901;
        }
    }
    cout<<f[k][n]<<endl;
    return 0;
}
