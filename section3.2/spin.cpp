/*ID: 5120309052
PROG: spin
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int s[6][6]={0},l[6][6]={0},v[6]={0},tot[6]={0};
int f[361]={0};
int main()
{
    freopen("spin.in","r",stdin);
    freopen("spin.out","w",stdout);
    int x,y;
    for(int i=1;i<=5;++i)
    {
        cin>>v[i]>>y;tot[i]=y;
        for(int j=1;j<=y;++j)
            cin>>s[i][j]>>l[i][j];
    }
    for(int i=0;i<360;++i)
    {
        memset(f,0,sizeof(f));
        for(int j=1;j<=5;++j)
            for(int k=1;k<=tot[j];++k)
                for(int t=s[j][k];t<=s[j][k]+l[j][k];++t)
                    ++f[t%360];
        //for(int j=0;j<=359;++j) cout<<f[j];cout<<endl;
        int kk;
        for(kk=0;kk<359;++kk)
            if(f[kk]==5) break;
        if(f[kk]==5) {cout<<i<<endl;return 0;}
        for(int j=1;j<=5;++j)
            for(int k=1;k<=5;++k)
                s[j][k]=(s[j][k]+v[j])%360;
    }
    cout<<"none\n";
    return 0;
}
