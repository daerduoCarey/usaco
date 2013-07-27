/*ID: 5120309052
PROG: rect1
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,m,tot;
int ans[2501]={0};
int x1[1001]={0},x2[1001]={0},y1[1001]={0},y2[1001]={0},color[1001]={0};
int min1(int x,int y) {if(x<y) return x; else return y;}
int max1(int x,int y) {if(x>y) return x; else return y;}
void cover(int c,int x,int y,int xx,int yy,int k)
{
    if(k>tot) {ans[c]+=(xx-x+1)*(yy-y+1);return ;}
    if(x>xx||y>yy) return;
    if(y1[k]>=y&&y1[k]<=yy) {cover(c,x,y,xx,min1(yy,y1[k]-1),k+1);y=y1[k];}
    else if(y1[k]>yy) {cover(c,x,y,xx,yy,k+1);return ;}
    if(y2[k]<=yy&&y2[k]>=y) {cover(c,x,max1(y,y2[k]+1),xx,yy,k+1);yy=y2[k];}
    else if(y2[k]<y) {cover(c,x,y,xx,yy,k+1);return ;}
    if(x1[k]>=x&&x1[k]<=xx) {cover(c,x,y,min1(xx,x1[k]-1),yy,k+1);x=x1[k];}
    else if(x1[k]>xx) {cover(c,x,y,xx,yy,k+1);return ;}
    if(x2[k]<=xx&&x2[k]>=x) {cover(c,max1(x,x2[k]+1),y,xx,yy,k+1);xx=x2[k];}
    else if(x2[k]<x) {cover(c,x,y,xx,yy,k+1);return ;}
}
int main()
{
    freopen("rect1.in","r",stdin);
    freopen("rect1.out","w",stdout);
    cin>>n>>m>>tot;
    for(int i=1;i<=tot;++i)
    {
        cin>>y1[i]>>x1[i]>>y2[i]>>x2[i]>>color[i];
        --x2[i];--y2[i];
    }
    for(int i=tot;i>=1;--i)
        cover(color[i],x1[i],y1[i],x2[i],y2[i],i+1);
    cover(1,0,0,m-1,n-1,1);
    for(int i=1;i<=2500;++i)
        if(ans[i]) cout<<i<<" "<<ans[i]<<endl;
    return 0;
}
