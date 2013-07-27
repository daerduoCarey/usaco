/*ID: 5120309052
PROG: hamming
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,b,d,a[100]={0};
bool panduan(int x,int y)
{
    int xx[10]={0},yy[10]={0};
    for(int i=1;i<=b;++i)
    {
        xx[i]=x%2;x/=2;
        yy[i]=y%2;y/=2;
    }
    int sum=0;
    for(int i=1;i<=b;++i)
        if(xx[i]!=yy[i]) ++sum;
    if(sum>=d) return true;
    else return false;
}
int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    int k=1,p=0;a[1]=0;
    cin>>n>>b>>d;
    while(k<n)
    {
        ++p;
        int f=1;
        for(int i=1;i<=k;++i)
            if(!panduan(p,a[i])) {f=0;break;}
        if(f) {++k;a[k]=p;}
    }
    for(int i=1;i<n;++i)
    {
        if(i%10==0) cout<<a[i]<<endl;
        else cout<<a[i]<<" ";
    }
    cout<<a[n]<<endl;
    return 0;
}
