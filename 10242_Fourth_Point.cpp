#include<stdio.h>
#include<math.h>

struct co_ord
{
    double x,y;
};

double dist(co_ord a,co_ord b)
{
    double dist=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return dist;
}
co_ord a[5],b,c;
double d,d2;
bool forth(double x)
{
    c.x=x;
    c.y=b.y+(sqrt(d)-(x-b.x)*(x-b.x))*(sqrt(d)-(x-b.x)*(x-b.x));
    d2=dist(c,b);
    if(d-d2<.0001)
       return true;
    return false;
}
int main()
{
    int i;
    double low,high,mid;
    while(scanf("%lf %lf",&a[0].x,&a[0].y)==2)
    {
        scanf("%lf %lf",&a[1].x,&a[1].y);
        scanf("%lf %lf",&a[2].x,&a[2].y);
        scanf("%lf %lf",&a[3].x,&a[3].y);

        if((a[0].x==a[2].x && a[0].y==a[2].y) || (a[1].x==a[2].x && a[1].y==a[2].y))
            b=a[3];
        else
            b=a[2];

        d=dist(a[0],a[1]);

        low=-10;
        high=10;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(forth(mid))
                break;
            else if(d2<d)
                low=mid;
            else
                high=mid;
        }
        printf("%lf %lf\n",c.x,c.y);
    }

}
