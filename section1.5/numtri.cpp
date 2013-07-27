/*ID: 5120309052
PROG:numtri
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,a[2000]={0},b[2000]={0};
int max1(int x,int y) {if(x<y) return y; return x;}
int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    cin>>n;
    cin>>a[1];
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=i;++j) cin>>b[j];
        a[i]=b[i]+a[i-1];
        for(int j=i-1;j>=2;--j)
            a[j]=max1(a[j-1],a[j])+b[j];
        a[1]+=b[1];
    }
    int max=0;
    for(int i=1;i<=n;++i)
        if(a[i]>max) max=a[i];
    cout<<max<<endl;
    return 0;
}
