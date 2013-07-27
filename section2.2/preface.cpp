/*ID: 5120309052
PROG: preface
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int a[10]={0};
void dod(int x)
{
    int y;
    for(int i=1;i<=7;i+=2)
    {
        y=x%10;
        if(y<=3) a[i]+=y;
        else if(y==4||y==6) {++a[i];++a[i+1];}
        else if(y==5) ++a[i+1];
        else if(y==7) {++a[i+1];a[i]+=2;}
        else if(y==8) {++a[i+1];a[i]+=3;}
        else if(y==9) {++a[i+2];++a[i];}
        x/=10;
    }
}
char get(int x)
{
    if(x==1) return 'I';
    else if(x==2) return 'V';
    else if(x==3) return 'X';
    else if(x==4) return 'L';
    else if(x==5) return 'C';
    else if(x==6) return 'D';
    else if(x==7) return 'M';
}
int main()
{
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        dod(i);
    }
    for(int i=1;i<=7;++i)
        if(a[i]) cout<<get(i)<<" "<<a[i]<<endl;
    return 0;
}
