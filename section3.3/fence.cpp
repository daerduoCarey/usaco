/*ID: 5120309052
PROG: fence
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int tot;
int a[501][501]={0};
int deg[501]={0};
struct node
{
    int x;
    node *next;
    node(int xx=0,node *nn=NULL):x(xx),next(nn) {}
};
node* dfs(int x)
{
    node *p=new node(x);
    int mini=-1;
    for(int i=1;i<=500;++i)
        if(a[x][i])
    {
        mini=i;
        --a[x][i];--a[i][x];
        --deg[i];--deg[x];
        break;
    }
    if(mini>0) p->next=dfs(mini);
    return p;
}
int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    cin>>tot;
    node *head=new node();
    int x,y,mini=-1;
    for(int i=1;i<=tot;++i)
    {
        cin>>x>>y;
        ++a[x][y];++a[y][x];
        ++deg[x];++deg[y];
        if(x<mini||mini==-1) mini=x;
    }
    int t[3],lt=0;
    for(int i=1;i<=500;++i)
        if(deg[i]%2) t[++lt]=i;
    if(lt&&t[1]<t[2]) head->next=dfs(t[1]);
    else if(lt) head->next=dfs(t[2]);
    else head->next=dfs(mini);
    while(1)
    {
        node *tmp=head,*pos=NULL;
        while(tmp->next)
        {
            if(deg[tmp->next->x]>0) pos=tmp;
            tmp=tmp->next;
        }
        if(pos==NULL) break;
        else
        {
            node *ee,*tt=dfs(pos->next->x);
            ee=tt;
            while(ee->next) {ee=ee->next;}
            ee->next=pos->next->next;
            pos->next=tt;
        }
    }
    while(head->next)
    {
        cout<<head->next->x<<endl;
        head=head->next;
    }
    return 0;
}
