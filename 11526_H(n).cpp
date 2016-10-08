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

long long H(int n)
{

    long long res = 0,i;
    /*
    for(i=1;i*i<=n;i++)
    res+=n/i;

    res+=n/2;
    return res;
    */
    for(i = 1; i <= n; i=i+1 )
    {
        res = (res + n/i);
        cout<<n/i<<" ";
    }
    return res;
}

int main()
{
    int tc;
    long long n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld",&n);
        printf("%lld\n",H(n));
    }
    return 0;
}
