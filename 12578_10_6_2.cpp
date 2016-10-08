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
#define PI acos (-1)


int main()
{
    int tc;
    double L,W,R;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lf",&L);
        W=L*6/10;
        R=L/5;

        printf("%.2lf %.2lf\n",PI*R*R,L*W-PI*R*R);
    }
    return 0;
}
