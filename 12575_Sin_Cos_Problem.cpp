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
    double A,B,i,x,mx,mxi,O;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lf %lf",&A,&B);

        O=atan(A/B);
        mxi=O*PI/180;
        mx=A*sin(O)+B*cos(O);


        printf("%.2lf %.2lf\n",mxi,mx);
    }
    return 0;
}
