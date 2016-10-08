#include<stdio.h>

long long fib[90],bee[90];

void fibee()
{
    int i;
    fib[0]=1;
    fib[1]=1;
    for(i=2;i<90;i++)
    fib[i]=fib[i-1]+fib[i-2];

    bee[1]=1;
    bee[2]=2;
    for(i=3;i<90;i++)
    bee[i]=bee[i-1]+fib[i-1];

}

int main()
{
    fibee();
    long long x;
    while(1)
    {
        scanf("%lld",&x);
        if(x<0)
        break;
        printf("%lld %lld\n",bee[x],bee[x+1]);

    }
    return 0;
}
