/*ID: 5120309052
PROG: ttwo
LANG: C++
*/

#include<iostream>
#include<cstdio>

using namespace std;
char c[11][11];int st=0,m[11][11][5][11][11][5]={0};
void dod(int x1,int y1,int d1,int x2,int y2,int d2)
{
    if(m[x1][y1][d1][x2][y2][d2]) {cout<<0<<endl;return ;}
    m[x1][y1][d1][x2][y2][d2]=1;
    if(x1==x2&&y1==y2) {cout<<st<<endl;return ;}
    ++st;
    if(d1==1) {if(x1>1&&c[x1-1][y1]!='*') --x1; else d1=(d1+1)%4;}
    else if(d1==2) {if(y1<10&&c[x1][y1+1]!='*') ++y1; else d1=(d1+1)%4;}
    else if(d1==3) {if(x1<10&&c[x1+1][y1]!='*') ++x1; else d1=(d1+1)%4;}
    else {if(y1>1&&c[x1][y1-1]!='*') --y1; else d1=(d1+1)%4;}
    if(d2==1) {if(x2>1&&c[x2-1][y2]!='*') --x2; else d2=(d2+1)%4;}
    else if(d2==2) {if(y2<10&&c[x2][y2+1]!='*') ++y2; else d2=(d2+1)%4;}
    else if(d2==3) {if(x2<10&&c[x2+1][y2]!='*') ++x2; else d2=(d2+1)%4;}
    else {if(y2>1&&c[x2][y2-1]!='*') --y2; else d2=(d2+1)%4;}
    dod(x1,y1,d1,x2,y2,d2);
}
int main()
{
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    int x1,x2,d1,y1,y2,d2;
    for(int i=1;i<=10;++i)
    {
        for(int j=1;j<=10;++j)
        {
            c[i][j]=getchar();
            if(c[i][j]=='F') {x1=i;y1=j;d1=1;}
            if(c[i][j]=='C') {x2=i;y2=j;d2=1;}
        }
        getchar();
    }
    dod(x1,y1,d1,x2,y2,d2);
    return 0;
}
