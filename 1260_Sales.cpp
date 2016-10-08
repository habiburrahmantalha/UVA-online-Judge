#include<stdio.h>
#include<string.h>

int main()
{
    int sum,tc,n,x,f[5010],j,i;
    scanf("%d",&tc);

    while(tc--)
    {
        memset(f,0,sizeof(f));
        scanf("%d",&n);
        sum=0;
        scanf("%d",&x);
        f[x]++;

        for(i=1;i<n;i++)
        {
            scanf("%d",&x);

            for(j=0;j<=x;j++)
                sum+=f[j];
            f[x]++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
