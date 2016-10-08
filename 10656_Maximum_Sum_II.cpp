#include<stdio.h>

int main()
{

    int i,j,x,a[1001],n;

    while(scanf("%d",&n) && n)
    {
        j=0;
        a[0]=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x!=0)
                a[j++]=x;
        }

        for(i=0;i<j-1;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[i]);
    }
    return 0;
}

