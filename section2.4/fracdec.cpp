/*ID: 5120309052
PROG: fracdec
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a,b;
int f[100001]={0},x[100001]={0};
int l[100001]={0},ll=0;
int main()
{
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    cin>>a>>b;
    int tot=0;
    int xx=a/b;
    if(xx==0) ++tot;
    while(xx) {++tot;xx/=10;}
    ++tot;
    cout<<a/b<<".";
    a=a%b;
    while(!f[a]&&a)
    {
        ++ll;
        f[a]=1;x[a]=ll;
        a*=10;
        l[ll]=a/b;
        a=a%b;
    }

    int beg=x[a];
    if(a==0)  {
        if(ll==0) cout<<0;
        else
            for(int i=1;i<=ll;++i) {++tot;if(tot%76==1) cout<<endl; cout<<l[i];}
    }
    else{
        for(int i=1;i<beg;++i) {++tot;if(tot%76==1) cout<<endl; cout<<l[i];}
        ++tot;if(tot%76==1) cout<<endl; cout<<"(";
        for(int i=beg;i<=ll;++i) {++tot;if(tot%76==1) cout<<endl; cout<<l[i];}
        ++tot;if(tot%76==1) cout<<endl; cout<<")";
    }
    cout<<endl;
    return 0;
}
