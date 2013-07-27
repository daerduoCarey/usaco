/*
ID: 5120309052
PROG: beads
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n;char s[350];int mar[350]={0};
int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    cin>>n;cin>>s;
    int sum,max=0;
    int f1=0,f2=0;
    for(int i=0;i<n;++i) if(s[i]=='r') f1=1; else if(s[i]=='b') f2=1;
    if(!f1||!f2) {cout<<n<<endl;return 0;}
    for(int i=0;i<n;++i)
    {
        memset(mar,0,sizeof(mar));
        if(s[i]!=s[(i-1+n)%n])
        {
            char x=s[(i-1+n)%n];int k=(i-1+n)%n;
            if(x=='w')
                while(s[k]=='w')
                {
                    mar[k]=1;k=(k-1+n)%n;
                }
            x=s[k];
            while(s[k]=='w'||s[k]==x)
            {
                mar[k]=1;k=(k-1+n)%n;
            }

            x=s[i];k=i;
            if(x=='w')
                while(s[k]=='w')
                {
                    mar[k]=1;k=(k+1)%n;
                }
            x=s[k];
            while(s[k]=='w'||s[k]==x)
            {
                mar[k]=1;k=(k+1)%n;
            }
            sum=0;
            for(int i=0;i<n;++i) if(mar[i]) ++sum;
            if(sum>max) max=sum;
        }
    }
    cout<<max<<endl;
    return 0;
}
