#include<stdio.h>

int main()
{
    long long tc,n;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld",&n);
        n=((((((n*567)/9)+7492)*235)/47)-498);
        n/=10;
        if(n<0)
        n*=-1;
        printf("%d\n",n%10);


    }
    return 0;
}
