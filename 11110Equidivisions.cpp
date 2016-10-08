#include<stdio.h>
#include<string.h>

int n,g[101][101],visit[101][101];
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};

bool valid(int x,int y)
{
    if(x<0 || x>n || y<0 || y>n)
    return false;
    return true;
}

int dfs_visit(int x,int y,int a)
{
    visit[x][y]=1;
    int u,v,count=0,i;
    count++;
    for(i=0;i<4;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v) && visit[u][v]==0 && g[u][v]==a)
        count+=dfs_visit(u,v,a);
    }
    return count;

}



bool dfs()
{
    int i,j,count;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(visit[i][j]==0)
            count=dfs_visit(i,j,g[i][j]);
            if(count!=n)
            return false;
        }
    }
    return true;
}

int main()
{
    int i,j,x,y;
    bool f;
    while(scanf("%d",&n) && n)
    {

        //memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            g[i][j]=5;

        memset(visit,0,sizeof(visit));

        for(i=1;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d %d",&x,&y);
                g[--x][--y]=i;
            }
        }

        if(dfs())
            printf("good\n");
		else
            printf("wrong\n");

    }

    return 0;
}

