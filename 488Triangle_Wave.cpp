#include<stdio.h>
#define LL long long
int main()
{
    LL tc,i,j,k,a,f;
    bool f1=false,f2=false;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&a,&f);
        if(f1)
        printf("\n");
        f2=false;
        for(i=0;i<f;i++)
        {
            if(f2)
            printf("\n");
            for(j=1;j<=a;j++)
            {
                for(k=1;k<=j;k++)
                printf("%lld",j);
                printf("\n");

            }
            for(j=1;j<a;j++)
            {
                for(k=1;k<=a-j;k++)
                printf("%lld",a-j);
                printf("\n");

            }
            f2=true;

        }
        f1=true;
    }
    return 0;
}
