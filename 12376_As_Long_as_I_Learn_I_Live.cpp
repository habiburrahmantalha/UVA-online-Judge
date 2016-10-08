#include<stdio.h>
#include<string.h>

int main()
{
    int tc,t=1,a,b,n,m,c[110],next[110],i,cost;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        scanf("%d",&c[i]);
        memset(next,-1,sizeof(next));
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            if(next[a]==-1)
            next[a]=b;
            else
            {
                if(c[b]>c[next[a]])
                next[a]=b;
            }
        }
        cost=0;
        a=0;
        b=next[a];
        while(b!=-1)
        {
            cost+=c[b];
            a=b;
            b=next[a];
        }
        printf("Case %d: %d %d\n",t++,cost,a);
    }
    return 0;
}
