#include<stdio.h>

int main()
{
    int t,x,max,sum,a[100000],i;
    while(1)
    {


        scanf("%d",&t);
        if(t==0)
        break;
        sum=0;
        scanf("%d",&a[0]);
        max=a[0];
        for(i=1;i<t;i++)
        {
            scanf("%d",&a[i]);
            sum=a[i]+a[i-1];
            if(a[i]<sum)
            a[i]=sum;
            if(max<a[i])
            max=a[i];
        }
        if(max<=0)
        printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",max);
    }
}
