//Problem Type : Fibonacci
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
long long dp[85];

void precal()
{
    int i;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(i=3;i<=80;i++)
    dp[i]=dp[i-1]+dp[i-2];
}
int main()
{
    precal();
    int n;
    while(scanf("%d",&n) && n)
    {
        printf("%lld\n",dp[n]);
    }
    return 0;
}
