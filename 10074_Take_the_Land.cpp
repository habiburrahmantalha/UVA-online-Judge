#include<stdio.h>
#include<string.h>

int g[110][110],n,m;
int no_tree(int a,int b,int x,int y)
{
    int i,j,c=0;
    for(i=a;i<=x;i++)
    for(j=b;j<=y;j++)
    if(g[i][j]==1)
    return 0;
    else
    c++;
    return c;
}
void MAX_RECTANGE()
{
    int i,j,k,l,e,max=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(k=1;k<=i;k++)
            {
                for(l=1;l<=j;l++)
                {
                    e=(i-k+1)*(j-l+1);
                    if(e==no_tree(k,l,i,j))
                    if(max<e)
                    max=e;
                }

            }
        }
    }
    printf("%d\n",max);
}

int main()
{
    int i,j;
    while(scanf("%d %d",&n,&m)==2 && n+m)
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        scanf("%d",&g[i][j]);

        MAX_RECTANGE();
    }
    return 0;
}
