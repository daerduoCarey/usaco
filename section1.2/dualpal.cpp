/*
ID: 5120309052
PROG: dualpal
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,s,x,y;
int a[1000],l;int aa[1000],ll;
int main()
{
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    cin>>n>>s;x=s;
    while(n)
    {
        ++x;
        int sum=0;
        for(int b=2;b<=10;++b)
        {
            if(sum>1) break;
            l=0;int xx=x;
            while(xx) {a[++l]=xx%b;xx/=b;}
            int yes=1;
            for(int j=1;j<=l/2;++j) if(a[j]!=a[l-j+1]) {yes=0;break;}
            if(yes) ++sum;
        }
        if(sum>1) {--n;cout<<x<<endl;}
    }
    return 0;
}

