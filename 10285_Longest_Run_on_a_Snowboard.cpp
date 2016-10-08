#include<stdio.h>
#include<string.h>
int g[110][110],d[110][110];
int R,C;
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
bool valid(int x,int y)
{
    if(x<0 || x>=R || y<0 || y>=C)
        return false;
    return true;
}

void snowboarding(int x,int y,int k)
{
    int i,u,v;
    if(d[x][y]>k)
        return;
    d[x][y]=k;
    for(i=0;i<4;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v) && g[u][v]<g[x][y])
            snowboarding(u,v,k+1);
    }

}
int main()
{
    int tc,i,j,mx;
    char name[100];
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%s %d %d",name,&R,&C);
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            scanf("%d",&g[i][j]);
        memset(d,0,sizeof(d));
        mx=0;
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                snowboarding(i,j,1);
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            {
                if(mx<d[i][j])
                    mx=d[i][j];
            }
        printf("%s: %d\n",name,mx);

    }
    return 0;
}
