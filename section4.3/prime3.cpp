/*
ID: 5120309052
TASK: prime3
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int tot,f[6][6]={0},ans=0,s[6]={0};
int prime[100000]={0};
int sh[6]={0},sl[6]={0};
long long total=0;
int lp[1000]={0},p[100][10000]={0};
int p3[1000][100]={0};
int anslist[10000][25]={0};
void produce_prime(int x)
{
    int tt,ss;
    for(int i=2;i<=sqrt(100000);++i)
        for(int j=i;j<=99999/i;++j)
            prime[i*j]=1;
    for(int i=0;i<10000;++i) prime[i]=0;
    for(int i=10000;i<=99999;++i)
        if(prime[i]) prime[i]=0;
        else
        {
            tt=i;ss=0;
            for(int j=1;j<=5;++j) {ss+=tt%10;tt/=10;}
            if(ss==x)
            {
                prime[i]=1;
                prime[i/10000]=1;
                prime[i/1000]=1;
                prime[i/100]=1;
                prime[i/10]=1;
            }
        }
}
bool cmp(int* x,int* y)
{
    int f=0;
    while(x[f]==y[f]) ++f;
    if(x[f]<y[f]) return true;
    else return false;
}
int main()
{
    freopen("prime3.in","r",stdin);
    freopen("prime3.out","w",stdout);
    cin>>tot>>f[1][1];int key=f[1][1];
    produce_prime(tot);
    int st=1;
    for(int i=10000;i<=99999;++i)
        if(prime[i])
        {
            p[i/10000][++lp[i/10000]]=i;
            p[i/1000][++lp[i/1000]]=i;
            p3[i/100][++lp[i/100]]=i;
        }
    for(int a1=1;a1<=lp[key];++a1)
    {
        int tmp=p[key][a1],error=0;
        for(int i=5;i>=2;--i) {f[1][i]=tmp%10;tmp/=10;if(!f[1][i]) {error=1;break;}}
        if(error) continue;
        for(int a2=1;a2<=lp[key];++a2)
        {
            int tmp=p[key][a2],error=0;
            for(int i=5;i>=2;--i) {f[i][1]=tmp%10;tmp/=10;if(!f[i][1]) {error=1;break;}}
            if(error) continue;

            for(int a3=1;a3<=lp[key];++a3)
            {
                int tmp=p[key][a3],error=0;
                for(int i=5;i>=2;--i) {f[i][i]=tmp%10;tmp/=10;}
                if(error) continue;
                for(int a4=1;a4<=lp[f[2][1]*10+f[2][2]];++a4)
                {
                    int tmp=p[f[2][1]*10+f[2][2]][a4];
                    for(int i=5;i>=3;--i) {f[2][i]=tmp%10;tmp/=10;}
                    for(int a5=1;a5<=lp[f[1][2]*10+f[2][2]];++a5)
                    {
                        int tmp=p[f[1][2]*10+f[2][2]][a5];
                        for(int i=5;i>=3;--i) {f[i][2]=tmp%10;tmp/=10;}
                        int xx=f[5][1]*10000+f[4][2]*1000+f[3][3]*100+f[2][4]*10+f[1][5];
                        if(!prime[xx]) continue;
                        for(int a6=1;a6<=lp[f[3][1]*100+f[3][2]*10+f[3][3]];++a6)
                        {
                            int tmp=p3[f[3][1]*100+f[3][2]*10+f[3][3]][a6];
                            for(int i=5;i>=4;--i) {f[3][i]=tmp%10;tmp/=10;}
                            for(int a7=1;a7<=lp[f[1][3]*100+f[2][3]*10+f[3][3]];++a7)
                            {
                                int tmp=p3[f[1][3]*100+f[2][3]*10+f[3][3]][a7];
                                for(int i=5;i>=4;--i) {f[i][3]=tmp%10;tmp/=10;}
                                for(f[5][4]=0;f[5][4]<=9;++f[5][4])
                                    for(f[4][5]=0;f[4][5]<=9;++f[4][5])
                                {
                                    int tmp,error=0;
                                    tmp=f[4][1]*10000+f[4][2]*1000+f[4][3]*100+f[4][4]*10+f[4][5];
                                    if(!prime[tmp]) error=1;
                                    if(error) continue;
                                    tmp=f[5][1]*10000+f[5][2]*1000+f[5][3]*100+f[5][4]*10+f[5][5];
                                    if(!prime[tmp]) error=1;
                                    if(error) continue;
                                    tmp=f[1][4]*10000+f[2][4]*1000+f[3][4]*100+f[4][4]*10+f[5][4];
                                    if(!prime[tmp]) error=1;
                                    if(error) continue;
                                    tmp=f[1][5]*10000+f[2][5]*1000+f[3][5]*100+f[4][5]*10+f[5][5];
                                    if(!prime[tmp]) error=1;
                                    if(error) continue;
                                    ++ans;
                                    for(int i=1;i<=5;++i)
                                        for(int j=1;j<=5;++j)
                                            anslist[ans][(i-1)*5+(j-1)]=f[i][j];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(ans==0) {cout<<"NONE\n";return 0;}
    int swaptmp[25]={0};
    for(int i=1;i<ans;++i)
        for(int j=i+1;j<=ans;++j)
    {
        if(!cmp(anslist[i],anslist[j]))
        {
            for(int kk=0;kk<=24;++kk) swaptmp[kk]=anslist[i][kk];
            for(int kk=0;kk<=24;++kk) anslist[i][kk]=anslist[j][kk];
            for(int kk=0;kk<=24;++kk) anslist[j][kk]=swaptmp[kk];
        }
    }
    for(int kk=1;kk<=ans;++kk)
    {
        if(kk>1) cout<<endl;
        for(int i=1;i<=5;++i)
        {
            for(int j=1;j<=5;++j)
                cout<<anslist[kk][(i-1)*5+(j-1)];
            cout<<endl;
        }
    }
    return 0;
}

