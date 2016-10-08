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
    int tc;
    double a,b,z,h,res;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lf %lf %lf",&a,&b,&z);
        h=z/(a+b);
        res=a*h;
        res+=res-b*h;
        printf("%.0lf\n",res);
    }
    return 0;
}
