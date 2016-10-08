//Problem Type :    base convertion
//Time : 0.012
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
long long  base,to_base;
long long m[130];
char n[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

bool valid()
{
    for(long long i=0;i<num.size();i++)
        if(m[num[i]]>=base)
            return false;
    return true;
}
long long POW(long  long x,long long y)
{
    long long i,z=1;
    for(i=1;i<=y;i++)
        z*=x;
    //cout<<z<<endl;
    return z;
}
string convert()
{
    long long i,j;
    long long dec=0;
    string res="";
    for(i=0,j=num.size()-1;i<num.size();i++,j--)
    {
        dec+=POW(base,j)*m[num[i]];
    }
    //cout<<dec<<endl;
    while(dec)
    {
        res+=n[dec%to_base];
        dec/=to_base;

    }
    reverse(res.begin(),res.end());
    //cout<<res<<endl;
    if(res.size()==0)
    res="0";
    return res;
}

int main()
{
    char i;
    long long j;
    for(i='0',j=0;i<='9';i++,j++)
    m[i]=j;
    for(i='A',j=10;i<='F';i++,j++)
    m[i]=j;

    while(scanf("%lld %lld",&base,&to_base)==2)
    {
        cin>>num;
        if(valid())
            printf("%s base %lld = %s base %lld\n",num.c_str(),base,convert().c_str(),to_base);
        else
            printf("%s is an illegal base %lld number\n",num.c_str(),base);
    }
    return 0;
}
