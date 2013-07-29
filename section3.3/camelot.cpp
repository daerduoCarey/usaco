/*ID: 5120309052
PROG: camelot
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

const int MAX_INT=10000000;
int cx[9]={0,-1,-2,-2,-1,1,2,2,1},cy[9]={0,-2,-1,1,2,2,1,-1,-2};
int tot=0,m,n,ans=MAX_INT;
int x[1000]={0},y[1000]={0};
int kingx,kingy;
int qx[100000]={0},qs[100000]={0},qy[100000]={0},he,ta;
int f[31][31][2]={0},mm[31][31][2]={0};

int dis(int x1,int y1,int x2,int y2)
{
    return max(abs(x1-x2),abs(y1-y2));
}
int main()
{
    freopen("camelot.in","r",stdin);
    freopen("camelot.out","w",stdout);
    cin>>m>>n;
    char c;int xx;
    cin>>c>>xx;
    kingx=xx;kingy=c-'A'+1;
    while(cin>>c>>xx)
    {
        ++tot;
        x[tot]=xx;y[tot]=c-'A'+1;
    }
    if(!tot) {cout<<0<<endl;return 0;}
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
    {
        for(int ii=1;ii<=m;++ii)
            for(int jj=1;jj<=n;++jj)
        {
            f[ii][jj][0]=f[ii][jj][1]=MAX_INT;
            mm[ii][jj][1]=mm[ii][jj][1]=0;
        }
        he=ta=1;qx[1]=i;qy[1]=j;qs[1]=0;f[i][j][0]=0;mm[i][j][0]=1;
        while(he<=ta)
        {
            int tx=qx[he],ty=qy[he],ts=qs[he];++he;
            for(int kk=1;kk<=8;++kk)
            {
                if(tx+cx[kk]>=1&&tx+cx[kk]<=m&&ty+cy[kk]>=1&&ty+cy[kk]<=n&&f[tx+cx[kk]][ty+cy[kk]][ts]>f[tx][ty][ts]+1)
                {
                    f[tx+cx[kk]][ty+cy[kk]][ts]=f[tx][ty][ts]+1;
                    if(!mm[tx+cx[kk]][ty+cy[kk]][ts])
                    {
                        ++ta;qx[ta]=tx+cx[kk];qy[ta]=ty+cy[kk];qs[ta]=ts;
                        mm[tx+cx[kk]][ty+cy[kk]][ts]=1;
                    }
                }
            }
            if(!ts)
            {
                if(f[tx][ty][1]>f[tx][ty][0]+dis(kingx,kingy,tx,ty))
                {
                    f[tx][ty][1]=f[tx][ty][0]+dis(kingx,kingy,tx,ty);
                    if(!mm[tx][ty][1])
                    {
                        ++ta;qx[ta]=tx;qy[ta]=ty;qs[ta]=1;
                        mm[tx][ty][1]=1;
                    }
                }
            }
            mm[tx][ty][ts]=0;
        }
        int total=0;
        for(int j=1;j<=tot;++j) total+=f[x[j]][y[j]][0];
        int mi=-1;
        for(int j=1;j<=tot;++j)
        {
            if(mi==-1||total-f[x[j]][y[j]][0]+f[x[j]][y[j]][1]<mi)
                mi=total-f[x[j]][y[j]][0]+f[x[j]][y[j]][1];
        }
        if(mi<ans) ans=mi;
    }
    cout<<ans<<endl;
    return 0;
}
