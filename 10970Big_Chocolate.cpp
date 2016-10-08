#include<stdio.h>

int main()
{
    long long x,y;
    while(scanf("%lld %lld",&x,&y)==2)
    printf("%lld\n",x*y-1);
    return 0;
}
