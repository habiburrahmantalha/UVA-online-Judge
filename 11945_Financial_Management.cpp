#include<stdio.h>

int main()
{
    int tc,k=1,sum2;
    double x,sum;
    scanf("%d",&tc);

    while(tc--)
    {
        sum=0.0;
        for(int i=0;i<12;i++)
        {
            scanf("%lf",&x);
            sum+=x;
        }
        sum/=12;
        sum2= sum/1000;
        printf("%d $",k++);
        if(sum2){
            printf("%d,",sum2);
            printf("%.2lf\n",sum-sum2*1000);

        }
        else
        printf("%.2lf\n",sum);
    }
    return 0;
}
