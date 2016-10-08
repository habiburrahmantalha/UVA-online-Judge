#include<stdio.h>

int main()
{
    int tc,x[11],t,i,max;
    char web[11][110];
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        max=0;
        for(i=0;i<10;i++)
        {
            scanf("%s %d",web[i],&x[i]);
            if(max<x[i])
                max=x[i];
        }
        printf("Case #%d:\n",t);
        for(i=0;i<10;i++)
        {
            if(max==x[i])
                printf("%s\n",web[i]);
        }
    }
    return 0;
}
