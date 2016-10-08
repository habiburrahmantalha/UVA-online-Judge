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


int main()
{
    double a,b,c,s,ar,r,R,sunflowers,violets,roses  ;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3)
    {
        s=(a+b+c)/2.0;
        ar=sqrt(s*(s-a)*(s-b)*(s-c));

        r=ar/s;
        R=a*b*c/(4*ar);

        roses=PI*r*r;
        violets=ar-roses;
        sunflowers=PI*R*R-ar;
        printf("%.4lf %.4lf %.4lf\n",sunflowers,violets,roses);
    }
    return 0;
}
