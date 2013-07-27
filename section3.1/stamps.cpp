/*ID: 5120309052
PROG: stamps
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int f[2000001]={0};
int p[51]={0};
int main()
{
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    cin>>k>>n;int maxp=0;
    for(int i=1;i<=n;++i) {cin>>p[i];if(p[i]>maxp) maxp=p[i];}
    int t=1;
    while(1)
    {
        int mi=300;
        for(int i=1;i<=n;++i)
            if(t-p[i]>0&&f[t-p[i]]&&f[t-p[i]]<mi) mi=f[t-p[i]];
            else if(t-p[i]==0) mi=0;
        f[t]=mi+1;
        if(f[t]>k) break;
        ++t;
    }
    cout<<t-1<<endl;
    return 0;
}
