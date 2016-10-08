#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int m,d;
char D[8][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int find_day()
{
    int a,y;
    a=(14-m)/12;
    y=2011-a;
    m=m+12*a-2;
    //Julian calendar:
    //return (5+d+y+y/4+(31*m/12))%7;
    //For Gregorian calendar:
    return (d+y+y/4-(y/100)+(y/400)+(31*m/12))%7;
}

int main()
{
    int tc,day;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&m,&d);
        day=find_day();
        printf("%s\n",D[day]);
    }
    return 0;
}
