#include<stdio.h>
#define eps 1e-9
#include<math.h>
int main()
{
    int n,i;
    long double sum,x[1001],res1,res2;
    long long avg;
    while(scanf("%d",&n) && n)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%Lf",&x[i]);
            x[i]*=100+eps;
            sum+=x[i];
        }
        avg=sum/n;

        res1=res2=0;
        for(i=0;i<n;i++)
        {
            if(x[i]<avg)
                res1+=avg-x[i];
        }
        for(i=0;i<n;i++)
        {
            if(x[i]>avg)
                res2+=x[i]-avg;
        }

        if(res1>res2)
            res1=res2;

        printf("$%.2Lf\n",res1/100);
    }
    return 0;
}
