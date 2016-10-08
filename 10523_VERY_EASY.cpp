//big int :(

#include<stdio.h>
#include<math.h>
int main()
{
    long long n,a,sum,i;

    while(scanf("%lld %lld",&n,&a)==2)
    {
        sum=0;
        for(i=1;i<=n;i++)
            sum+=i*pow(a,i);
        printf("%lld\n",sum);
    }
}
