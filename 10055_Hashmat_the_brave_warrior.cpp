#include<stdio.h>
long long ABS(long long a)
{
    if(a<0)
        return -a;
    return a;
}
int main()
{
    long long a,b;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        printf("%lld\n",ABS(a-b));

    }
    return 0;
}
