#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
#define LL long long
LL lcm[1000010],res[1000010];
LL GCD(LL a,LL b)
{
    if(b)
    return GCD(b,a%b);
    return a;
}
LL LCM(LL a,LL b)
{
    return ((a*b)/GCD(a,b));
}
void precal()
{
    LL i,x;
    lcm[1]=1;
    res[1]=1;
    for(i=2;i<=1000000;i++)
    {
        lcm[i]=LCM(i,lcm[i-1]);
        x=lcm[i];
        while(x%10==0)
        x/=10;
        res[i]=x%10;
    }

}
int main()
{
    precal();
    int i,x;
    //while(scanf("%lld",&x) && x)
    {
        for(x=1;x<3000;x++)
        printf("%lld\n",res[x]);
    }
    return 0;
}
