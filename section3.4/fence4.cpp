/*
ID: 5120309052
LANG: C++
TASK: fence4
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n;
int x[200]={0},y[200]={0};
long long xx,yy;
long long abs(long long x) {if(x<0) return -x; return x;}
long long det(long long a1,long long a2,long long a3,long long a4)
{
    return a1*a4-a2*a3;
}
bool cross(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3,long long x4,long long y4)
{
    //cout<<det(x2-x1,y2-y1,x3-x1,y3-y1)<<" "<<det(x2-x1,y2-y1,x4-x1,y4-y1)<<endl;
    if(det(x2-x1,y2-y1,x3-x1,y3-y1)*det(x2-x1,y2-y1,x4-x1,y4-y1)>0) return false;
    else
    {
        if(det(x2-x1,y2-y1,x3-x1,y3-y1)==0&&det(x2-x1,y2-y1,x4-x1,y4-y1)==0)
        {
            long long minx=min(x1,x2),maxx=max(x1,x2);
            if((x4>maxx&&x3>maxx)||(x3<minx&&x4<minx)) return false;
            else return true;
        }
        else if(det(x2-x1,y2-y1,x3-x1,y3-y1)==0)
        {
            long long minx=min(x1,x2),maxx=max(x1,x2);
            if(x3>=minx&&x3<=maxx) return true;
        }
        else if(det(x2-x1,y2-y1,x4-x1,y4-y1)==0)
        {
            long long minx=min(x1,x2),maxx=max(x1,x2);
            if(x4>=minx&&x4<=maxx) return true;
        }
    }
    //cout<<det(x2-x1,y2-y1,x3-x1,y3-y1)<<" "<<det(x2-x1,y2-y1,x4-x1,y4-y1)<<endl;
    if(det(x4-x3,y4-y3,x1-x3,y1-y3)*det(x4-x3,y4-y3,x2-x3,y2-y3)>0) return false;
    else
    {
        if(det(x4-x3,y4-y3,x1-x3,y1-y3)==0&&det(x4-x3,y4-y3,x2-x3,y2-y3)==0)
        {
            long long minx=min(x3,x4),maxx=max(x3,x4);
            if((x1>maxx&&x2>maxx)||(x1<minx&&x2<minx)) return false;
            else return true;
        }
        else if(det(x4-x3,y4-y3,x1-x3,y1-y3)==0)
        {
            long long minx=min(x3,x4),maxx=max(x3,x4);
            if(x1>=minx&&x1<=maxx) return true;
        }
        else if(det(x4-x3,y4-y3,x2-x3,y2-y3)==0)
        {
            long long minx=min(x3,x4),maxx=max(x3,x4);
            if(x2>=minx&&x2<=maxx) return true;
        }
    }
    return true;
}
bool check()
{
    int f=1;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            //cout<<"@"<<i<<" "<<j<<endl;
            //printf("(%d,%d) (%d,%d) (%d,%d) (%d,%d)\n",x[i],y[i],x[(i+1)%n],y[(i+1)%n],x[j],y[j],x[(j+1)%n],y[(j+1)%n]);
            if(i==j||i==(j+1)%n||j==(i+1)%n) continue;
            if(cross(x[i],y[i],x[(i+1)%n],y[(i+1)%n],x[j],y[j],x[(j+1)%n],y[(j+1)%n]))
            {
                f=0;break;
            }
        }
    return f;
}
int tot=0;
int ansi[201]={0},ansj[201]={0};
int main()
{
    freopen("fence4.in","r",stdin);
    freopen("fence4.out","w",stdout);
    cin>>n;cin>>xx>>yy;
    for(int i=0;i<n;++i) cin>>x[i]>>y[i];
    if(check())
    {
        for(int j=0;j<n;++j)
        {
            int i=(j+n-1)%n;
            int f1=1,f2=1;
            for(int k=0;k<n;++k)
                if(k!=i&&k!=(i+n-1)%n&&cross(xx,yy,x[i],y[i],x[k],y[k],x[(k+1)%n],y[(k+1)%n]))
                    {f1=0;break;}
            for(int k=0;k<n;++k)
                if(k!=i&&k!=(i+1)%n&&cross(xx,yy,x[j],y[j],x[k],y[k],x[(k+1)%n],y[(k+1)%n]))
                    {f2=0;break;}
            if(f1||f2)
            {

                ++tot;ansi[tot]=i;ansj[tot]=j;
                if(i==n-1) {ansi[tot]=0;ansj[tot]=n-1;}
            }
        }
        cout<<tot<<endl;
        for(int i=1;i<tot;++i)
            for(int j=1;j<i;++j)
                if(ansj[i]<ansj[j])
                {
                    int tmp=ansi[i];ansi[i]=ansi[j];ansi[j]=tmp;
                    tmp=ansj[i];ansj[i]=ansj[j];ansj[j]=tmp;
                }
        for(int i=1;i<=tot;++i)
        {
            int tt=ansi[i],ttt=ansj[i];
            cout<<x[tt]<<" "<<y[tt]<<" "<<x[ttt]<<" "<<y[ttt]<<endl;
        }
    }
    else cout<<"NOFENCE\n";
    return 0;
}
