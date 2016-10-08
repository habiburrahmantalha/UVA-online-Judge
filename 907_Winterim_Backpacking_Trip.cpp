#include<stdio.h>

#define REP(x,i,j) for(x=i;x<j;x++)
int res()
{
    start=max;
    end=sum;

    while(1)
    {
        mid=(strt+end)/2;
        REP(i,0,s+1)
        {
            if(sum+x[i]<=mid)
            sum+=x[i];
            else
            {

            }
        }
    }
}

int main()
{
    while(scanf("%d %d",&s,&n)==2)
    {
        sum=max=0;
        REP(i,0,s+1)
        {
            scanf("%d",&x[i]);
            sum+=x[i];
            if(max<x[i])
                max=x[i];
        }

        printf("%d\n",res());
    }
    return 0;
}
