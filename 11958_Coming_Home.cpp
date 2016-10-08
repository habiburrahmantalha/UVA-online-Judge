#include<stdio.h>

int main()
{
    int tc,t,i,min,m,n,h,home,time1,time2,time;

    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        scanf("%d %d:%d",&n,&h,&m);
        time1=h*60+m;
        min=1000000;
        for(i=0;i<n;i++)
        {

            scanf("%d:%d %d",&h,&m,&home);
            time2=h*60+m;
            if(time2<time1)
            {
                time=time2+(24*60-time1)+home;
            }
            else
                time=time2-time1+home;
            if(min>time)
                min=time;
        }
        printf("Case %d: %d\n",t,min);
    }
}
