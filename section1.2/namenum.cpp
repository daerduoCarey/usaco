/*
ID: 5120309052
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
int st[127]={0,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int fff=0;
int main()
{
    ifstream f("dict.txt");
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    char c,s[30];int a[30]={0},n=0;
    while((c=fin.get())!=EOF)
    {
        if(c>='0'&&c<='9')
        {
            ++n;a[n]=c-'0';
        }
    }
    while(f>>s)
    {
        if(strlen(s)==n)
        {
            int ff=1;
            for(int i=0;i<strlen(s);++i)
                if(st[s[i]-'A'+1]!=a[i+1]) {ff=0;break;}
            if(ff) {fout<<s<<endl;fff=1;}
        }
    }
    if(fff==0) fout<<"NONE\n";
    f.close();fin.close();fout.close();
    return 0;
}
