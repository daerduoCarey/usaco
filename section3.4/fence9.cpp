/*
ID: 5120309052
LANG: C++
TASK: fence9
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,p;long long ans=0;
int main()
{
    freopen("fence9.in","r",stdin);
    freopen("fence9.out","w",stdout);
    cin>>n>>m>>p;
    for(int i=1;i<m;++i)
    {
        int t1,t2;
        t1=n*i/m;
        t2=((n-p)*i+p*m)/m;
        if(((n-p)*i+m*p)%m==0) --t2;
        ans+=t2-t1;
    }
    cout<<ans<<endl;
    return 0;
}
