/*ID: 5120309052
PROG: sort3
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[2001]={0},b[2001]={0},c[5][5]={0};
int min1(int x,int y) {if(x<y) return x; return y;}
int max1(int x,int y) {if(x>y) return x; return y;}
int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;++i)
    {
        if(a[i]!=b[i]) ++c[a[i]][b[i]];
    }
    int ans=0,t;
    ans+=min1(c[1][2],c[2][1]);t=max1(c[1][2],c[2][1])-min1(c[1][2],c[2][1]);
    ans+=min1(c[1][3],c[3][1]);
    ans+=min1(c[3][2],c[2][3]);
    ans+=2*t;
    cout<<ans<<endl;
    return 0;
}
