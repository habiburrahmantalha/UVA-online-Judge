#include<stdio.h>

int main()
{
    int coin[]={1,5,10,25,50};
    int change[10000],x,i,j,k;
    change[0]=1;
    for(i=0;i<5;i++)
    {
        x=coin[i];
        for(j=x,k=0;j<=8000;k++,j++)
        {
            //if(change[j])
            {
                change[j]+=change[k];

            }
        }
    }
    //for(i=0;i<20;i++)
    //printf("%d ",change[i]);

    while(scanf("%d",&x)==1)
    {
        printf("%d\n",change[x]);
    }
    return 0;
}
