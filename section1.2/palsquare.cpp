/*
ID: 5120309052
PROG: palsquare
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int b;
int main()
{
    int a[20]={0},l;
    int aa[20]={0},ll;
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    cin>>b;
    for(int i=1;i<=300;++i)
    {
        int x=i*i,xx=x,f=1;
        l=0;
        while(xx) {a[++l]=xx%b;xx/=b;}
        for(int j=1;j<=l/2;++j)
            if(a[j]!=a[l-j+1]) {f=0;break;}
        if(f)
        {
            int y=i;
            ll=0;
            while(y) {aa[++ll]=y%b;y/=b;}
            for(int j=ll;j>=1;--j)
            {
                if(aa[j]<10) cout<<aa[j];
                else cout<<char(aa[j]-10+'A');
            }
            cout<<" ";
            for(int j=l;j>=1;--j)
            {
                if(a[j]<10) cout<<a[j];
                else cout<<char(a[j]-10+'A');
            }
            cout<<endl;
        }
    }
    return 0;
};
