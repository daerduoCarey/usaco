/*
ID: 5120309052
PROG: ride
LANG: C++
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    int x=1,y=1,f=0;
    char c;
    while((c=getchar())!=EOF)
    {
        if(c=='\n') f=1;
        else if(f)
        {
            y=(y*(c-'A'+1))%47;
        }
        else
        {
            x=(x*(c-'A'+1))%47;
        }
    }
    if(x==y) cout<<"GO\n";
    else cout<<"STAY\n";
    return 0;
}
