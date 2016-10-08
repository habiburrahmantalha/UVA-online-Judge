#include<stdio.h>

int main()
{
    double C1,C2,F1,F2,d;
    int tc,t;
    scanf("%d",&tc);

    for(t=1;t<=tc;t++)
    {
        scanf("%lf %lf",&C1,&d);
        F1=C1*1.8+32;

        F2=F1+d;

        C2=(F2-32)/1.8;
        printf("Case %d: %.2lf\n",t,C2);
    }
    return 0;
}
