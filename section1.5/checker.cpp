/*ID: 5120309052
PROG: checker
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,tot=0;
int a[20]={0};
void dfs(int k)
{
    if(k>n)
    {
        ++tot;
        if(tot<=3)
        {
            for(int i=1;i<n;++i) cout<<a[i]<<" ";cout<<a[n]<<endl;
        }
    }
    else
    {
        for(int i=1;i<=n;++i)
        {
            int f=1;
            for(int j=1;j<k;++j)
            {
                if(a[j]==i) {f=0;break;}
                if(a[j]==i-(k-j)) {f=0;break;}
                if(a[j]==i+k-j) {f=0;break;}
            }
            if(f)
            {
                a[k]=i;
                dfs(k+1);
            }
        }
    }
}
int main()
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    cin>>n;
    int tmp,tmp2=0;
    for(int i=1;i<=n/2;++i)
    {
        a[1]=i;
        dfs(2);
    }
    tmp=tot;
    if(n%2)
    {
        a[1]=n/2+1;
        dfs(2);
        tmp2=tot-tmp;
    }
    if(tot>3)
        cout<<2*tmp+tmp2<<endl;
    else
    {
        for(int i=(n%2)? n/2+2:n/2+1;i<=n;++i)
        {
            a[1]=i;
            dfs(2);
        }
        cout<<tot<<endl;
    }
    return 0;
}
