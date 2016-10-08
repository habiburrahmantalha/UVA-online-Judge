#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
int visit[101][101],n,count;
char g[101][101];

bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;
}

void visit_dfs(int x,int y)
{
    int a,b;
    for(int i=0;i<n;i++)
    {
        a=x+X[i];
        b=y+Y[i];
        if(valid(a,b) && visit[a][b]==0 && (g[a][b]=='x' || g[a][b]=='@'))
        {
            visit[a][b]=1;
            visit_dfs(a,b);
        }
    }
}

void dfs()
{
    count=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(g[i][j]=='x' && visit[i][j]==0)
        {
            visit_dfs(i,j);
            visit[i][j]=0;
            count++;
        }
}

int main()
{
    int tc,t,i,j;

    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        memset(g,0,sizeof(g));
        memset(visit,0,sizeof(visit));
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",g[i]);
        dfs();
        printf("Case %d: %d\n",t,count);
    }
    return 0;
}
