/*ID: 5120309052
PROG: prefix
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[4000][200];char t[300000];char quit[5];
int l=0,ls[4000]={0},lt=0;
int f[300000]={0};
char ccc[300000];
int main()
{
    quit[0]='.';quit[1]='\0';
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    l=0;
    while(scanf("%s",ccc)==1)
    {
        if(strcmp(ccc,quit)==0) break;
        else
        {
            ++l;
            ls[l]=strlen(ccc);
            for(int i=1;i<=ls[l];++i) s[l][i]=ccc[i-1];
        }
    }
    int tmp;
    while(scanf("%s",ccc)==1)
    {
        tmp=strlen(ccc);
        for(int i=0;i<tmp;++i) t[lt+i+1]=ccc[i];
        lt+=tmp;
    }
    f[0]=1;
    for(int j=1;j<=lt;++j)
         for(int i=1;i<=l;++i)
    {
        int ff=1;
        for(int k=j;k>=j-ls[i]+1;--k) if(k<=0||s[i][k+ls[i]-j]!=t[k]) {ff=0;break;}
        if(ff&&f[j-ls[i]]) f[j]=1;
    }

    int k=lt;
    while(!f[k]) --k;
    cout<<k<<endl;
    return 0;
}
