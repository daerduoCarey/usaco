/*ID: 5120309052
PROG:pprime
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a,b,la,lb;
int getl(int x)
{
    int xx=x;
    int k=0;
    while(xx) {xx/=10;++k;}
    return k;
}
int sushu(int x)
{
    int f=1;
    for(int i=2;i<=sqrt(x);++i)
        if(x%i==0) {f=0;break;}
    return f;
}
int rev(int x)
{
    int xx=x,y;
    int a[10]={0},la=0;
    while(xx) {a[++la]=xx%10;xx/=10;}
    y=a[1];
    for(int i=2;i<=la;++i) y=y*10+a[i];
    return y;
}
int main()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    cin>>a>>b;
    la=getl(a);lb=getl(b);
    if(la==1)
            for(int i=a;i<=9;++i) if(sushu(i))cout<<i<<endl;
    for(int i=(la>1)? la:2;i<=lb;++i)
    {
        int d=1;
        for(int j=1;j<=i/2-1;++j) d*=10;
        int fff=1;
        for(int j=d;j<d*10&&fff;++j)
        {
            int tmp=rev(j);
            if(i%2)
            {
                for(int k=0;k<=9;++k)
                {
                    if(sushu(d*100*j+d*10*k+tmp))
                    {
                        if(d*100*j+d*10*k+tmp<=b&&d*100*j+d*10*k+tmp>=a) cout<<d*100*j+d*10*k+tmp<<endl;
                        else if(i==lb&&d*100*j+d*10*k+tmp>b) fff=0;
                    }
                }
            }
            else
            {
                if(sushu(d*10*j+tmp))
                {
                    if(d*10*j+tmp<=b&&d*10*j+tmp>=a) cout<<d*10*j+tmp<<endl;
                    else if(i==lb&&d*10*j+tmp>b) fff=0;
                }
            }
        }
    }
    return 0;
}
