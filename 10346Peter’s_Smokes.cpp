#include<stdio.h>


int main()
{
    long long n,k,sum,m;
    while(scanf("%lld %lld",&n,&k)==2)
    {
        sum=0;
        m=0;
        while((n+m)>=k)
        {
            sum+=n;
            n+=m;
            m=n%k;
            n=n/k;
            //if(!n)
            //break;

            //printf("%lld %lld\n",n,m);

        }
        sum+=n;
        printf("%lld\n",sum);
    }

    return 0;
}
