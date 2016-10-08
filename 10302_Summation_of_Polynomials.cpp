#include<stdio.h>

long long C[50000+5],P[50000+5],x;

void cube()
{
    long long i;
    for(i=1;i<=50000;i++)
        C[i]=i*i*i;
    P[0]=0;
    for(i=1;i<=50000;i++)
        P[i]=P[i-1]+C[i];
}
int main()
{
    cube();

    while(scanf("%d",&x)==1)
    {
        printf("%lld\n",P[x]);
    }
    return 0;
}
