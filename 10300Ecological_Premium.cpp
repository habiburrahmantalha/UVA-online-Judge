#include<stdio.h>

int main()
{
    int tc,n,l,a,e,sum,i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&l,&a,&e);
            sum+=l*e;
        }
        printf("%d\n",sum);
    }
    return 0;
}
