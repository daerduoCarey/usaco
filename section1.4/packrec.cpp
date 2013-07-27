/*
ID: 5120309052
PROG: packrec
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int p[5][2]={0},mi[1000000]={0};;
int o(int x) {return (x+1)%2;}
int max1(int x,int y) {if(x<y) return y; return x;}
int min1(int x,int y) {if(x>y) return y; return x;}
int main()
{
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);
    for(int i=1;i<=4;++i) cin>>p[i][0]>>p[i][1];
    int min=10000000;
    int minl=0;
    //case1
    for(int a=1;a<=4;++a)
        for(int b=1;b<=4;++b)
            if(b!=a)
                for(int c=1;c<=4;++c)
                    if(c!=a&&c!=b)
    {
        int d=10-a-b-c;
        for(int aa=0;aa<=1;++aa)
             for(int bb=0;bb<=1;++bb)
              for(int cc=0;cc<=1;++cc)
               for(int dd=0;dd<=1;++dd)
        {
            int t1=p[a][aa]+p[b][bb]+p[c][cc]+p[d][dd];
            int t2=max1(max1(max1(p[a][o(aa)],p[b][o(bb)]),p[c][o(cc)]),p[d][o(dd)]);
            if(t1*t2<min) {min=t1*t2;mi[1]=min1(t1,t2);minl=1;}
            else if(t1*t2==min) {mi[++minl]=min1(t1,t2);}
        }
    }
    //case2
    for(int a=1;a<=4;++a)
        for(int b=1;b<=4;++b)
            if(b!=a)
                for(int c=1;c<=4;++c)
                    if(c!=a&&c!=b)
    {
        int d=10-a-b-c;
        for(int aa=0;aa<=1;++aa)
             for(int bb=0;bb<=1;++bb)
              for(int cc=0;cc<=1;++cc)
               for(int dd=0;dd<=1;++dd)
        {
            int t1=max1(p[a][aa],p[b][bb]+p[c][cc]+p[d][dd]);
            int t2=max1(max1(p[d][o(dd)],p[b][o(bb)]),p[c][o(cc)])+p[a][o(aa)];
            if(t1*t2<min) {min=t1*t2;mi[1]=min1(t1,t2);minl=1;}
            else if(t1*t2==min) {mi[++minl]=min1(t1,t2);}
        }
    }
    //case3
    for(int a=1;a<=4;++a)
        for(int b=1;b<=4;++b)
            if(b!=a)
                for(int c=1;c<=4;++c)
                    if(c!=a&&c!=b)
    {
        int d=10-a-b-c;
        for(int aa=0;aa<=1;++aa)
             for(int bb=0;bb<=1;++bb)
              for(int cc=0;cc<=1;++cc)
               for(int dd=0;dd<=1;++dd)
        {
            int t1=max1(max1(p[a][aa],p[b][bb])+p[c][cc],p[d][dd]);
            int t2=max1(p[a][o(aa)]+p[b][o(bb)],p[c][o(cc)])+p[d][o(dd)];
            if(t1*t2<min) {min=t1*t2;mi[1]=min1(t1,t2);minl=1;}
            else if(t1*t2==min) {mi[++minl]=min1(t1,t2);}
        }
    }
    //case4
    for(int a=1;a<=4;++a)
        for(int b=1;b<=4;++b)
            if(b!=a)
                for(int c=1;c<=4;++c)
                    if(c!=a&&c!=b)
    {
        int d=10-a-b-c;
        for(int aa=0;aa<=1;++aa)
             for(int bb=0;bb<=1;++bb)
              for(int cc=0;cc<=1;++cc)
               for(int dd=0;dd<=1;++dd)
        {
            int t1=max1(max1(p[a][aa],p[b][bb]+p[c][cc]),p[d][dd]);
            int t2=p[a][o(aa)]+p[d][o(dd)]+max1(p[b][o(bb)],p[c][o(cc)]);
            if(t1*t2<min) {min=t1*t2;mi[1]=min1(t1,t2);minl=1;}
            else if(t1*t2==min) {mi[++minl]=min1(t1,t2);}
        }
    }
    //case5
     for(int a=1;a<=4;++a)
        for(int b=1;b<=4;++b)
            if(b!=a)
                for(int c=1;c<=4;++c)
                    if(c!=a&&c!=b)
    {
        int d=10-a-b-c;
        for(int aa=0;aa<=1;++aa)
             for(int bb=0;bb<=1;++bb)
              for(int cc=0;cc<=1;++cc)
               for(int dd=0;dd<=1;++dd)
        {
            int t1=max1(p[a][aa],p[b][bb])+p[c][cc]+p[d][dd];
            int t2=max1(max1(p[a][o(aa)]+p[b][o(bb)],p[c][o(cc)]),p[d][o(dd)]);
            if(t1*t2<min) {min=t1*t2;mi[1]=min1(t1,t2);minl=1;}
            else if(t1*t2==min) {mi[++minl]=min1(t1,t2);}
        }
    }
    //case6
     for(int a=1;a<=4;++a)
        for(int b=1;b<=4;++b)
            if(b!=a)
                for(int c=1;c<=4;++c)
                    if(c!=a&&c!=b)
    {
        int d=10-a-b-c;
        for(int aa=0;aa<=1;++aa)
             for(int bb=0;bb<=1;++bb)
              for(int cc=0;cc<=1;++cc)
               for(int dd=0;dd<=1;++dd)

        {
            int t1,t2;
            if(p[c][cc]>=p[b][bb]+p[d][dd]){
                t1=p[c][cc]+p[a][aa];
                t2=max1(p[c][o(cc)]+max1(p[b][o(bb)],p[d][o(dd)]),p[a][o(aa)]);
            }
            else if(p[c][cc]>p[d][dd]&&p[c][cc]<p[b][bb]+p[d][dd])
            {
                t1=max1(p[a][aa]+p[c][cc],p[b][bb]+p[d][dd]);
                t2=max1(max1(p[a][o(aa)]+p[b][o(bb)],p[b][o(bb)]+p[c][o(cc)]),p[c][o(cc)]+p[d][o(dd)]);
            }
            else if(p[d][dd]>p[c][cc]&&p[d][dd]<p[a][aa]+p[c][cc])
            {
                t1=max1(p[a][aa]+p[c][cc],p[b][bb]+p[d][dd]);
                t2=max1(max1(p[a][o(aa)]+p[b][o(bb)],p[d][o(dd)]+p[c][o(cc)]),p[a][o(aa)]+p[d][o(dd)]);
            }
            else if(p[d][dd]>=p[a][aa]+p[c][cc])
            {
                t1=max1(p[a][aa]+p[c][cc],p[b][bb]+p[d][dd]);
                t2=max1(max1(p[a][o(aa)]+p[d][o(dd)],p[b][o(bb)]),p[c][o(cc)]+p[d][o(dd)]);
            }
            else if(p[c][cc]==p[d][dd])
            {
                t1=max1(p[a][aa]+p[c][cc],p[b][bb]+p[d][dd]);
                t2=max1(p[a][o(aa)]+p[b][o(bb)],p[c][o(cc)]+p[d][o(dd)]);
            }
            if(t1*t2<min) {min=t1*t2;mi[1]=min1(t1,t2);minl=1;}
            else if(t1*t2==min) {mi[++minl]=min1(t1,t2);}
        }
    }
    cout<<min<<endl;
    sort(mi+1,mi+minl+1);
    cout<<mi[1]<<" "<<min/mi[1]<<endl;int rem=mi[1];
    for(int i=2;i<=minl;++i)
        if(mi[i]!=rem)
    {cout<<mi[i]<<" "<<min/mi[i]<<endl;rem=mi[i];}
    return 0;
}
