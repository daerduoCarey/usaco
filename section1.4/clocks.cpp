/*
ID: 5120309052
PROG: clocks
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int q[300000]={0},m[300000]={0},pre[300000]={0},way[300000]={0},he,ta;
int ans[300000]={0},la=0;
int ch1(int x)
{
    int xx=x,y=1;
    int a[10]={0};
    for(int i=1;i<=9;++i) {a[10-i]=xx%4;xx/=4;}
    a[1]=(a[1]+1)%4;
    a[2]=(a[2]+1)%4;
    a[4]=(a[4]+1)%4;
    a[5]=(a[5]+1)%4;
    y=a[1];
    for(int i=2;i<=9;++i) y=y*4+a[i];
    return y;
}
int ch2(int x)
{
    int xx=x,y=1;
    int a[10]={0};
    for(int i=1;i<=9;++i) {a[10-i]=xx%4;xx/=4;}
    a[1]=(a[1]+1)%4;
    a[2]=(a[2]+1)%4;
    a[3]=(a[3]+1)%4;
    //a[5]=(a[5]+1)%4;
    y=a[1];
   for(int i=2;i<=9;++i) y=y*4+a[i];
    return y;
}
int ch3(int x)
{
    int xx=x,y=1;
    int a[10]={0};
    for(int i=1;i<=9;++i) {a[10-i]=xx%4;xx/=4;}
    a[3]=(a[3]+1)%4;
    a[2]=(a[2]+1)%4;
    a[6]=(a[6]+1)%4;
    a[5]=(a[5]+1)%4;
    y=a[1];
    for(int i=2;i<=9;++i) y=y*4+a[i];
    return y;
}
int ch4(int x)
{
    int xx=x,y=1;
    int a[10]={0};
    for(int i=1;i<=9;++i) {a[10-i]=xx%4;xx/=4;}
    a[1]=(a[1]+1)%4;
    a[7]=(a[7]+1)%4;
    a[4]=(a[4]+1)%4;
    //a[5]=(a[5]+1)%4;
    y=a[1];
    for(int i=2;i<=9;++i) y=y*4+a[i];
    return y;
}
int ch5(int x)
{
    int xx=x,y=1;
    int a[10]={0};
    for(int i=1;i<=9;++i) {a[10-i]=xx%4;xx/=4;}
    a[6]=(a[6]+1)%4;
    a[8]=(a[8]+1)%4;
    a[2]=(a[2]+1)%4;
    a[4]=(a[4]+1)%4;
    a[5]=(a[5]+1)%4;
    y=a[1];
    for(int i=2;i<=9;++i) y=y*4+a[i];
    return y;
}
int ch6(int x)
{
    int xx=x,y=1;
    int a[10]={0};
    for(int i=1;i<=9;++i) {a[10-i]=xx%4;xx/=4;}
    a[3]=(a[3]+1)%4;
    a[6]=(a[6]+1)%4;
    a[9]=(a[9]+1)%4;
    //a[5]=(a[5]+1)%4;
    y=a[1];
    for(int i=2;i<=9;++i) y=y*4+a[i];
    return y;
}
int ch7(int x)
{
    int xx=x,y=1;
    int a[10]={0};
    for(int i=1;i<=9;++i) {a[10-i]=xx%4;xx/=4;}
    a[8]=(a[8]+1)%4;
    a[7]=(a[7]+1)%4;
    a[4]=(a[4]+1)%4;
    a[5]=(a[5]+1)%4;
    y=a[1];
    for(int i=2;i<=9;++i) y=y*4+a[i];
    return y;
}
int ch8(int x)
{
    int xx=x,y=1;
    int a[10]={0};
    for(int i=1;i<=9;++i) {a[10-i]=xx%4;xx/=4;}
    a[7]=(a[7]+1)%4;
    a[8]=(a[8]+1)%4;
    a[9]=(a[9]+1)%4;
    //a[5]=(a[5]+1)%4;
    y=a[1];
    for(int i=2;i<=9;++i) y=y*4+a[i];
    return y;
}
int ch9(int x)
{
    int xx=x,y=1;
    int a[10]={0};
    for(int i=1;i<=9;++i) {a[10-i]=xx%4;xx/=4;}
    a[6]=(a[6]+1)%4;
    a[8]=(a[8]+1)%4;
    a[9]=(a[9]+1)%4;
    a[5]=(a[5]+1)%4;
    y=a[1];
    for(int i=2;i<=9;++i) y=y*4+a[i];
    return y;
}
int main()
{
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    int tar=3;
    for(int i=2;i<=9;++i) tar=tar*4+3;
    //cout<<tar<<endl;
    int x,y;
    cin>>x;
    x=(x/3)-1;
    for(int i=1;i<9;++i)
    {
        cin>>y;
        x=x*4+(y/3-1);
    }
    m[x]=1;he=ta=1;q[1]=x;pre[x]=x;
    while(he<=ta)
    {
        int tmp=q[he];++he;
        if(tmp==tar)
        {
            while(pre[tmp]!=tmp)
            {
                ans[++la]=way[tmp];
                tmp=pre[tmp];
            }
            for(int i=la;i>=2;--i) cout<<ans[i]<<" ";cout<<ans[1]<<endl;
            return 0;
        }
        int xx=ch1(tmp);if(!m[xx]) {q[++ta]=xx;m[xx]=1;pre[xx]=tmp;way[xx]=1;}
        xx=ch2(tmp);if(!m[xx]) {q[++ta]=xx;m[xx]=1;pre[xx]=tmp;way[xx]=2;}
        xx=ch3(tmp);if(!m[xx]) {q[++ta]=xx;m[xx]=1;pre[xx]=tmp;way[xx]=3;}
        xx=ch4(tmp);if(!m[xx]) {q[++ta]=xx;m[xx]=1;pre[xx]=tmp;way[xx]=4;}
        xx=ch5(tmp);if(!m[xx]) {q[++ta]=xx;m[xx]=1;pre[xx]=tmp;way[xx]=5;}
        xx=ch6(tmp);if(!m[xx]) {q[++ta]=xx;m[xx]=1;pre[xx]=tmp;way[xx]=6;}
        xx=ch7(tmp);if(!m[xx]) {q[++ta]=xx;m[xx]=1;pre[xx]=tmp;way[xx]=7;}
        xx=ch8(tmp);if(!m[xx]) {q[++ta]=xx;m[xx]=1;pre[xx]=tmp;way[xx]=8;}
        xx=ch9(tmp);if(!m[xx]) {q[++ta]=xx;m[xx]=1;pre[xx]=tmp;way[xx]=9;}
    }
    return 0;
}
