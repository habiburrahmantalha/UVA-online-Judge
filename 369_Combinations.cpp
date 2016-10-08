#include<stdio.h>

int main()
{
    double N,M,i,j,d;

    while(scanf("%lf %lf",&N,&M) && N && M)
    {
        d=1.0;
        for(i=(N-M)+1,j=1;i<=N,j<=M;i++,j++)
            d*=i/j;
        for(;j<=M;j++)
            d/=j;
        for(;i<=N;i++)
            d*=i;

        printf("%.0lf things taken %.0lf at a time is %.0lf exactly.\n",N,M,d);
    }
    return 0;
}
