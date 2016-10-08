#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    int tc,h,m;
    int time[]={11,11,10,9,8,7,6,5,4,3,2,1,12};
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d:%d",&h,&m);
        if(h>12)
        h-=12;
        if(h==0)
        h=12;
        if(m==0)
        {
            if(time[h]<10)
            printf("0%d:00\n",time[h]);
            else
            printf("%d:00\n",time[h]);

        }
        else if(m==60)
        {
            m=0;
            h=(h+1)%13;
            if(time[h]<10)
            printf("0%d:00\n",time[h]);
            else
            printf("%d:00\n",time[h]);
        }
        else
        {
            if(time[(h+1)%13]<10 && 60-m<10)
            printf("0%d:0%d\n",time[(h+1)%13],60-m);
            else if(time[(h+1)%12]<10)
            printf("0%d:%d\n",time[(h+1)%13],60-m);
            else if(60-m<10)
            printf("%d:0%d\n",time[(h+1)%13],60-m);
            else
            printf("%d:%d\n",time[(h+1)%13],60-m);
        }
    }
    return 0;
}
