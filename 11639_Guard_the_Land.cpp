#include<stdio.h>
#include<string.h>
int main()
{
    int t=1,i,j,a[102][102],w,s,u,tc,x1,x2,y1,y2;
    scanf("%d",&tc);

    while(tc--)
    {
        s=w=u=0;
        memset(a,0,sizeof(a));
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(i=x1;i<x2;i++)
            for(j=y1;j<y2;j++)
            a[i][j]++;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(i=x1;i<x2;i++)
            for(j=y1;j<y2;j++)
            a[i][j]++;
        for(i=0;i<100;i++)
            for(j=0;j<100;j++)
            {
                if(a[i][j]==1)
                    w++;
                else if(a[i][j]==2)
                    s++;
            }
        u=100*100-w-s;
        printf("Night %d: %d %d %d\n",t++,s,w,u);
    }
    return 0;
}
