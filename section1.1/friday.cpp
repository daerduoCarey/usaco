/*
ID: 5120309052
PROG: friday
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(int x)
{
    if(x%4==0&&x%100) return true;
    else if(x%400==0) return true;
    return false;
}
int n,y=1900,m=1,k=2;
int num[8]={0};
int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    cin>>n;
    while(y<=1900+n-1)
    {
        ++num[(k+5)%7];
        ++m;k=(k+a[m-1])%7;
        if(m==13) {++y;m=1;}
        if(m==3&&leap(y)) k=(k+1)%7;
    }
    for(int i=0;i<6;++i) cout<<num[i]<<" ";cout<<num[6];
    cout<<endl;
    return 0;
}
