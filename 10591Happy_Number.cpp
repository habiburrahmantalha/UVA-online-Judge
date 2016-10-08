#include<stdio.h>
#include<string.h>

long long number;
bool mark[1000];
bool happy(long long x)
{
    long long d,n=0;
    while(x)
    {
        d=x%10;
        x/=10;
        n+=(d*d);
    }
    if(n==1)
    return true;
    else if(mark[n])
    return false;
    else
    {
        mark[n]=1;;
        happy(n);
    }
}

int main()
{
    long long tc,i;
    scanf("%lld",&tc);
    for(i=1;i<=tc;i++)
    {
        scanf("%lld",&number);
        memset(mark,0,sizeof(mark));
        if(happy(number))
        printf("Case #%lld: %lld is a Happy number.\n",i,number);
        else
        printf("Case #%lld: %lld is an Unhappy number.\n",i,number);

    }
    return 0;
}
