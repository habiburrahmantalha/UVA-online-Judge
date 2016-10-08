#include<stdio.h>

int main()
{
    long long cube[30];
    long long change[1000000],x,i,j,k;

    for(i=1;i<=22;i++)
    cube[i]=i*i*i;

    change[0]=1;
    for(i=1;i<=22;i++)
    {
        x=cube[i];
        for(j=x,k=0;j<=100000;k++,j++)
        {
            if(j+x<=100000)
            {
                change[j]+=change[k];

            }
        }
    }
    //for(i=0;i<20;i++)
    //printf("%d ",change[i]);

    while(scanf("%lld",&x)==1)
    {
        //if(change[x]==1)
        //printf("There is only 1 way to produce %lld cents change.\n",x);
        //else
        printf("%lld\n",change[x]);
    }
    return 0;
}
