#include<stdio.h>

int main()
{
    long long t,x,sum,p,count,i=1;
    while(1)
    {
        scanf("%lld",&x);
        if(x<0)
        break;
        p=1;
        sum=1;
        count=0;
        while(sum<x)
        {
            sum+=p;
            p=sum;
            count++;
        }
        printf("Case %lld: %lld\n",i++,count);
    }
    return 0;
}
