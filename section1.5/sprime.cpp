/*ID: 5120309052
PROG:sprime
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int a[10]={0};
bool sushu(int x)
{
    int f=1;
    for(int i=2;i<=sqrt(x);++i)
        if(x%i==0) {f=0;break;}
    return f;
}
void sear(int s,int k)
{
    if(k>n)
    {
        for(int i=1;i<=n;++i)
                cout<<a[i];
        cout<<endl;
    }
    else{
    for(int i=1;i<=5;++i)
    {
        a[k]=2*i-1;
        if(sushu(s*10+a[k])) sear(s*10+a[k],k+1);
    }}
}
int main()
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    cin>>n;
    a[1]=2;sear(2,2);
    a[1]=3;sear(3,2);
    a[1]=5;sear(5,2);
    a[1]=7;sear(7,2);
    return 0;
}

