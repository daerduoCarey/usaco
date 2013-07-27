/*
ID: 5120309052
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[11][14];char ss[14];int n,x,y;
int num[11]={0};
int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    while(cin>>ss)
    {
        int k=1;
        while(strcmp(ss,s[k])) ++k;
        cin>>x>>y;
        if(!y) continue;
        int tmp=x/y;
        num[k]-=tmp*y;
        for(int i=1;i<=y;++i)
        {
            cin>>ss;
            int k=1;
            while(strcmp(ss,s[k])) ++k;
            num[k]+=tmp;
        }
    }
    for(int i=1;i<=n;++i)
    {
        cout<<s[i]<<" "<<num[i]<<endl;
    }
    return 0;
}
