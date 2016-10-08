//Problem Type : adhoc
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


int main()
{
    long long a,b,c,d,e;
    while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e) && a+b+c+d+e)
    {
        printf("%lld\n",a*b*c*d*d*e*e);
    }
    return 0;
}
