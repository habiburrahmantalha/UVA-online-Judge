//Problem Type : Geometry
//Time :    .008
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
    double r,n,area;
    while(scanf("%lf %lf",&r,&n)==2)
    {
        area=r*r*n*sin(2*PI/n)/2;
        printf("%.3lf\n",area);
    }
    return 0;
}
