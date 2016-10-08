#include<stdio.h>
#include<math.h>

#define LL long long

LL m,af[21][500001],x;
LL fib(LL n)
{
    if(n<2)
        return n;
    if(n<500001)
        return af[x][n];

    if(n%2==0)
        return ((2*fib((n/2)-1)+fib(n/2))*fib(n/2))%m;
    else
        return ((fib((n+1)/2)*fib((n+1)/2))+(fib(((n+1)/2)-1)*fib(((n+1)/2)-1)))%m;
}
void precal()
{
    for(int i=0;i<=20;i++)
    {
        af[i][0]=0;
        af[i][1]=1;
    }
    for(int i=0;i<=20;i++)
    {
        LL k=pow(2,i);
        for(LL j=2;j<500000;j++)
        {
            af[i][j]=(af[i][j-1]+af[i][j-2])%k;
        }
    }
    //for(int i=0;i<20;i++)
        //printf("%d ",af[4][i]);
}
int main()
{
    precal();
    long long n,f;

    while(scanf("%lld %lld",&n,&x)==2)
    {
        if(n==0 || x==0)
        {
            printf("0\n");
            continue;
        }
        m=pow(2,x);
        f=fib(n);
        printf("%lld\n",f);

    }

    return 0;
}
