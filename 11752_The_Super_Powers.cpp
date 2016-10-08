//Problem Type :
//Time :
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

LL N;
map<LL,int>m;

LL POW(LL x,LL n)
{
    LL y=1;
    for(LL i=1;i<=n;i++)
    y*=x;

    return y;
}
void precal()
{
    LL x;
    for(LL i=2;i<1000;i++)
    {
        for(LL j=2;j<10 ;j++)
        {
            x=POW(i,j);

            m[x]++;

        }
    }
}
int main()
{
    N=POW(2,63)-1;
    cout<<"8876902158263259136"<<endl<<N;

    return 0;

    precal();

    map<LL,int> ::iterator it;
    for(it=m.begin();it!=m.end();it++)
    if(it->second>1)
    cout<<it->first<<endl;
    return 0;
}
