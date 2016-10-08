#include<stdio.h>
#include<string.h>
int main()
{
    int x,in,y[100],i;
    while(scanf("%d",&x) && x>=0)
    {
        in=0;
        memset(y,0,sizeof(y));
        if(x==0)
        printf("0");
        while(x)
        {
            y[in++]=x%3;
            x/=3;
        }
        for(i=in-1;i>=0;i--)
        printf("%d",y[i]);
        printf("\n");
    }
    return 0;
}
