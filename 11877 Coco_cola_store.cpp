#include<stdio.h>

int main()

{
    long long x,count,y;
    while(scanf("%lld",&x) && x)
    {
        count=0;
        while(1)
        {
            if(x==1)
            break;
            if(x==2)
            {
                count++;
                break;
            }
            y=x/3;
            count+=y;
            x%=3;
            x+=y;
        }
        printf("%lld\n",count);
    }
    return 0;
}
