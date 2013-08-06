/*
ID: 5120309052
TASK: frameup
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int m,n,tot=0;
char c[31][31],d[27]={0},a[27][27]={0};
int lx[27]={0},rx[27]={0},ly[27]={0},ry[27]={0};
int ans[27]={0},deg[27]={0};
void dfs(int k)
{
    if(k>tot)
    {
        for(int i=1;i<=tot;++i) cout<<char(ans[i]+'A'-1);
        cout<<endl;
        return;
    }
    for(int i=1;i<=26;++i)
        if(!d[i]&&!deg[i])
        {
            ans[k]=i;d[i]=1;
            for(int j=1;j<=26;++j)
                if(a[i][j]) --deg[j];
            dfs(k+1);
            d[i]=0;
            for(int j=1;j<=26;++j)
                if(a[i][j]) ++deg[j];
        }
}
int main()
{
    freopen("frameup.in","r",stdin);
    freopen("frameup.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=26;++i) d[i]=1;
    for(int i=1;i<=m;++i)
    {
        getchar();
        for(int j=1;j<=n;++j)
        {
            c[i][j]=getchar();
            if(c[i][j]>='A'&&c[i][j]<='Z')
            {
                int ct=c[i][j]-'A'+1;
                if(d[ct]) ++tot;
                d[ct]=0;
                if(lx[ct]==0||i<lx[ct]) lx[ct]=i;
                if(rx[ct]==0||i>rx[ct]) rx[ct]=i;
                if(ly[ct]==0||j<ly[ct]) ly[ct]=j;
                if(ry[ct]==0||j>ry[ct]) ry[ct]=j;
            }
        }
    }
    for(int i=1;i<=26;++i)
        if(!d[i])
        {
            int yy=ly[i];
            for(int j=lx[i];j<=rx[i];++j)
                if(c[j][yy]-'A'+1!=i)
                {
                    if(!a[i][c[j][yy]-'A'+1])
                        ++deg[c[j][yy]-'A'+1];
                    a[i][c[j][yy]-'A'+1]=1;
                }
            yy=ry[i];
            for(int j=lx[i];j<=rx[i];++j)
                if(c[j][yy]-'A'+1!=i)
                {
                    if(!a[i][c[j][yy]-'A'+1])
                        ++deg[c[j][yy]-'A'+1];
                    a[i][c[j][yy]-'A'+1]=1;
                }
            int xx=lx[i];
            for(int j=ly[i];j<=ry[i];++j)
                if(c[xx][j]-'A'+1!=i)
                {
                    if(!a[i][c[xx][j]-'A'+1])
                        ++deg[c[xx][j]-'A'+1];
                    a[i][c[xx][j]-'A'+1]=1;
                }
            xx=rx[i];
            for(int j=ly[i];j<=ry[i];++j)
                if(c[xx][j]-'A'+1!=i)
                {
                    if(!a[i][c[xx][j]-'A'+1])
                        ++deg[c[xx][j]-'A'+1];
                    a[i][c[xx][j]-'A'+1]=1;
                }
        }
    dfs(1);
    return 0;
}
