#include<stdio.h>

void factor(int k)
{
    int i;

    for(i=2;i*i<=k;i++)
    {
        if(k%i==0)
        {
            printf(" %d * %d ",i,k/i);
            break;
        }
    }
    printf("=");
    for(i=i+1;i*i<=k;i++)
    {
        if(k%i==0)
        {
            printf(" %d * %d\n",i,k/i);
            break;
        }
    }
}
int main()
{
    int tc,t=1,k;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&k);

        printf("Case #%d: %d =",t++,k);
        factor(k);
    }
    return 0;
}
