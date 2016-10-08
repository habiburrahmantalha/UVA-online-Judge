#include<stdio.h>

int main()
{
    long long coin[]={1,5,10,25,50};
    long long change[50000],x,i,j,k;
    change[0]=1;
    for(i=0;i<5;i++)
    {
        x=coin[i];
        for(j=x,k=0;j<=30000;k++,j++)
        {
            //if(change[j])
            {
                change[j]+=change[k];

            }
        }
    }
    //for(int k=0;k<11;k++)
    //printf("%d ",change[k]);
    //printf("\n");

    while(scanf("%lld",&x)==1)
    {
        if(change[x]==1)
        printf("There is only 1 way to produce %lld cents change.\n",x);
        else
        printf("There are %lld ways to produce %lld cents change.\n",change[x],x);
    }
    return 0;
}
