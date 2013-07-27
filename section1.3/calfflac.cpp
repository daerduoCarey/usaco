/*
ID: 5120309052
PROG: calfflac
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[30000],s[30000];int sc[30000]={0},ls=0,k=0;int tmp,tmp1;
bool check(int q)
{
    int f=0;
    for(int i=1;i<=ls-q+1;++i)
    {
        int ff=1;
        for(int j=i;j<=i+q/2-1;++j)
        {
            if(s[j]!=s[i+q-1-j+i]) {ff=0;break;}
        }
        if(ff) {f=1;tmp=i;break;}
    }
    return f;
}
bool check1(int q)
{
    int f=0;
    for(int i=1;i<=ls-q+1;++i)
    {
        int ff=1;
        for(int j=i;j<=i+q/2-1;++j)
        {
            if(s[j]!=s[i+q-1-j+i]) {ff=0;break;}
        }
        if(ff) {f=1;tmp1=i;break;}
    }
    return f;
}
int main()
{
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    char cc;
    while((cc=getchar())!=EOF)
    {
        c[++k]=cc;
        if(cc>='a'&&cc<='z') {s[++ls]=cc;sc[ls]=k;}
        if(cc>='A'&&cc<='Z') {s[++ls]=cc-'A'+'a';sc[ls]=k;}
    }
    int l=1,r=1000;
    while(l<r)
    {
        int mid=(l+r)/2+1;
        if(check(mid*2)) l=mid;
        else r=mid-1;
    }

    int ll=1,rr=1000;
    while(ll<rr)
    {
        int mid=(ll+rr)/2+1;
        if(check1(mid*2-1)) ll=mid;
        else rr=mid-1;
    }
    if(2*l>2*ll-1){
       cout<<l*2<<endl;
    int start=sc[tmp],end=sc[tmp+2*l-1];
    for(int i=start;i<=end;++i) cout<<c[i];
    cout<<endl;}
    else
    {
            cout<<2*ll-1<<endl;
        int start=sc[tmp1],end=sc[tmp1+2*ll-1-1];
        for(int i=start;i<=end;++i) cout<<c[i];
        cout<<endl;
    }
    return 0;
}
