#include<stdio.h>

int main()
{
    int tc,x,n;
    scanf("%d",&tc);
    for(int i=1;i<=tc;i++)
    {
        int max=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&x);
            if(max<x)
            max=x;
        }
        printf("Case %d: %d\n",i,max);

    }
    return 0;
}
