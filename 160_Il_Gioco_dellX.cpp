#include<stdio.h>
#include<string.h>


char g[210][210];
int n,visit[210][210];

int X[]={-1,-1,0,0,1,1};
int Y[]={-1,0,-1,1,0,1};

bool valid(int x,int y)
{
    if(x<0 || x>=n ||y<0 || y>=n)
        return false;
    return true;
}

void dfs(int x,int y)
{
    int i,u,v;
    visit[x][y]=1;
    for(i=0;i<6;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v) && visit[u][v]==0 && g[u][v]=='b')
            dfs(u,v);
    }
}

bool Black()
{
    int i,j,k,l;

    for(i=0;i<n;i++)
    {
        memset(visit,0,sizeof(visit));
        if(g[0][i]=='b')
        dfs(0,i);

        //for(k=0;k<n;k++){
        //for(l=0;l<n;l++)
          //  printf("%d ",visit[k][l]);
        //printf("\n");}printf("\n");

        for(j=0;j<n;j++)
        if(visit[n-1][j])
            return true;

    }
    return false;
}

int main()
{
    int i,t=1;
    while(scanf("%d",&n) && n)
    {
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
            scanf("%s",g[i]);

        if(Black())
            printf("%d B\n",t++);
        else
            printf("%d W\n",t++);
    }
    return 0;

}
