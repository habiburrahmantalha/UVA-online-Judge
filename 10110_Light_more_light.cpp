#include<stdio.h>
#include<math.h>

int main()
{
    long long m,n;
    while(scanf("%lld",&n) && n)
    {
        m =(long long ) ceil(sqrt((double)n));
        if(m*m==n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
