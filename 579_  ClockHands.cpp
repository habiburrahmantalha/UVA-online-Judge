#include<stdio.h>

int main()
{
    double min,hr,angle1,angle2,angle_hr,angle_min;
    while(scanf("%lf:%lf",&hr,&min))
    {
        if(hr==0 && min== 0 )
            break;
        angle_hr=(hr*30)+(min/2);
        angle_min=min*6;
        angle1=angle_hr-angle_min;

        if(angle1<0)
            angle1+=360;
        angle2=angle_min-angle_hr;
        if(angle2<0)
            angle2+=360;

        if(angle2<angle1)
            angle1=angle2;
        printf("%.3lf\n",angle1);
    }
    return 0;
}
