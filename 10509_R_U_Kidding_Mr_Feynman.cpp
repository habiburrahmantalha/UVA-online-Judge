#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)

double qube(double x)
{
    double i;
    for(i=1;i*i*i<=x;i++)
    {
        if(i*i*i==x)
        return i;
    }
    return i-1;

}

int main()
{
    double n,a,dx;
    while(scanf("%lf",&n) && n)
    {
        a=qube(n);
        if(a*a*a!=n)
        dx=(n-a*a*a)/(3*a*a);
        else
        dx=0;
        printf("%.4lf\n",a+dx);
    }
    return 0;
}
