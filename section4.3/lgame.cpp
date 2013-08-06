/*
ID: 5120309052
TASK: lgame
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int p[27]={0,2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
int tar[27]={0},ff=1;
int a[40000][27]={0};
char s[10],ss[40000][10];
int tmp[27]={0},point[40000]={0},l[40000]={0};
int tot=0,ans=0,anstot=0;

struct node
{
    char s[20];
    int length;
}anslist[50000];

bool cmp(node xx,node yy)
{
    int re=-1;
    int k=1,lx=xx.length,ly=yy.length;
    while(k<=lx&&k<=ly)
    {
        if(xx.s[k]<yy.s[k]) {re=1;break;}
        else if(xx.s[k]>yy.s[k]) {re=0;break;}
        ++k;
    }
    if(k==-1)
    {
        if(lx<ly) re=1;
        else re=0;
    }
    return re;
}

int main()
{
    ifstream fin("lgame.in");
    ifstream dict("lgame.dict");
    ofstream fout("lgame.out");
    char c;
    while(fin>>c) ++tar[c-'a'+1];
    while(ff)
    {
        dict.getline(s,'\n');
        if(s[0]=='.') break;
        int ok=1;
        memset(tmp,0,sizeof(tmp));
        for(int i=0;i<strlen(s);++i)
        {
            ++tmp[s[i]-'a'+1];
            if(tmp[s[i]-'a'+1]>tar[s[i]-'a'+1])
            {
                ok=0;break;
            }
        }
        if(ok)
        {
            ++tot;
            l[tot]=strlen(s);
            for(int i=1;i<=strlen(s);++i) ss[tot][i]=s[i-1];
            for(int i=1;i<=26;++i) a[tot][i]=tmp[i];
        }
    }
    for(int i=1;i<=tot;++i)
    {
        for(int j=1;j<=26;++j) point[i]+=a[i][j]*p[j];
        if(point[i]>ans)
        {
            ans=point[i];
            anstot=1;
            anslist[1].length=l[i];
            for(int k=1;k<=l[i];++k) anslist[1].s[k]=ss[i][k];
        }
        else if(point[i]==ans)
        {
            ++anstot;
            anslist[anstot].length=l[i];
            for(int k=1;k<=l[i];++k) anslist[anstot].s[k]=ss[i][k];
        }
    }
    for(int i=1;i<=tot;++i)
        for(int j=i;j<=tot;++j)
        {
            int fff=1,sum=0;
            for(int k=1;k<=26;++k) if(a[i][k]+a[j][k]>tar[k]) {fff=0;break;}
            if(fff)
            {
                for(int k=1;k<=26;++k) sum+=p[k]*(a[i][k]+a[j][k]);
                if(sum>ans)
                {
                    ans=sum;anstot=1;
                    anslist[1].length=l[i]+l[j]+1;
                    for(int k=1;k<=l[i];++k) anslist[1].s[k]=ss[i][k];
                    anslist[1].s[l[i]+1]=' ';
                    for(int k=l[i]+2;k<=l[i]+l[j]+1;++k) anslist[1].s[k]=ss[j][k-l[i]-1];
                }
                else if(sum==ans)
                {
                    ++anstot;
                    anslist[anstot].length=l[i]+l[j]+1;
                    for(int k=1;k<=l[i];++k) anslist[anstot].s[k]=ss[i][k];
                    anslist[anstot].s[l[i]+1]=' ';
                    for(int k=l[i]+2;k<=l[i]+l[j]+1;++k) anslist[anstot].s[k]=ss[j][k-l[i]-1];
                }
            }
        }
    fout<<ans<<endl;
    sort(anslist+1,anslist+anstot+1,cmp);
    for(int i=1;i<=anstot;++i)
    {
        for(int j=1;j<=anslist[i].length;++j)
            fout<<anslist[i].s[j];
        fout<<endl;
    }
    return 0;
}
