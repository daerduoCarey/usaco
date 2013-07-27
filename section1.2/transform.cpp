/*
ID: 5120309052
PROG: transform
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n;
char c[11][11],s[11][11];
template<int nn>
bool id(char (&x)[nn][nn],char (&y)[nn][nn])
{
    int f=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(x[i][j]!=y[i][j]) {f=0;break;}
    return f;
}
template<int nn>
bool n1(char (&x)[nn][nn],char (&y)[nn][nn])
{
    int f=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(x[i][j]!=y[j][n-i+1])
    {
        f=0;break;
    }
    return f;
}
template<int nn>
bool n2(char (&x)[nn][nn],char (&y)[nn][nn])
{
    int f=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(x[i][j]!=y[n-i+1][n-j+1])
    {
        f=0;break;
    }
    return f;
}
template<int nn>
bool n3(char (&x)[nn][nn],char (&y)[nn][nn])
{
    int f=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(x[i][j]!=y[n-j+1][i])
    {
        f=0;break;
    }
    return f;
}
template<int nn>
bool n4(char (&x)[nn][nn],char (&y)[nn][nn])
{
    char cc[11][11];
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cc[i][j]=x[i][n-j+1];
    if(id(cc,y)) return true;
    return false;
}
int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    cin>>n;getchar();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            c[i][j]=getchar();
        getchar();
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            s[i][j]=getchar();
        getchar();
    }
    if(n1(c,s)) {cout<<1<<endl;return 0;}
    if(n2(c,s)) {cout<<2<<endl;return 0;}
    if(n3(c,s)) {cout<<3<<endl;return 0;}
    if(n4(c,s)) {cout<<4<<endl;return 0;}
    char cc[11][11];
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cc[i][j]=c[i][n-j+1];
    if(n1(cc,s)||n2(cc,s)||n3(cc,s)) {cout<<5<<endl;return 0;}
    if(id(c,s)) {cout<<6<<endl;return 0;}
    cout<<7<<endl;
    return 0;
}
