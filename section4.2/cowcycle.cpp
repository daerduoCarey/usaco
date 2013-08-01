/*
ID: 5120309052
TASK: cowcycle
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int f,r,lf,rf,lr,rr;
int ff[6]={0},fr[11]={0};
int ansff[6]={0},ansfr[11]={0};
double ratio[100];
double ans=-1;
double square(double x) {return x*x;}
void dfs(int k)
{
    if(k>f+r)
    {
        if(ff[f]*fr[r]<3*ff[1]*fr[1]) return;
        for(int i=1;i<=f;++i)
            for(int j=1;j<=r;++j)
                ratio[r*(i-1)+j]=ff[i]*1.0/fr[j];
        sort(ratio+1,ratio+f*r+1);
        int tot=f*r;
        double average,sum=0,variance=0;
        for(int i=1;i<tot;++i) sum+=ratio[i+1]-ratio[i];
        average=sum/(tot-1);sum=0;
        for(int i=1;i<tot;++i) sum+=square(ratio[i+1]-ratio[i]-average);
        variance=sum/(tot-1);
        if(ans<0||ans>variance)
        {
            ans=variance;
            for(int i=1;i<=f;++i) ansff[i]=ff[i];
            for(int i=1;i<=r;++i) ansfr[i]=fr[i];
        }
        return;
    }
    if(k<=f)
    {
        for(int i=ff[k-1]+1;i<=rf;++i)
        {
            ff[k]=i;
            dfs(k+1);
        }
    }
    else
    {
        if(k==f+1)
        {
            for(int i=lr;i<=rr;++i)
            {
                fr[1]=i;
                dfs(k+1);
            }
        }
        else if(k<f+r)
        {
            for(int i=fr[k-f-1]+1;i<=rr;++i)
            {
                fr[k-f]=i;
                dfs(k+1);
            }
        }
        else
        {
            int tmp=3*ff[1]*fr[1];
            if(tmp%ff[f]==0) tmp=tmp/ff[f];
            else tmp=tmp/ff[f]+1;
            for(int i=max(tmp,fr[k-f-1]+1);i<=rr;++i)
            {
                fr[k-f]=i;
                dfs(k+1);
            }
        }
    }
    return;
}
int main()
{
    freopen("cowcycle.in","r",stdin);
    freopen("cowcycle.out","w",stdout);
    cin>>f>>r>>lf>>rf>>lr>>rr;
    ff[0]=lf-1;fr[0]=lr-1;
    dfs(1);
    for(int i=1;i<f;++i) cout<<ansff[i]<<" ";cout<<ansff[f]<<endl;
    for(int i=1;i<r;++i) cout<<ansfr[i]<<" ";cout<<ansfr[r]<<endl;
    return 0;
}
