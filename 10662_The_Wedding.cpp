//Problem Type :
//Time :    0.008
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
int PT[25],PR[25],PH[25],TR[25][25],RH[25][25],HT[25][25],T,R,H,P,t,r,h;

void booking()
{
    int i,j,k,c;
    t=r=h=-1;
    P=20000000;
    for(i=0;i<T;i++)
    {

        for(j=0;j<R;j++)
        if(TR[i][j]==0)
        {

            for(k=0;k<H;k++)
            if(RH[j][k]==0)
            {

                if(HT[k][i]==0)
                {
                    c=PT[i]+PR[j]+PH[k];
                    //printf("%d %d %d:%d\n",i,j,k,c);
                    if(c<P)
                    {
                        P=c;
                        t=i;
                        r=j;
                        h=k;
                    }
                }

            }
        }
    }
    if(t>=0 && r>=0 && h>=0)
        printf("%d %d %d:%d\n",t,r,h,P);
    else
        printf("Don't get married!\n");
}

int main()
{
    int i,j;
    while(scanf("%d %d %d",&T,&R,&H)==3)
    {
        for(i=0;i<T;i++)
        {
            scanf("%d",&PT[i]);
            for(j=0;j<R;j++)
                scanf("%d",&TR[i][j]);

        }
        for(i=0;i<R;i++)
        {
            scanf("%d",&PR[i]);
            for(j=0;j<H;j++)
                scanf("%d",&RH[i][j]);

        }
        for(i=0;i<H;i++)
        {
            scanf("%d",&PH[i]);
            for(j=0;j<T;j++)
                scanf("%d",&HT[i][j]);

        }
        booking();

    }
    return 0;
}
