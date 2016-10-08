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
int res;
void MNG(long long x,int c)
{
    if(x==0)
    {
        res=min(c,res);
        return;
    }
    if(x==1)
    {
        res=min(c+1,res);
        return;
    }

    if(x&1)
    {
        MNG(x+1,c+1);
        MNG(x-1,c+1);
    }
    else
    MNG(x/2,c+1);
}

int main()
{
    long long n;
    while(scanf("%lld",&n)==1)
    {
        res=0x7F;
        MNG(n,0);
        printf("%lld\n",res);
    }
    return 0;
}
