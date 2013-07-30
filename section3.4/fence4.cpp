/*
ID: 5120309052
LANG: C++
TASK: fence4
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
    int i,j;
}ans[201];
bool cmp(node a,node b)
{
    if(a.j<b.j||(a.j==b.j&&a.i<b.i)) return true;
    else return false;
}
int n;
int x[200]={0},y[200]={0};
double xx,yy;
double abs(double x) {if(x<0) return -x; return x;}
double det(double a1,double a2,double a3,double a4)
{
    return a1*a4-a2*a3;
}
bool cross(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
    if(det(x2-x1,y2-y1,x3-x1,y3-y1)*det(x2-x1,y2-y1,x4-x1,y4-y1)>0) return false;
    else
    {
        if(det(x2-x1,y2-y1,x3-x1,y3-y1)==0&&det(x2-x1,y2-y1,x4-x1,y4-y1)==0)
        {
            double minx=min(x1,x2),maxx=max(x1,x2);
            if(minx==maxx)
            {
                if((y3>max(y1,y2)&&y4>max(y1,y2))||(y3<max(y1,y2)&&y4<max(y1,y2))) return false;
                else return true;
            }
            if((x4>maxx&&x3>maxx)||(x3<minx&&x4<minx)) return false;
            else return true;
        }
        else if(det(x2-x1,y2-y1,x3-x1,y3-y1)==0)
        {
            double minx=min(x1,x2),maxx=max(x1,x2);
            if(minx==maxx)
            {
                if(y3>max(y1,y2)||y3<min(y1,y2)) return false;
                else return false;
            }
            if(x3>=minx&&x3<=maxx) return true;
        }
        else if(det(x2-x1,y2-y1,x4-x1,y4-y1)==0)
        {
            double minx=min(x1,x2),maxx=max(x1,x2);
            if(minx==maxx)
            {
                if(y4>max(y1,y2)||y4<min(y1,y2)) return false;
                else return false;
            }
            if(x4>=minx&&x4<=maxx) return true;
        }
    }
    if(det(x4-x3,y4-y3,x1-x3,y1-y3)*det(x4-x3,y4-y3,x2-x3,y2-y3)>0) return false;
    else
    {
        if(det(x4-x3,y4-y3,x1-x3,y1-y3)==0&&det(x4-x3,y4-y3,x2-x3,y2-y3)==0)
        {
            double minx=min(x3,x4),maxx=max(x3,x4);
            if(minx==maxx)
            {
                if((y1>max(y3,y4)&&y2>max(y3,y4))||(y1<max(y3,y4)&&y2<max(y3,y4))) return false;
                else return true;
            }
            if((x1>maxx&&x2>maxx)||(x1<minx&&x2<minx)) return false;
            else return true;
        }
        else if(det(x4-x3,y4-y3,x1-x3,y1-y3)==0)
        {
            double minx=min(x3,x4),maxx=max(x3,x4);
            if(minx==maxx)
            {
                if(y1>max(y1,y2)||y1<min(y1,y2)) return false;
                else return false;
            }
            if(x1>=minx&&x1<=maxx) return true;
        }
        else if(det(x4-x3,y4-y3,x2-x3,y2-y3)==0)
        {
            double minx=min(x3,x4),maxx=max(x3,x4);
            if(minx==maxx)
            {
                if(y2>max(y1,y2)||y2<min(y1,y2)) return false;
                else return false;
            }
            if(x2>=minx&&x2<=maxx) return true;
        }
    }
    return true;
}
bool check()
{
    int f=1;
    for(int i=0;i<n;++i)
        for(int j=0;j<n&&f;++j)
        {
            if(i==j||i==(j+1)%n||j==(i+1)%n) continue;
            if(cross(x[i],y[i],x[(i+1)%n],y[(i+1)%n],x[j],y[j],x[(j+1)%n],y[(j+1)%n]))
            {
                printf("%d %d %d %d %d %d %d %d \n",x[i],y[i],x[(i+1)%n],y[(i+1)%n],x[j],y[j],x[(j+1)%n],y[(j+1)%n]);
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
            double k,b,f=0,len,st=0.001,maxx=max(x[i],x[j]);
            len=sqrt((x[i]-x[j])*(x[i]-x[j])*1.0+(y[i]-y[j])*(y[i]-y[j]));
            //printf("%d:(%d,%d)=>%d:(%d,%d)\n",i,x[i],y[i],j,x[j],y[j]);
            if(x[j]==x[i]) f=1;
            else
            {
                k=(y[j]-y[i])*1.0/(x[j]-x[i]);
                b=y[i]-k*x[i];
            }
            if(!f){
                double cx;
                cx=min(x[i],x[j]);
                cx+=st*len;
                while(cx<maxx)
                {
                    double cy=k*cx+b;
                    int fff=1;
                    for(int jj=0;jj<n;++jj)
                    {
                        int ii=(jj+n-1)%n;
                        if(ii!=i&&cross(cx,cy,xx,yy,x[ii],y[ii],x[jj],y[jj]))
                        {
                            fff=0;break;
                        }
                    }
                    if(fff) break;
                    cx+=st*len;
                }
                if(cx<maxx) {
                    if(i==n-1) {++tot;ans[tot].i=0;ans[tot].j=n-1;}
                    else {++tot;ans[tot].i=i;ans[tot].j=j;}
                }
            }
            else
            {
                double cx=x[i],cy=min(y[i],y[j]),maxx=max(y[i],y[j]);
                double len=maxx-cy,st=0.001;
                cy+=st*len;
                while(cy<maxx)
                {
                    int fff=1;
                    for(int jj=0;jj<n;++jj)
                    {
                        int ii=(jj+n-1)%n;
                        if(ii!=i&&cross(cx,cy,xx,yy,x[ii],y[ii],x[jj],y[jj]))
                        {
                            fff=0;break;
                        }
                    }
                    if(fff) break;
                    cy+=st*len;
                }
                if(cy<maxx) {
                    if(i==n-1) {++tot;ans[tot].i=0;ans[tot].j=n-1;}
                    else {++tot;ans[tot].i=i;ans[tot].j=j;}
                }
            }
        }
        cout<<tot<<endl;
        sort(ans+1,ans+tot+1,cmp);
        for(int i=1;i<=tot;++i)
        {
            int tt=ans[i].i,ttt=ans[i].j;
            cout<<x[tt]<<" "<<y[tt]<<" "<<x[ttt]<<" "<<y[ttt]<<endl;
        }
    }
    else cout<<"NOFENCE\n";
    return 0;
}
