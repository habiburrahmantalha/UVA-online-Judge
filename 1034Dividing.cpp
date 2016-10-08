//হয় নাই

#include<stdio.h>

int main()
{
    int x,sum,tc=1;
    while(1)
    {
        sum=0;
        for(int i=1;i<=6;i++)
        {
            scanf("%d",&x);
            sum+=x*i;

        }
        if(sum==0)
        break;
        if(sum%2==0)
        printf("Collection#%d:\nCan be divided.\n",tc++);
        else
        printf("Collection#%d:\nCan't be divided.\n",tc++);
    }
}
