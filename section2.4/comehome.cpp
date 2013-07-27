/*ID: 5120309052
PROG: comehome
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int p,n=0;
int c[200],m[200];
int a[200][200]={0};
int main()
{
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    cin>>p;char c1,c2;int x;
    for(int i=1;i<=p;++i)
    {
        c1=getchar();while(c1==' '||c1=='\n') c1=getchar();
        c2=getchar();while(c2==' '||c2=='\n') c2=getchar();
        cin>>x;
        if(c1!=c2){
        int t1,t2;
        if(c1>='a'&&c1<='z') t1=c1-'a'+1;
        else t1=c1-'A'+27;
        if(c2>='a'&&c2<='z') t2=c2-'a'+1;
        else t2=c2-'A'+27;
        if(!a[t1][t2]||a[t1][t2]>x) a[t1][t2]=a[t2][t1]=x;
        }
    }
    int t=52;
    for(int i=1;i<52;++i) c[i]=-1;
    for(int i=1;i<52;++i)
    {
        m[t]=1;
        for(int j=1;j<=52;++j)
        {
            if(a[t][j]>0)
            {
                if(c[j]==-1) c[j]=a[t][j]+c[t];
                else if(a[t][j]+c[t]<c[j]) c[j]=a[t][j]+c[t];
            }
        }
        int mi=-1,mint;
        for(int j=1;j<=52;++j)
            if(!m[j]&&(mi==-1||c[j]<mi)&&c[j]>0) {mi=c[j];mint=j;}
        if(mi<0) break;
        t=mint;
    }
    int mi=-1,mini;
    for(int i=27;i<=51;++i)
    {
        if(mi==-1||c[i]<mi) if(c[i]>0) {mi=c[i];mini=i;}
        //cout<<char(i-27+'A')<<" "<<mi<<endl;
    }
    cout<<char(mini-27+'A')<<" "<<mi<<endl;
    return 0;
}
