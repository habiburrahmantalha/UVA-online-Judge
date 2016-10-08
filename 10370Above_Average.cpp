#include<stdio.h>

int main()
{
    int t,a[1001],sum,i;
    double avg,res,count,n;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lf",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }

        avg=sum/n;

        count=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>avg)
            count++;
        }
        res=count/n;
        printf("%.3lf%\n",res*100);
    }
    return 0;
}
