/*ID: 5120309052
PROG: frac1
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

struct node
{
    int x,y;
    node *next;
    node(int xx=0,int yy=1,node *nn=NULL):x(xx),y(yy),next(nn) {reduce();}
    void reduce()
    {
        if(x==0) y=1;
        else
        {
            for(int i=2;i<=x;++i)
            {
                while(x%i==0&&y%i==0) {x/=i;y/=i;}
            }
        }
    }
};

node *head;
int n;
int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    cin>>n;
    head=new node(0,1);
    node *p,*q,*pp;
    pp=new node(1,1);head->next=pp;
    for(int i=2;i<=n;++i)
    {
        p=head->next;pp=head;
        for(int j=1;j<i;++j)
        {
            q=new node(j,i);
            if(q->y==i)
            {
                while(p&&(p->x)*i<(p->y)*j) {p=p->next;pp=pp->next;}
                if(p) {pp->next=q;q->next=p;p=q;}
                else {pp->next=q;p=q;}
            }
        }
    }
    p=head;
    while(p)
    {
        cout<<p->x<<"/"<<p->y<<endl;
        p=p->next;
    }
    return 0;
}
