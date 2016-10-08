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

long long GCD(long long a,long long b)
{
    if(b==0)
    return a;
    else
    return GCD(b,a%b);
}
int main()
{
    int tc,t=1;
    long long a,b;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&a,&b);
        printf("Case %d: %lld\n",t++,(a+b)/GCD(a,b));
    }
    return 0;
}
