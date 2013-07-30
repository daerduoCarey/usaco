/*
ID: 5120309052
LANG: C++
TASK: game1
*/

#include<iostream>
#include<cstdio>
using namespace std;

int n,a[101]={0},s[101]={0};
int f[101][101]={0};

int main()
{
    freopen("game1.in","r",stdin);
    freopen("game1.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        f[i][i]=a[i];
    }
    for(int i=2;i<=n;++i)
        for(int j=1;j<=n-i+1;++j)
            if(f[j+1][j+i-1]<f[j][j+i-2])
                f[j][j+i-1]=a[j]+(s[j+i-1]-s[j]-f[j+1][j+i-1]);
            else
                f[j][j+i-1]=a[j+i-1]+(s[j+i-2]-s[j-1]-f[j][j+i-2]);
    cout<<f[1][n]<<" "<<s[n]-f[1][n]<<endl;
    return 0;
}
