#include<stdio.h>

struct hotel
{
    int b;
    int w[14];
};
int main()
{
    hotel h[20];
    int N,B,H,W,i,j,res;
    while(scanf("%d %d %d %d",&N,&B,&H,&W)==4)
    {
        for(i=0;i<H;i++)
        {
            scanf("%d",&h[i].b);
            for(j=0;j<W;j++)
                scanf("%d",&h[i].w[j]);

        }
        res=5000000;
        for(i=0;i<H;i++)
        {
            for(j=0;j<W;j++)
            {
                if(h[i].w[j]>=N)
                {
                    if(res>h[i].b*N)
                        res=h[i].b*N;
                    break;
                }
            }

        }
        if(res<=B)
            printf("%d\n",res);
        else
            printf("stay home\n");

    }
    return 0;
}
