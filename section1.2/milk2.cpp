/*
ID: 5120309052
PROG: milk2
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n;
int l[5001]={0},r[5001]={0};
int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>l[i]>>r[i];
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
            if(l[i]>l[j]||(l[i]==l[j]&&r[i]>r[j]))
    {
        int tmp=l[i];l[i]=l[j];l[j]=tmp;
        tmp=r[i];r[i]=r[j];r[j]=tmp;
    }
    int x=l[1],y=r[1];int l1=r[1]-l[1],l2=0;
    for(int i=2;i<=n;++i)
    {
        int xx=l[i],yy=r[i];
        if(xx>y)
        {
            if(xx-y>l2) l2=xx-y;
            if(y-x>l1) l1=y-x;
            x=xx;y=yy;
        }
        else if(yy>y) y=yy;
    }
    if(y-x>l1) l1=y-x;
    cout<<l1<<" "<<l2<<endl;
    return 0;
}
