#include<stdio.h>
#include<string.h>

int a[110],p[1000010];
int main()
{
    int tc,i,n,b,r,x,y,in;
    bool f;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&n,&b,&r);
        memset(a,0,sizeof(a));
        for(i=0;i<b;i++)
        {
            scanf("%d %d",&x,&y);
            a[x]=y;
        }
        for(i=0;i<n;i++)
        p[i]=1;
        in=0;
        f=false;
        for(i=0;i<r;i++)
        {
            scanf("%d",&x);
            if(!f)
            {
                p[in]+=x;
                if(a[p[in]])
                p[in]=a[p[in]];
                if(p[in]>=100)
                {
                    f=true;
                    if(p[in]>100)
                    p[in]=100;
                }

            }
            in++;
            in=in%n;
        }
        for(i=0;i<n;i++)
        printf("Position of player %d is %d.\n",i+1,p[i]);

    }
    return 0;
}
