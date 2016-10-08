#include<stdio.h>
#include<string.h>
#include<math.h>
double u,v,w;
bool valid()
{
    if(u>= v && u >= w)
    {
        if(u<v+w)
        return true;
    }
    else if(v>= u && v >= w)
    {
        if(v<u+w)
        return true;
    }
    else if(w>= v && w >= u)
    {
        if(w<v+u)
        return true;
    }
    return false;
}
int main()
{
    double a,s,x;
    while(scanf("%lf %lf %lf",&u,&v,&w)==3)
    {
        if(u && v && w && valid())
        {
            s=(u+v+w)/2;
            x=s*(s-u)*(s-v)*(s-w);
            a=4*sqrt(x)/3;
            printf("%.3lf\n",a);
        }
        else
        printf("-1.000\n");
    }
    return 0;
}
