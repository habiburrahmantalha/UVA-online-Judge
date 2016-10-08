#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long x,y;

    while(scanf("%llu",&x) && x)
    {
        y=(x*10)/9;
        if(x%9==0)
        printf("%llu %llu\n",y-1,y);
        else
        printf("%llu\n",y);

    }
    return 0;
}
