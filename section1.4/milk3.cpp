/*
ID: 5120309052
PROG: milk3
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int m[10000]={0};
int ans[21]={0};
int b[4];
void dfs(int x)
{
    m[x]=1;
    int a[4];
    a[1]=x/21/21;a[2]=(x/21)%21;a[3]=x%21;
    if(!a[1]) ans[a[3]]=1;
    for(int i=1;i<=3;++i)
        for(int j=1;j<=3;++j)
            if(i!=j)
        {
            if(b[j]-a[j]>0)
            {
                if(a[i]>b[j]-a[j])
                {
                    int di=b[j]-a[j];
                    a[i]-=di;
                    a[j]=b[j];
                    int y=a[1]*21*21+a[2]*21+a[3];
                    if(!m[y]) dfs(y);
                    a[i]+=di;
                    a[j]-=di;
                }
                else
                {
                    int di=a[i];
                    a[i]=0;
                    a[j]+=di;
                    int y=a[1]*21*21+a[2]*21+a[3];
                    if(!m[y]) dfs(y);
                    a[i]=di;
                    a[j]-=di;
                }
            }
        }
}
int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    cin>>b[1]>>b[2]>>b[3];
    int x=b[3];
    ans[b[3]]=1;
    dfs(x);
    int anss[100],lans=0;
    for(int i=0;i<=b[3];++i)
        if(ans[i]) anss[++lans]=i;
    for(int i=1;i<lans;++i) cout<<anss[i]<<" ";
    cout<<anss[lans]<<endl;
    return 0;
}
