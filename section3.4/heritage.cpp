/*
ID: 5120309052
LANG: C++
TASK: heritage
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char qx[27],zx[27],hx[27];
int l;
void dod(int qxl,int qxr,int zxl,int zxr,int hxl,int hxr)
{
    if(qxl>qxr) return;
    else if(qxl==qxr) hx[hxl]=qx[qxl];
    else
    {
        char tmp=qx[qxl];
        hx[hxr]=tmp;
        int k=zxl;
        while(zx[k]!=tmp) ++k;
        int s=k-zxl;
        dod(qxl+1,qxl+s,zxl,k-1,hxl,hxl+s-1);
        dod(qxl+s+1,qxr,k+1,zxr,hxl+s,hxr-1);
    }
}
int main()
{
    freopen("heritage.in","r",stdin);
    freopen("heritage.out","w",stdout);
    scanf("%s",zx);scanf("%s",qx);l=strlen(zx);
    dod(0,l-1,0,l-1,0,l-1);
    for(int i=0;i<l;++i) printf("%c",hx[i]);
    printf("\n");
    return 0;
}
