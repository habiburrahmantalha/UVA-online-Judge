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

LL a,b,m,F[500001],x;

LL fib(LL n)
{
    if(n<500000)
        return F[n];

    if(n%2==0)
        return ((2*fib((n/2)-1)+fib(n/2))*fib(n/2))%m;
    else
        return ((fib((n+1)/2)*fib((n+1)/2))+(fib(((n+1)/2)-1)*fib(((n+1)/2)-1)))%m;
}
void precal(LL n)
{
    LL N2=500000;
    if(N2>n)
    N2=n;
    F[0]=a;
    F[1]=b;
    for(LL i=2;i<=N2;i++)
        F[i]=(F[i-1]+F[i-2])%m;


    //for(int i=0;i<11;i++)
        //printf("%d ",F[i]);
}
LL MOD(int x)
{
    LL y=1;
    while(x--)
    y*=10;

    return y;
}
int main()
{

    long long n,f;
    int tc=11;
    //scanf("%d",&tc);
    while(tc--)
    {
        //scanf("%lld %lld %lld %lld",&a,&b,&n,&m);
        a=0;b=1;n=1000000000;m=4;
        m=MOD(m);
        precal(n);

        f=fib(n);
        //printf("%lld\n",f);

    }

    return 0;
}
