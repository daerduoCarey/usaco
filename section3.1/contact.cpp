/*ID: 5120309052
PROG: contact
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int a,b,n,l=0;
int s[200001];
int f[13][5001]={0};
int ans[51]={0};
void print(int ll,int x)
{
    int tmp[20]={0},lt=0;
    while(x) {tmp[++lt]=x%2;x/=2;}
    for(int i=1;i<=ll-lt;++i) cout<<0;
    for(int i=lt;i>=1;--i) cout<<tmp[i];
}
int main()
{
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    cin>>a>>b>>n;
    char c;
    c=getchar();
    while(c!=EOF)
    {
        while(c!='0'&&c!='1'&&c!=EOF) c=getchar();
        if(c!=EOF)
        {
            if(c=='0') s[++l]=0;
            else s[++l]=1;
            c=getchar();
        }
    }
    int t,lt;
    for(int i=1;i<=l;++i)
    {
        t=s[i];
        if(i+a-1>l) break;
        for(int j=1;j<a;++j) t=t*2+s[i+j];
        lt=a;
        while(lt<=b&&i+lt-1<=l)
        {
            //cout<<i<<" "<<lt<<" "<<t<<endl;
            ++f[lt][t];
            ++lt;
            t=t*2+s[i+lt-1];
        }
    }

    for(int kk=1;kk<=n;++kk)
    {
        int maxx=0;
        for(int i=0;i<=5000;++i) for(int j=a;j<=b;++j) if(f[j][i]>maxx) maxx=f[j][i];
        if(maxx==0) break;
        cout<<maxx<<endl;
        int ff=0;
        for(int j=a;j<=b;++j)
            for(int i=0;i<=5000;++i)
                if(f[j][i]==maxx)
        {
            ++ff;
            if(ff==1) print(j,i);
            else if(ff%6==1) {cout<<"\n";print(j,i);}
            else {cout<<" ";print(j,i);}
            f[j][i]=0;
        }
        cout<<endl;
    }
    return 0;
}
