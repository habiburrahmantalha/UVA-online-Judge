#include<stdio.h>
#include<string.h>

int main()
{
    int tc,i,j,sum,coin[100+5],divide[50000+5],n,diff;
    scanf("%d",&tc);
    while(tc--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&coin[i]);
            sum+=coin[i];
        }
        memset(divide,0,sizeof(divide));

        divide[0]=1;
        for(i=0;i<n;i++)
        {
            for(j=sum;j>=0;j--)
            {
                if(divide[j])
                {
                    divide[j+coin[i]]=1;
                }
            }
        }

        if(sum%2==0)
        {
            for(i=sum/2;i>=0;i--)
            if(divide[i])
            {
                diff=i;
                break;
            }
            printf ("%d\n", ((sum / 2) - diff)*2 );
        }
        else
        {
            for(i=sum/2;i>=0;i--)
            if(divide[i])
            {
                diff=i;
                break;
            }
            printf ("%d\n", ((sum / 2) - diff) *2+1);
        }

    }
    return 0;
}
