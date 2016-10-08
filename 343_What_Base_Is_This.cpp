//Problem Type :    base convertion
//Time : 0.276
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
string a,b;
long long  in_dec;
long long m[130];
char n[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',
            'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W',
            'X','Y','Z'};

bool valid(long long base)
{
    for(long long i=0;i<a.size();i++)
        if(m[a[i]]>=base)
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
void decimal(long long base)
{
    long long i,j;

    in_dec=0;
    for(i=0,j=a.size()-1;i<a.size();i++,j--)
        in_dec+=POW(base,j)*m[a[i]];
}
string convert(long long base)
{
    long long i,j,temp;
    temp=in_dec;
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
    char ch;
    bool f;
    long long i,j;
    string new_a;

    for(ch='0',j=0;ch<='9';ch++,j++)
        m[ch]=j;

    for(ch='A',j=10;ch<='Z';ch++,j++)
        m[ch]=j;


    while(cin>>a>>b)
    {
        f=false;
        for(i=2;i<=36;i++)
        {
            if(valid(i))
            {
                decimal(i);
                //cout<<in_dec<<endl;

                for(j=2;j<=36;j++)
                {

                    new_a=convert(j);
                    //cout<<in_dec<<new_a<<endl;
                    if(new_a==b)
                    {
                        //cout<<"Yes"<<i<<" "<<j<<endl;
                        printf("%s (base %lld) = %s (base %lld)\n",a.c_str(),i,b.c_str(),j);
                        f=true;
                        i=j=40;
                    }
                }

            }
        }
        if(!f)
            printf("%s is not equal to %s in any base 2..36\n",a.c_str(),b.c_str());


    }
    return 0;
}
