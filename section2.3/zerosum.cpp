/*ID: 5120309052
PROG: zerosum
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,b[20]={0};
char get(int x)
{
    if(x==0) return ' ';
    else if(x==1) return '+';
    else return '-';
}
void dfs(int k)
{
    //for(int i=1;i<n;++i) cout<<b[i];cout<<endl;
    if(k==n)
    {
        int t=1,ans=0,x=1;
        while(b[t]==0&&t<n)
        {
            ++t;
            x=x*10+t;
        }
        ans=x;
        while(t<n)
        {
            int f=1;
            if(b[t]==2) f=2;
            ++t;
            x=t;
            while(b[t]==0&&t<n)
            {
                ++t;
                x=x*10+t;
            }
            if(f==1) ans+=x;
            else ans-=x;
        }
        if(!ans)
        {
            for(int i=1;i<n;++i)
                cout<<i<<get(b[i]);
            cout<<n<<endl;
        }
    }
    else
    {
        b[k]=0;dfs(k+1);
        b[k]=1;dfs(k+1);
        b[k]=2;dfs(k+1);
    }
}
int main()
{
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    cin>>n;
    dfs(1);
    return 0;
}
