#include<stdio.h>

int main()
{
    int tc,k=1,low,high,n,x[55],i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&x[i]);

        high=low=0;
        for(i=1;i<n;i++)
        if(x[i]>x[i-1])
        high++;
        else if(x[i]<x[i-1])
        low++;

        printf("Case %d: %d %d\n",k++,high,low);

    }
    return 0;
}
