/*
ID: 5120309052
PROG: crypt1
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[10]={0},b[10]={0};
int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    cin>>n;int x;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        a[x]=1;
    }
    int k=0;
    for(int i=1;i<=9;++i) if(a[i]) b[++k]=i;
    int ans=0;
    for(int aa=1;aa<=n;++aa)
        for(int bb=1;bb<=n;++bb)
            for(int c=1;c<=n;++c)
    {
        int tmp=100*b[aa]+10*b[bb]+b[c];
        for(int d=1;d<=n;++d)
            for(int e=1;e<=n;++e)
        {
            if(b[d]*tmp<1000&&b[d]*tmp>99&&b[e]*tmp<1000&&b[e]*tmp>99&&(10*b[d]+b[e])*tmp<10000&&(10*b[d]+b[e])*tmp>999)
            {
                int f=1;
                int xx=b[d]*tmp;
                if(a[xx%10]&&a[(xx/10)%10]&&a[xx/100]) ; else f=0;
                xx=b[e]*tmp;
                if(a[xx%10]&&a[(xx/10)%10]&&a[xx/100]) ; else f=0;
                xx=(10*b[d]+b[e])*tmp;
                if(a[xx%10]&&a[(xx/10)%10]&&a[(xx/100)%10]&&a[xx/1000]) ; else f=0;
                if(f) ++ans;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
