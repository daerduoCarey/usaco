/*ID: 5120309052
PROG: humble
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int k,n,tot=0;
int p[101]={0},m[101]={0};
long long a[100001]={0};
int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    cin>>k>>n;
    for(int i=1;i<=k;++i) cin>>p[i];
    ++tot;a[1]=1;
    while(tot<=n)
    {
        int minm=-1,mink;
        for(int i=1;i<=k;++i)
        {
            while(a[m[i]]*p[i]<=a[tot]) ++m[i];
            if(minm==-1||a[m[i]]*p[i]<minm) {minm=a[m[i]]*p[i];mink=i;}
        }
        a[++tot]=minm;
    }
    cout<<a[tot]<<endl;
    return 0;
}
