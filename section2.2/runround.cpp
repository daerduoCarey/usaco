/*ID: 5120309052
PROG: runround
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long x;
int b[10]={0},c[10]={0},a[1000]={0},l=0;
bool check(long long y)
{
    //getchar();
    l=0;int f=1;
    for(int i=0;i<=9;++i) c[i]=b[i]=0;
    while(y&&f) {
            a[l++]=y%10;y/=10;
            if(a[l-1]==0) {f=0;break;}
            else if(b[a[l-1]]==1) {f=0;break;}
            else ++b[a[l-1]];
    }
    if(l>9) return false;
    if(f==0) return false;
    else
    {
        int t=a[l-1],k=l-1;
        while(!c[t])
        {
           // cout<<t<<endl;
            c[t]=1;
            k-=t;
            while(k<0) k+=l;
            //cout<<k<<endl;
            t=a[k];
        }
        int f=1;
        if(t!=a[l-1]) f=0;
        for(int i=1;i<=9&&f;++i)
            if(b[i]&&!c[i]) {f=0;break;}
        return f;
    }
}
int main()
{
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    cin>>x;++x;
    while(!check(x)) ++x;
    cout<<x<<endl;
    return 0;
}
