/*
ID: 5120309052
TASK: shuttle
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,tot=0;
int main()
{
    freopen("shuttle.in","r",stdin);
    freopen("shuttle.out","w",stdout);
    cin>>n;
    for(int i=2;i<=n+1;++i)
    {

        if(i%2)
        {
            for(int j=n+i;j>=n-i+2;j-=2) {++tot;if(tot%20==0) cout<<j<<endl; else cout<<j<<" ";}
        }
        else
        {
            for(int j=n+2-i;j<=n+i;j+=2) {++tot;if(tot%20==0) cout<<j<<endl; else cout<<j<<" ";}
        }
    }
    for(int i=n;i>=2;--i)
    {
        if(i%2)
        {
            for(int j=n+i;j>=n-i+2;j-=2) {++tot;if(tot%20==0) cout<<j<<endl; else cout<<j<<" ";}
        }
        else
        {
            for(int j=n+2-i;j<=n+i;j+=2) {++tot;if(tot%20==0) cout<<j<<endl; else cout<<j<<" ";}
        }
    }
    cout<<n+1<<endl;
    return 0;
}
