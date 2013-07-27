/*ID: 5120309052
PROG: fact4
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,x=1,y;
int p[4]={6,2,4,8};
int main()
{
    freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);
    cin>>n;
    y=0;
    int f,xx;
    for(int i=2;i<=n;++i)
    {
        xx=i;
        f=0;
        while(xx%2==0) {++f;xx/=2;}
        y+=f;
        f=0;
        while(xx%5==0) {++f;xx/=5;}
        y-=f;
        x=(x*xx)%10;
    }
    if(y) x=(x*p[y%4])%10;
    else x=x%10;
    cout<<x<<endl;
    return 0;
}
