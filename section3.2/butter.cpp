/*ID: 5120309052
PROG: butter
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
const int MAX_INT=1000000;
int n,p,c,he,ta;
int x[501]={0};
struct node
{
    int d,e;
    node* next;
    node(int dd=0,int ee=0,node* nn=NULL):d(dd),e(ee),next(nn) {}
}a[801];
int f[801]={0},m[801]={0},q[10001]={0};
int main()
{
    freopen("butter.in","r",stdin);
    freopen("butter.out","w",stdout);
    cin>>n>>p>>c;int xx,yy,zz;
    for(int i=1;i<=n;++i) cin>>x[i];
    node *qq,*pp;
    for(int i=1;i<=c;++i)
    {
        cin>>xx>>yy>>zz;
        pp=&a[xx];
        qq=new node(yy,zz,pp->next);
        pp->next=qq;
        pp=&a[yy];
        qq=new node(xx,zz,pp->next);
        pp->next=qq;
    }
    int mi=-1;
    for(int i=1;i<=p;++i)
    {
        for(int j=1;j<=p;++j) {f[j]=MAX_INT;m[j]=0;}
        f[i]=0;
        q[1]=i;he=ta=1;m[i]=1;
        while(he<=ta)
        {
            int tmp=q[he];++he;
            pp=&a[tmp];
            while(pp->next)
            {
                if(pp->next->e+f[tmp]<f[pp->next->d])
                {
                    f[pp->next->d]=pp->next->e+f[tmp];
                    if(!m[pp->next->d]) q[++ta]=pp->next->d;
                }
                pp=pp->next;
            }
            m[tmp]=0;
        }
        int sum=0;
        for(int j=1;j<=n;++j) sum+=f[x[j]];
        if(mi==-1||sum<mi) mi=sum;
    }
    cout<<mi<<endl;
    return 0;
}
