/*
ID: 5120309052
TASK: cryptcow
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100];
const char tar[]="Begin the Escape execution at the Break of Dawn";
int l=0,tim,ok=0,ltar;
int a[1000001]={0};
int ELFHash()
{
    int hash = 0;
    int x = 0;
    int kk=1;
    while (kk<=l)
    {
        hash = (hash << 4) + s[kk];
        ++kk;
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }
    return (hash & 0x7FFFFFFF);
}
bool check()
{
    char tt[100],lt=0;
    int kk=1;
    while(kk<=l)
    {
        if(s[kk]!='C'&&s[kk]!='O'&&s[kk]!='W') tt[++lt]=s[kk];
        else if(lt)
        {
            int occur=0;
            for(int i=0;i<ltar-lt+1;++i)
            {
                int ff=0;
                for(int j=1;j<=lt;++j) if(tt[j]!=tar[i+j-1]) {ff=1;break;}
                if(!ff) {occur=1;break;}
            }
            if(!occur) return false;
            lt=0;
        }
        ++kk;
    }
    if(lt)
        {
            int occur=0;
            for(int i=0;i<ltar-lt+1;++i)
            {
                int ff=0;
                for(int j=1;j<=lt;++j) if(tt[j]!=tar[i+j-1]) {ff=1;break;}
                if(!ff) {occur=1;break;}
            }
            if(!occur) return false;
            lt=0;
        }
    return true;
}
bool check2()
{
    int kk=1;
    while(s[kk]!='C'&&s[kk]!='O'&&s[kk]!='W'&&kk<=l) ++kk;
    --kk;
    int f=1;
    for(int i=1;i<=kk;++i) if(s[i]!=tar[i-1]) {f=0;break;}
    if(!f) return false;
    return true;
}
void dfs(int k)
{
    char tmp[100];
    for(int i=1;i<=l;++i) tmp[i]=s[i];
    if(!check()) return;
    if(!check2()) return;
    if(k>tim)
    {
        int ff=1;
        if(l!=ltar) ff=0;
        if(ff) for(int i=1;i<=l;++i) if(tar[i-1]!=s[i]) {ff=0;break;}
        if(ff) {cout<<"1 "<<tim<<endl;ok=1;}
        return ;
    }
    if(ok) return ;
    int tc=1,to,tw;
    while(tc<=l)
    {
        while(s[tc]!='C'&&tc<=l) ++tc;
        if(tc>l) break;
        to=tc+1;
        while(to<=l)
        {
            while(s[to]!='O'&&to<=l) ++to;
            if(to>l) break;
            tw=to+1;
            while(tw<=l)
            {
                while(s[tw]!='W'&&tw<=l) ++tw;
                if(tw>l) break;
                for(int i=tc;i<tc+tw-to-1;++i) s[i]=tmp[to+i-tc+1];
                for(int i=tc+tw-to-1;i<tw-2;++i) s[i]=tmp[tc+i+1-(tc+tw-to-1)];
                for(int i=tw-2;i<=l-3;++i) s[i]=tmp[i+3];
                l-=3;
                int ha=ELFHash()%1000001;
                if(!a[ha]) dfs(k+1);
                if(!a[ha])
                {
                    a[ha]=1;
                }
                l+=3;
                for(int i=1;i<=l;++i) s[i]=tmp[i];
                ++tw;
            }
            ++to;
        }
        ++tc;
    }
}
int main()
{
    freopen("cryptcow.in","r",stdin);
    freopen("cryptcow.out","w",stdout);
    char c;ltar=strlen(tar);
    while((c=getchar())!=EOF&&c!='\n') s[++l]=c;
    int tc=0,to=0,tw=0;
    for(int i=1;i<=l;++i)
    {
        if(s[i]=='C') ++tc;
        else if(s[i]=='O') ++to;
        else if(s[i]=='W') ++tw;
    }
    if(tc!=to||to!=tw) {cout<<"0 0\n";return 0;}
    if(tc*3+ltar!=l) {cout<<"0 0\n";return 0;}
    tim=tc;
    dfs(1);
    if(!ok) cout<<"0 0\n";
    return 0;
}
