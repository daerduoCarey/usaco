/*ID: 5120309052
PROG: lamps
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,c;
int q[100]={0},b[100]={0},h[100]={0},ans[100]={0},he,ta;
int a[5]={0},aa[5]={0};
bool fit(int *x,int *y)
{
    int f=1;
    for(int i=1;i<=4;++i)
    {
        if(y[i]!=-1&&x[i]!=y[i]) {f=0;break;}
    }
    return f;
}
int f1(int x)
{
    int tt[5]={0},xx=x;
    for(int i=1;i<=4;++i)
    {
        tt[i]=xx%2;xx/=2;
        tt[i]=(tt[i]+1)%2;
    }
    return tt[1]+tt[2]*2+tt[3]*4+tt[4]*8;
}
int f2(int x)
{
    int tt[5]={0},xx=x;
    for(int i=1;i<=4;++i)
    {
        tt[i]=xx%2;xx/=2;
        if(i==1||i==3) tt[i]=(tt[i]+1)%2;
    }
    return tt[1]+tt[2]*2+tt[3]*4+tt[4]*8;
}
int rev(int x)
{
    int tt[5]={0},xx=x;
    for(int i=1;i<=4;++i) {tt[i]=xx%2;xx/=2;}
    return tt[1]*8+tt[2]*4+tt[3]*2+tt[4];
}
int f3(int x)
{
    int tt[5]={0},xx=x;
    for(int i=1;i<=4;++i)
    {
        tt[i]=xx%2;xx/=2;
        if(i==2||i==4) tt[i]=(tt[i]+1)%2;
    }
    return tt[1]+tt[2]*2+tt[3]*4+tt[4]*8;
}
int f4(int x)
{
    int tt[5]={0},xx=x;
    for(int i=1;i<=4;++i)
    {
        tt[i]=xx%2;xx/=2;
        if(i==1||i==4) tt[i]=(tt[i]+1)%2;
    }
    return tt[1]+tt[2]*2+tt[3]*4+tt[4]*8;
}
int main()
{
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    cin>>n>>c;
    int x;
    for(int i=1;i<=4;++i) a[i]=-1;
    while(cin>>x) {
        if(x==-1) break;
        if(x%6==1) a[1]=1;
        else if(x%6==4) a[4]=1;
        else if(x%6==2||x%6==0) a[2]=1;
        else a[3]=1;
    }
    while(cin>>x) {
        if(x==-1) break;
        if(x%6==1) {if(a[1]==1) {cout<<"IMPOSSIBLE\n";return 0;} else a[1]=0;}
        else if(x%6==4) {if(a[4]==1) {cout<<"IMPOSSIBLE\n";return 0;} else a[4]=0;}
        else if(x%6==2||x%6==0) {if(a[2]==1) {cout<<"IMPOSSIBLE\n";return 0;} else a[2]=0;}
        else {if(a[3]==1) {cout<<"IMPOSSIBLE\n";return 0;} else a[3]=0;}
    }
    x=15;
    q[1]=x;b[x]=1;he=ta=1;h[x]=0;
    while(he<=ta)
    {
        int y=q[he++],yy;yy=y;
        //cout<<y<<endl;
        for(int i=1;i<=4;++i) {aa[i]=yy%2;yy/=2;}
        //for(int i=1;i<=4;++i) cout<<aa[i]<<" ";cout<<endl;
        //for(int i=1;i<=4;++i) cout<<a[i]<<" ";cout<<endl;
        if(fit(aa,a))
        {
            if((c-h[y])%2==0) ans[rev(y)]=1;
            else if(c-h[y]>=3) ans[rev(y)]=1;
        }
        int z=f1(y);if(!b[z]&&h[y]<c) {h[z]=h[y]+1;b[z]=1;q[++ta]=z;}
            z=f2(y);if(!b[z]&&h[y]<c) {h[z]=h[y]+1;b[z]=1;q[++ta]=z;}
            z=f3(y);if(!b[z]&&h[y]<c) {h[z]=h[y]+1;b[z]=1;q[++ta]=z;}
            z=f4(y);if(!b[z]&&h[y]<c) {h[z]=h[y]+1;b[z]=1;q[++ta]=z;}
    }
    int daan[5]={0};
    int tot=0;
    for(int i=0;i<=15;++i)
        if(ans[i])
        {
            tot=1;
            int tmp=rev(i);
            for(int j=1;j<=4;++j) {daan[j]=tmp%2;tmp/=2;}
            for(int k=1;k<=n;++k)
            {
                if(k%6==1) cout<<daan[1];
                else if(k%6==0||k%6==2) cout<<daan[2];
                else if(k%6==4) cout<<daan[4];
                else cout<<daan[3];
            }
            cout<<endl;
        }
    if(!tot) cout<<"IMPOSSIBLE\n";
    return 0;
}
