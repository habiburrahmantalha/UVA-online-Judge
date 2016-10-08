#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
    int x[101],n,i,y,buffer;
    memset(x,0,sizeof(x));
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            //read(0, buffer, y);
            scanf("%d",&y);
            x[y]++;
        }
        for(i=0;i<=100;i++)
        {
            if(x[i])
            {
                printf("%d",i);
                x[i]--;
                break;
            }
        }
        for(;i<=100;i++)
        {
            if(x[i])
            while(x[i]--)
                printf(" %d",i);

        }
        printf("\n");
    }
    return  0;
}
