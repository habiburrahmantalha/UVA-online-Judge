#include <stdio.h>
#include <math.h>

#define EPS 1e-7

int p,q,r,s,t,u;

double f(double x)
{
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

void bisection()
{
    double l=0,h=1,m;
    if(f(0)==0)
    {
        printf("%.4lf\n",f(0));
        return;
    }
    while(l<h)
    {
        m=(l+h)/2;
        if(fabs(f(m)-0)<=EPS)
        {
            printf("%.4lf\n",m);
            return;
        }
        else if(f(m)<0)
        h=m;
        else
        l=m;
    }
    printf("No solution\n");
}

int main()
{
    while (scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6)
    {
        bisection();
    }
    return 0;
}

