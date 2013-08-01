/*
ID: 5120309052
TASK: job
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,m1,m2,ans=0;
int a[31]={0},b[31]={0};
int costa[1001]={0},costb[1001]={0};
int delaya[1001]={0},delayb[1001]={0};
int main()
{
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
    cin>>n>>m1>>m2;
    for(int i=1;i<=m1;++i) cin>>a[i];
    for(int i=1;i<=m2;++i) cin>>b[i];
    for(int i=1;i<=n;++i)
    {
        int min=-1,mini;
        for(int j=1;j<=m1;++j)
            if(min==-1||min>delaya[j]+a[j])
            {
                min=delaya[j]+a[j];
                mini=j;
            }
        delaya[mini]+=a[mini];
        costa[i]=delaya[mini];
    }
    cout<<costa[n]<<" ";
    for(int i=1;i<=n;++i)
    {
        int min=-1,mini;
        for(int j=1;j<=m2;++j)
            if(min==-1||min>delayb[j]+b[j])
            {
                min=delayb[j]+b[j];
                mini=j;
            }
        delayb[mini]+=b[mini];
        costb[i]=delayb[mini];
        if(costb[i]+costa[n-i+1]>ans) ans=costb[i]+costa[n-i+1];
    }
    cout<<ans<<endl;
    return 0;
}
