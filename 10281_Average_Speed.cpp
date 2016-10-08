#include<stdio.h>
#include<string.h>

int h,m,s;

int main()
{
    int i,j;
    double speed=0.0,res,time1=0.0,time2=0.0,time0=0.0,dist=0.0;
    char ch;
    bool f=false;
    while(scanf("%d:%d:%d",&h,&m,&s)==3)
    {
        ch=getchar();

        if(f==false && ch==32)
        {
            scanf("%lf",&speed);
            speed/=3600;
            f=true;
            time0=double(h*60*60+m*60+s);
            continue;
        }


        if(ch==32)
        {
            time1=double(h*60*60+m*60+s);
            res=(time1-time0)*speed;
            dist+=res;
            time0=time1;

            scanf("%lf",&speed);
            speed/=3600;

            //printf("%s %.0lf km\n",time,dist);
        }
        else
        {
            time2=double(h*60*60+m*60+s);
            res=(time2-time0)*speed;
            dist+=res;
            //printf("%s %.2lf km\n",time,dist);
            printf("%02d:%02d:%02d %.2f km\n", h, m, s, dist);
            time0=time2;
        }
    }
    return 0;
}
