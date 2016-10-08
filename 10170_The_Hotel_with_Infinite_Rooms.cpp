#include<stdio.h>

int main()
{
    long long s,d;
    while(scanf("%lld %lld",&s,&d)==2)
    {
        while(1)
        {

            d-=s;
            if(d<=0)
                break;

            s++;


        }
        printf("%lld\n",s);
    }
    return 0;
}
