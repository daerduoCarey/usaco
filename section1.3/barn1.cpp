/*
ID: 5120309052
PROG: barn1
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int m,s,c;int a[400]={0},q[400]={0},d[400]={0},b[400]={0};
int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    cin>>m>>s>>c;
    for(int i=1;i<=c;++i) cin>>a[i];
    for(int i=1;i<c;++i)
            for(int j=1+i;j<=c;++j)
                if(a[i]>a[j])
    {
        int tmp=a[i];a[i]=a[j];a[j]=tmp;
    }
    for(int i=1;i<c;++i) {b[i]=i;d[i]=a[i+1]-a[i];}
    for(int i=1;i<c;++i)
            for(int j=i+1;j<c;++j)
                if(d[i]<d[j])
    {
        int tmp=d[i];d[i]=d[j];d[j]=tmp;
        tmp=b[i];b[i]=b[j];b[j]=tmp;
    }
    for(int i=1;i<m;++i) q[b[i]]=1;
    int ans=0;
    int x=a[1];
    for(int i=1;i<c;++i)
    {
        if(q[i])
        {
            //cout<<a[i]<<" "<<x<<endl;
            ans+=a[i]-x+1;
            x=a[i+1];
        }
    }
    //cout<<a[c]<<" "<<x<<endl;
    ans+=a[c]-x+1;
    cout<<ans<<endl;
    return 0;
}
