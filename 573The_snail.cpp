#include<stdio.h>

int main()
{
    double H,U,D,F,sum;
    int day;
    bool f;
    while(scanf("%lf %lf %lf %lf",&H,&U,&D,&F))
    {
        if(H==0)
        break;
        day=0;
        sum=0;
        f=false;
        F=U*F/100;
        while(1)
        {

            day++;
            sum+=U;
            if(sum>H)
            {
                printf("success on day %d\n",day);
                break;
            }
            sum-=D;
            //if(sum<0)
            //sum=0;

            if(sum<0)
            {
                printf("failure on day %d\n",day);
                break;
            }
            U-=F;
            if(U<0)
            U=0;
        }


    }
    return 0;
}
