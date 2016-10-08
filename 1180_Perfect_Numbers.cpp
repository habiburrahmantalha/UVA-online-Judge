#include<stdio.h>

int main()
{
    int n,i,x;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n-1;i++)
        {
            scanf("%d,",&x);
            if(x==2 || x==3 || x==5 || x==7 || x==13 || x==17)
                printf("Yes\n");
            else
                printf("No\n");
        }
        scanf("%d",&x);
        if(x==2 || x==3 || x==5 || x==7 || x==13 || x==17)
                printf("Yes\n");
            else
                printf("No\n");
    }
    return 0;
}
