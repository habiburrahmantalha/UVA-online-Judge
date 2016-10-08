#include<stdio.h>

int main()
{
    long long x,y;
    while(scanf("%lld",&x))
    {
        if(x<0)
            break;

        y=x*25;
        if(x==1)
            y=0;
        printf("%lld%\n",y);
    }
    return 0;
}
