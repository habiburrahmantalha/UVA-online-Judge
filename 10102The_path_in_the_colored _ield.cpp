#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
char g[101][101];
int n, d[101][101];


bool valid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n)
    return true;
    return false;
}

int bfs(int x,int y)
{
    memset(d,-1,sizeof(d));
    queue<int> q;
    int u,v,i;

    q.push(x);
    q.push(y);
    d[x][y]=0;
    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            x=u+X[i];
            y=v+Y[i];
            if(valid(x,y) && d[x][y]==-1)
            {
                d[x][y]=d[u][v]+1;
                if(g[x][y]=='3')
                return d[x][y];
                q.push(x);
                q.push(y);
            }
        }
    }
}

int main()
{
    int i,j,step,max;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",g[i]);
        }
        max=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]=='1')
                {
                    step=bfs(i,j);
                    //printf("%d\n",step);
                    if(max<step)
                    max=step;
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
