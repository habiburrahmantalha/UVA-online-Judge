
#include<stdio.h>

long long bangla(long long x)
{
        long long kuti,lakh,hajar,shata;
        kuti=x/10000000;
        x%=10000000;
        lakh=x/100000;
        x%=100000;
        hajar=x/1000;
        x%=1000;
        shata=x/100;
        x%=100;
        if(kuti>99)
        {
            kuti=bangla(kuti);
            if(!kuti)
            printf(" kuti");
        }
        if(kuti)
        printf(" %lld kuti",kuti);
        if(lakh)
        printf(" %lld lakh",lakh);
        if(hajar)
        printf(" %lld hajar",hajar);
        if(shata)
        printf(" %lld shata",shata);
        return x;
}
int main()
{
    long long x;
    int tc=1;
    while(scanf("%lld",&x)==1)
    {
        printf("%4d.",tc++);
        if(x==0)
        printf(" 0");
        x=bangla(x);
        if(x)
        printf(" %lld",x);
        printf("\n");
    }
    return 0;
}
