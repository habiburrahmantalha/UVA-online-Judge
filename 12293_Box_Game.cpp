#include<stdio.h>
#include<string.h>

int main()
{
    long long n,i,x;
    while(scanf("%lld",&n)==1 && n)
    {
        x=1;
        if(n&1)
        for(i=1;i<=n;i=i*2+1)
        if(i==n)
        x=2;

        if(x==1)
        printf("Alice\n");
        else
        printf("Bob\n");
    }
    return 0;
}
