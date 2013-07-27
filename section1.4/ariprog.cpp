/*
ID: 5120309052
PROG: ariprog
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int cc[250*250*2+1]={0},aa[250*250*2+1]={0},la=0,bb[250*250*2+1]={0},bbb[250*250*2+1]={0},lb=0;
int n,m;
int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<=m;++i)
        for(int j=i;j<=m;++j)
    {
        cc[i*i+j*j]=1;
    }
    for(int i=0;i<=m*m*2;++i)
    {
        if(cc[i]) aa[++la]=i;
    }
    //for(int i=1;i<=la;++i) cout<<aa[i]<<" ";cout<<endl;
    for(int i=2;i<=la;++i) for(int j=1;j<i;++j) bb[aa[i]-aa[j]]=1;
    for(int i=1;i<=m*m*2;++i) if(bb[i]) bbb[++lb]=i;
    //for(int i=1;i<=lb;++i) cout<<bbb[i]<<" ";cout<<endl;
    int ff=0;
    for(int i=1;i<=lb;++i)
        for(int j=1;j<=la;++j)
        {
            int f=1;
            if((n-1)*bbb[i]+aa[j]>m*m+m*m) break;
            for(int k=1;k<n;++k)
            {
                if(!cc[k*bbb[i]+aa[j]]) {f=0;break;}
            }
            if(f) {printf("%d %d\n",aa[j],bbb[i]);ff=1;}
        }
    if(!ff) printf("NONE\n");
    return 0;
}
