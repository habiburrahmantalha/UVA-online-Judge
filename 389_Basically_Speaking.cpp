//Problem Type :    base convertion
//Time :    0.544
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)

string num;
long long base,to_base,in_dec;
long long m[130];
char n[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};



long long POW(long  long x,long long y)
{
    long long i,z=1;
    for(i=1;i<=y;i++)
        z*=x;
    //cout<<z<<endl;
    return z;
}
void decimal()
{
    long long i,j;

    in_dec=0;
    for(i=0,j=num.size()-1;i<num.size();i++,j--)
        in_dec+=POW(base,j)*m[num[i]];
}

string convert()
{
    long long i,j,temp;
    temp=in_dec;
    string res="";
    while(temp)
    {
        res+=n[temp%to_base];
        temp/=to_base;

    }
    //reverse(res.begin(),res.end());
    //cout<<res<<endl;
    if(res.size()==0)
    res="0";
    for(i=res.size();i<7;i++)
    res+=' ';
    reverse(res.begin(),res.end());
    if(res.size()>7)
    return "  ERROR";
    else
    return res;
}

int main()
{

    char ch;
    long long i,j;
    for(ch='0',j=0;ch<='9';ch++,j++)
        m[ch]=j;

    for(ch='A',j=10;ch<='Z';ch++,j++)
        m[ch]=j;

    while(cin>>num>>base>>to_base)
    {
        decimal();
        printf("%s\n",convert().c_str());
    }

    return 0;
}
