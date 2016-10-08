#include<stdio.h>
#include<math.h>
#define LL long double
LL cal(LL x)
{
    LL i,j,k,y;

    for(i=9;i>=2;i--)
    {
        if(i>x)
            continue;
        y=x;
        for(k=0;k<i;k++)
        {
            y-=1;
            if(fmod(y,i)==0)
            y-=(y/i);
            else
                break;
        }
        if(fmod(y,i)==0)
            return i;

    }
    return 0;
}


int main()
{
    LL n,m;
    while(scanf("%Lf",&n) && n>=0)
    {
        m=cal(n);
        if(m==0)
            printf("%.0Lf coconuts, no solution\n",n);
        else
            printf("%.0Lf coconuts, %.0Lf people and 1 monkey\n",n,m);
    }
    return 0;
}
