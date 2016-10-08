#include<stdio.h>
#include<math.h>

struct co_ordinate
{
    double x,y;
};

double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    co_ordinate c[1010];
    double gx,gy,dx,dy,x,y,max;
    int i,j,n;
    bool escape;
    while(scanf("%d %lf %lf %lf %lf",&n,&gx,&gy,&dx,&dy)==5)
    {
        escape=false;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&c[i].x,&c[i].y);
            x=dist(gx,gy,c[i].x,c[i].y);
            y=dist(dx,dy,c[i].x,c[i].y);
            //printf("%lf %lf\n",x,y);
            if(!escape && x<=y/2.0)
            {
                escape=true;
                j=i;
            }
        }
        if(!escape)
            printf("The gopher cannot escape.\n");
        else
            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",c[j].x,c[j].y);
    }
    return 0;
}
