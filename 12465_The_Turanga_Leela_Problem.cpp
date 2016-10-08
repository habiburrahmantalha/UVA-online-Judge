//Problem Type :    divisor |a-b|
//Time :
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

bool SQURE(int x)
{
    int i;
    if(x==1)
    return false;
    for(i=1;i*i<=x;i++)
    if(i*i==x)
    return true;

    return false;
}

int main()
{
    int a,b,c,d,i;
    while(scanf("%d %d",&a,&b) && a+b)
    {
        c=abs(a-b);
        d=1;
        for(i=2;i*i<=c;i++)
        {
            if(c%i==0)
            d++;
        }
        if(c>1)
            d*=2;
        if(SQURE(c))
            d-=1;
        printf("%d\n",d);
    }
    return 0;
}
