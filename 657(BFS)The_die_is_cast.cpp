#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

char g[51][51];
int visitb[51][51],visitd[51][51];
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};

int m,n;
bool valid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
    return true;
    return false;
}

int dfs(int x,int y)
{
    int i,u,v;
    visitd[x][y]=1;
    for(i=0;i<4;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v)&& g[u][v]=='X' && visitd[u][v]==0)
        {
                dfs(u,v);
        }
    }
}
int bfs(int x,int y)
{
    queue<int> q;
    int u,v,i,count=0;

    q.push(x);
    q.push(y);
    visitb[x][y]=1;
    if(g[x][y]=='X')
    {
        count++;
        dfs(x,y);
    }

    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            x=u+X[i];
            y=v+Y[i];
            if(valid(x,y) && visitb[x][y]==0 && (g[x][y]=='*' || g[x][y]=='X'))
            {

                if(g[x][y]=='X' && visitd[x][y]==0)
                {
                    //printf("a");
                    count++;
                    dfs(x,y);
                    visitb[x][y]=1;
                }
                else
                visitb[x][y]=1;
                q.push(x);
                q.push(y);
            }
        }
    }
    return count;
}

int main()
{
    int i,j,in,tc=1,x[100],y;
    while(scanf("%d %d",&m,&n) &&n &&m)
    {

        memset(g,0,sizeof(g));
        memset(visitb,0,sizeof(visitb));
        memset(visitd,0,sizeof(visitd));
        for(i=0;i<n;i++)
        {
            scanf("%s",g[i]);
        }
        in=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(visitb[i][j]==0 && (g[i][j]=='*' || g[i][j]=='X'))
                {

                    y=bfs(i,j);
                    //printf("%d",y);
                    if(y)
                    x[in++]=y;
                }
            }
        }
        sort(x,x+in);
        printf("Throw %d\n",tc++);
        if(in!=0)
        {
            for(i=0;i<in-1;i++)
            printf("%d ",x[i]);
            printf("%d\n",x[i]);
        }
        else
        printf("\n");
        printf("\n");
    }
    return 0;
}
