//Problem Type :    base covert,bigmod
//Time :    .036
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
#define LL long long
long long base,mod,m_dec;
string num,m;
char n[]={'0','1','2','3','4','5','6','7','8','9'};

LL p2 (LL p)
{
    return p * p;
}

LL bigMod (LL b, LL p)
{

    if ( p == 0 ) return 1;
    if ( p % 2 == 0 ) return p2 (bigMod(b, p / 2)) % mod;
    return ( (b % mod) * (bigMod(b, p - 1) % mod) ) % mod;
}

long long POW(long  long x,long long y)
{
    long long i,z=1;
    for(i=1;i<=y;i++)
        z*=x;
    //cout<<z<<endl;
    return z;
}
void mod_decimal()
{
    long long i,j;

    mod=0;
    for(i=0,j=m.size()-1;i<m.size();i++,j--)
        mod+=POW(base,j)*(m[i]-'0');
    //cout<<mod<<" ";
}
void reminder()
{
    mod_decimal();
    m_dec=0;
    long long i,j;
    for(i=0,j=num.size()-1;i<num.size();i++,j--)
    {
        m_dec+=( bigMod(base,j)*(num[i]-'0') ) %mod;
        m_dec%=mod;
        //cout<<m_dec<<endl;
    }
    //cout<<m_dec<<" ";
}
string convert()
{
    reminder();
    long long i,j,temp;
    temp=m_dec;
    string res="";
    while(temp)
    {
        res+=n[temp%base];
        temp/=base;

    }
    reverse(res.begin(),res.end());
    //cout<<res<<endl;
    if(res.size()==0)
    res="0";
    return res;
}


int main()
{
    while(scanf("%lld",&base) && base )
    {
        cin>>num>>m;
        printf("%s\n",convert().c_str());
    }
    return 0;
}
