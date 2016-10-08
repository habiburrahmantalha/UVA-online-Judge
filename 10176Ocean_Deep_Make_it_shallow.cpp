#include<stdio.h>
#include<string>
#include<iostream>

#define LL long long

using namespace std;

LL m=131071;
string bin,temp;

LL p2 (LL p)
{
    return p * p;
}


LL bigMod (LL b, LL p)
{

    if ( p == 0 ) return 1;
    if ( p % 2 == 0 ) return p2 (bigMod(b, p / 2)) % m;
    return ( (b % m) * (bigMod(b, p - 1) % m) ) % m;
}


bool divisible()
{
    LL n=bin.size()-1,i,rem=0;
    for(i=0;i<n;i++)
    {
        if(bin[i]=='1')
        rem+=bigMod(2,n-1-i);
    }
    //printf("%lld\n",rem);
    if(rem%m==0)
    return true;
    else
    return false;
}

int main()
{

    while(cin>>bin)
    {
        if(bin[bin.size()-1]!='#')
        while(bin[bin.size()-1]!='#')
        {
            cin>>temp;
            bin+=temp;
        }
        if(divisible())
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        //cout<<bin<<endl;
    }
    return 0;
}
