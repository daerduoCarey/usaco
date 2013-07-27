/*ID: 5120309052
PROG: holstein
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int v,g,mi=50,mans[50]={0},mini;
int a[50]={0},b[20][50]={0},d[50]={0},m[50]={0};
void dfs(int k,int s)
{
    if(k>g)
    {
        //for(int i=1;i<=g;++i) cout<<m[i]<<" ";cout<<endl;
        int f=1;
        for(int i=1;i<=v;++i) if(d[i]<a[i]) {f=0;break;}
       // for(int i=1;i<=v;++i) cout<<d[i]<<" ";cout<<endl;
        int tmp=0;while(m[tmp]==0) ++tmp;
        //cout<<tmp<<" "<<mi<<" "<<mini<<endl;
        if(f&&(mi>s||(mi==s&&mini>tmp)))
        {
            mi=s;mini=tmp;
            int k=0;
            for(int i=1;i<=g;++i) if(m[i]) mans[++k]=i;
        }
    }
    else
    {
        dfs(k+1,s);
        for(int i=1;i<=v;++i) d[i]+=b[k][i];m[k]=1;
        dfs(k+1,s+1);
        for(int i=1;i<=v;++i) d[i]-=b[k][i];m[k]=0;
    }
}
int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    cin>>v;
    for(int i=1;i<=v;++i) cin>>a[i];
    cin>>g;
    for(int i=1;i<=g;++i)
        for(int j=1;j<=v;++j)
            cin>>b[i][j];
    dfs(1,0);
    cout<<mi<<" ";
    for(int i=1;i<mi;++i) cout<<mans[i]<<" ";
    cout<<mans[mi]<<endl;
    return 0;
}
