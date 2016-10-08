#include<stdio.h>
#include <stdlib.h>
#define N 50
int *y=(int*)malloc(N*sizeof(int));

int main()
{
    int in,i;

    long long b,p,m,x,d;

    while(scanf("%lld %lld %lld",&b,&p,&m)==3)
    {
        in=0;
        d=1;
        x=p;
        while(x)
        {
            y[in++]=x%2;
            x/=2;
        }
        for(i=in-1;i>=0;i--)
        {
            d=(d*d)%m;
            if(y[i]==1)
                d=(d*b)%m;
        }
        printf("%lld\n",d);
    }
    free(y);
    return 0;
}
