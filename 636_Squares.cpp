//Problem Type :    base
//Time :    0.008
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
int in_dec;

bool valid(long long base)
{
    for(long long i=0;i<num.size();i++)
        if((num[i]-'0')>=base)
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
    for(i=0,j=num.size()-1;i<num.size();i++,j--)
        in_dec+=POW(base,j)*(num[i]-'0');
}

int main()
{
    long long i,x;
    while(cin>>num && num!="0")
    {
        for(i=2;i<=100;i++)
        {
            if(valid(i))
            {
                decimal(i);
                x=floor(sqrt(in_dec));
                if(x*x==in_dec)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
