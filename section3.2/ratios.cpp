/*ID: 5120309052
PROG: ratios
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int b[4],a[4][4];
int main()
{
    freopen("ratios.in","r",stdin);
    freopen("ratios.out","w",stdout);
    for(int i=1;i<=3;++i) cin>>b[i];
    for(int i=1;i<=3;++i) for(int j=1;j<=3;++j) cin>>a[i][j];
    for(int i=1;i<=300;++i)
        for(int x=0;x<=min(100,i);++x)
            for(int y=0;y<=min(100,i-x);++y)
    {
        int z=i-x-y;
        int t[4]={0};
        for(int tt=1;tt<=3;++tt) t[tt]=x*a[1][tt]+y*a[2][tt]+z*a[3][tt];
        if(t[1]%b[1]==0)
        {
            int k=t[1]/b[1];
            if(t[2]==b[2]*k&&t[3]==b[3]*k)
            {cout<<x<<" "<<y<<" "<<z<<" "<<k<<endl;return 0;}
        }
    }
    cout<<"NONE\n";
    return 0;
}
