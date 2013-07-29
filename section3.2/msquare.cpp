/*ID: 5120309052
PROG: msquare
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[9]={0},tar=0;
int q[50000]={0},pre[50000]={0},w[50000]={0},he,ta;
bool m[10000000]={0};
int ans[50000]={0},lans=0;
int f1(int x)
{
    int t[9]={0},tt[9]={0};
    for(int i=8;i>=1;--i) {t[i]=x%10;x/=10;}
    tt[1]=t[8];tt[2]=t[7];tt[3]=t[6];tt[4]=t[5];
    tt[5]=t[4];tt[6]=t[3];tt[7]=t[2];tt[8]=t[1];
    int y=0;
    for(int i=1;i<=8;++i) y=y*10+tt[i];
    return y;
}
int f2(int x)
{
    int t[9]={0},tt[9]={0};
    for(int i=8;i>=1;--i) {t[i]=x%10;x/=10;}
    tt[1]=t[4];tt[2]=t[1];tt[3]=t[2];tt[4]=t[3];
    tt[5]=t[6];tt[6]=t[7];tt[7]=t[8];tt[8]=t[5];
    int y=0;
    for(int i=1;i<=8;++i) y=y*10+tt[i];
    return y;
}
int f3(int x)
{
    int t[9]={0},tt[9]={0};
    for(int i=8;i>=1;--i) {t[i]=x%10;x/=10;}
    tt[1]=t[1];tt[2]=t[7];tt[3]=t[2];tt[4]=t[4];
    tt[5]=t[5];tt[6]=t[3];tt[7]=t[6];tt[8]=t[8];
    int y=0;
    for(int i=1;i<=8;++i) y=y*10+tt[i];
    return y;
}
int main()
{
    freopen("msquare.in","r",stdin);
    freopen("msquare.out","w",stdout);
    for(int i=1;i<=8;++i) {cin>>a[i];tar=tar*10+a[i];}
    int z,y,x=12345678;
    q[1]=x;he=ta=1;pre[1]=0;w[1]=0;m[x/10]=1;
    while(he<=ta)
    {
        y=q[he];++he;
        if(y==tar) break;
        z=f1(y);if(!m[z/10]) {q[++ta]=z;w[ta]=1;m[z/10]=1;pre[ta]=he-1;}
        z=f2(y);if(!m[z/10]) {q[++ta]=z;w[ta]=2;m[z/10]=1;pre[ta]=he-1;}
        z=f3(y);if(!m[z/10]) {q[++ta]=z;w[ta]=3;m[z/10]=1;pre[ta]=he-1;}
    }
    int tmp=he-1;
    while(pre[tmp])
    {
        ans[++lans]=w[tmp];
        tmp=pre[tmp];
    }
    cout<<lans<<endl;
    for(int i=lans;i>=1;--i)
    {
        if(ans[i]==1) cout<<"A";
        else if(ans[i]==2) cout<<"B";
        else cout<<"C";
    }
    cout<<endl;
    return 0;
}
