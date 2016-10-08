#include<stdio.h>

int main()
{
    long long n,m,i,in;
    long long s[1000];

    while(scanf("%lld %lld",&n,&m)==2)
    {
        in=0;
        if(n>=m && m>1)
        {
            while(n%m==0)
            {
                s[in++]=n;
                n/=m;
            }
            s[in]=n;

            if(n==1)
            {
                for(i=0;i<in;i++)
                    printf("%lld ",s[i]);
                printf("%lld\n",s[i]);
            }
            else
                printf("Boring!\n");
        }
        else
            printf("Boring!\n");
    }
    return 0;
}
