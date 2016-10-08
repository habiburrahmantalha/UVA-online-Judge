#include<stdio.h>

int main()
{
    long long n,f[]={0,0,0,0,0,0,0,0,40320,362880,3628800,39916800,479001600,6227020800};

    while(scanf("%lld",&n)==1)
    {
        if(n<0)
        {
            n*=(-1);
            if(n&1)
                printf("Overflow!\n");
            else
                printf("Underflow!\n");

        }
        else if(n<8)
            printf("Underflow!\n");
        else if(n>13)
            printf("Overflow!\n");
        else
            printf("%lld\n",f[n]);
    }
    return 0;
}
