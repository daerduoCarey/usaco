/*ID: 5120309052
PROG: maze1
LANG: C++
*/

#include<iostream>
#include<cstdio>

using namespace std;
int m,n;
char c[400][400];
int a[3][200][200]={0},b[3][200][200]={0};
int qx[500]={0},qy[500]={0},he,ta;
int min1(int x,int y) {if(x<y) return x; else return y;}
int main()
{
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    cin>>n>>m;getchar();
    for(int i=1;i<=2*m+1;++i)
    {
        int f=1;
        for(int j=1;j<=2*n+1;++j)
        {
            c[i][j]=getchar();
            if(c[i][j]=='\n')
                while(j<=2*n+1) {c[i][j]=' ';++j;f=0;}
        }
        if(f) getchar();
    }
    /*for(int i=1;i<=2*m+1;++i)
    {
        for(int j=1;j<=2*n+1;++j)
            cout<<c[i][j];
        cout<<endl;
    }*/
    int k=0;
    int x[3],y[3];
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            a[1][i][j]=a[2][i][j]=1000000;
    for(int i=1;i<=n;++i)
        if(c[1][2*i]==' ') {++k;a[k][1][i]=1;x[k]=1;y[k]=i;c[1][2*i]='-';}
    for(int i=1;i<=n;++i)
        if(c[2*m+1][2*i]==' ') {++k;a[k][m][i]=1;x[k]=m;y[k]=i;c[2*m+1][2*i]='-';}
    for(int i=1;i<=m;++i)
        if(c[2*i][1]==' ') {++k;a[k][i][1]=1;x[k]=i;y[k]=1;c[2*i][1]='|';}
    for(int i=1;i<=m;++i)
        if(c[2*i][2*n+1]==' ') {++k;a[k][i][n]=1;x[k]=i;y[k]=n;c[2*i][2*n+1]='|';}
    he=ta=1;qx[1]=x[1];qy[1]=y[1];b[1][qx[1]][qy[1]]=1;
    while(he<=ta)
    {
        int x=qx[he],y=qy[he];++he;
        if(c[2*x-1][2*y]==' '&&!b[1][x-1][y]) {qx[++ta]=x-1;qy[ta]=y;a[1][x-1][y]=a[1][x][y]+1;b[1][x-1][y]=1;}
        if(c[2*x+1][2*y]==' '&&!b[1][x+1][y]) {qx[++ta]=x+1;qy[ta]=y;a[1][x+1][y]=a[1][x][y]+1;b[1][x+1][y]=1;}
        if(c[2*x][2*y-1]==' '&&!b[1][x][y-1]) {qx[++ta]=x;qy[ta]=y-1;a[1][x][y-1]=a[1][x][y]+1;b[1][x][y-1]=1;}
        if(c[2*x][2*y+1]==' '&&!b[1][x][y+1]) {qx[++ta]=x;qy[ta]=y+1;a[1][x][y+1]=a[1][x][y]+1;b[1][x][y+1]=1;}
    }
    he=ta=1;qx[1]=x[2];qy[1]=y[2];b[2][qx[1]][qy[1]]=1;
    while(he<=ta)
    {
        int x=qx[he],y=qy[he];++he;
        if(c[2*x-1][2*y]==' '&&!b[2][x-1][y]) {qx[++ta]=x-1;qy[ta]=y;a[2][x-1][y]=a[2][x][y]+1;b[2][x-1][y]=1;}
        if(c[2*x+1][2*y]==' '&&!b[2][x+1][y]) {qx[++ta]=x+1;qy[ta]=y;a[2][x+1][y]=a[2][x][y]+1;b[2][x+1][y]=1;}
        if(c[2*x][2*y-1]==' '&&!b[2][x][y-1]) {qx[++ta]=x;qy[ta]=y-1;a[2][x][y-1]=a[2][x][y]+1;b[2][x][y-1]=1;}
        if(c[2*x][2*y+1]==' '&&!b[2][x][y+1]) {qx[++ta]=x;qy[ta]=y+1;a[2][x][y+1]=a[2][x][y]+1;b[2][x][y+1]=1;}
    }
    int ans=0;
    /*for(int i=1;i<=m;++i)
        {for(int j=1;j<=n;++j)
            if(a[1][i][j]==1000000) cout<<"* ";
            else cout<<a[1][i][j]<<" ";
        cout<<endl;}
    cout<<endl;
    for(int i=1;i<=m;++i)
        {for(int j=1;j<=n;++j)
            if(a[2][i][j]==1000000) cout<<"* ";
            else cout<<a[2][i][j]<<" ";
        cout<<endl;}*/
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(min1(a[1][i][j],a[2][i][j])>ans)
                ans=min1(a[1][i][j],a[2][i][j]);
    cout<<ans<<endl;
    return 0;
}
