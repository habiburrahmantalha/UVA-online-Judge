#include<stdio.h>
#include<string.h>

int g[110][110],mx,n,k;
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
int d[110][110];

bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
    return false;
    return true;
}
void penny_collect(int x,int y,int sum)
{
    d[x][y]=sum;
    int i,j,u,v;
    if(sum>mx)
    {
        mx=sum;
    }
    for(i=1;i<=k;i++)
    {
        for(j=0;j<4;j++)
        {
            u=x+X[j]*i;
            v=y+Y[j]*i;

            if(valid(u,v) && g[x][y]<g[u][v] && d[u][v]<sum+g[u][v])
                penny_collect(u,v,sum+g[u][v]);
        }
    }

}
int main()
{
    int tc,i,j;
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)
            printf("\n");
        f=true;
        scanf("%d %d",&n,&k);

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                scanf("%d",&g[i][j]);
        }
        mx=0;
        memset(d,0,sizeof(d));
        penny_collect(0,0,g[0][0]);
        printf("%d\n",mx);

    }
    return 0;
}
