/*ID: 5120309052
PROG: range
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;

int n;
int a[251][251]={0},s[251][251]={0};
int f[251][251][2]={0};
bool check(int x,int y,int k)
{
    int f=1;
    if(s[x][y]-s[x-k][y]-s[x][y-1]+s[x-k][y-1]!=k) f=0;
    if(s[x][y]-s[x][y-k]-s[x-1][y]+s[x-1][y-k]!=k) f=0;
    return f;
}
int main()
{
    freopen("range.in","r",stdin);
    freopen("range.out","w",stdout);
    cin>>n;char c;getchar();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            a[i][j]=getchar()-'0';
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
        getchar();
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f[i][j][1]=a[i][j]+f[i-1][j][1]+f[i][j-1][1]-f[i-1][j-1][1];
    for(int k=2;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
        {
            f[i][j][k%2]=f[i-1][j][k%2]+f[i][j-1][k%2]-f[i-1][j-1][k%2];
            if(a[i][j])
            {
                if(i<k||j<k) f[i][j][k%2]=0;
                else if(check(i,j,k))
                    f[i][j][k%2]+=f[i-1][j-1][(k+1)%2]-f[i-2][j-1][(k+1)%2]-f[i-1][j-2][(k+1)%2]+f[i-2][j-2][(k+1)%2];
            }
        }
        if(f[n][n][k%2]) cout<<k<<" "<<f[n][n][k%2]<<endl;
    }
    return 0;
}
