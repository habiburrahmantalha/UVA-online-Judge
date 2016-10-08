//Problem Type : adhoc
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
    int a,b,c,d,x,y;
    while(scanf("%d %d",&a,&b) && a>=0 && b>=0)
    {
        c=0;
        x=a;
        y=b;
        while(x!=y)
        {
            x=(x+1)%100;
            c++;
        }
        d=0;
        x=a;
        y=b;
        while(x!=y)
        {
            x=(x+99)%100;
            d++;
        }
        printf("%d\n",min(c,d));
    }
    return 0;
}
