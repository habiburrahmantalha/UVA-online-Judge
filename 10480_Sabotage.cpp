#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

int g[55][55],mn;
int n,visit[55],pi[55],visit2[55];
int gc[55][55];

bool bfs()
{
    queue<int>q;
    int u,v,i;
    memset(visit,0,sizeof(visit));
    for(i=0;i<=n;i++)
    pi[i]=i;

    visit[1]=1;
    q.push(1);
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(v=1;v<=n;v++)
        {
            if(g[u][v] && visit[v]==0)
            {
                visit[v]=1;
                pi[v]=u;
                q.push(v);
                if(v==2)
                return true;
            }
        }
    }
    return false;
}
void min_path(int x)
{
    if(x==1)
    return;
    else
    {
        //printf("%d %d\n",pi[x],x);
        if(mn>g[pi[x]][x])
        mn=g[pi[x]][x];
        min_path(pi[x]);
    }
}
void minus_path(int x)
{
    if(x==1)
    return;
    else
    {
        g[pi[x]][x]-=mn;
        g[x][pi[x]]-=mn;
        minus_path(pi[x]);
    }
}
void dfs_dest(int u)
{
    visit2[u]=1;
    for(int v=1;v<=n;v++)
    {
        if(g[u][v] && visit2[v]==0 )
        {
            dfs_dest(v);
        }
    }
}
void dfs_sorc(int u)
{
    visit[u]=1;
    for(int v=1;v<=n;v++)
    {
        if(g[u][v]==0 && visit2[v] && gc[u][v])
        {
            printf("%d %d\n",u,v);

        }
        else
        {
            if(gc[u][v] && visit[v]==0)
            dfs_sorc(v);
        }

    }
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        printf("%d ",g[i][j]);
        printf("\n");
    }
}
int main()
{
    int i,m,a,b,c;

    while(scanf("%d %d",&n,&m)==2 && n+m)
    {
        memset(g,0,sizeof(g));
        memset(gc,0,sizeof(gc));
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[a][b]=g[b][a]=c;
            gc[a][b]=gc[b][a]=1;

        }


        while(bfs())
        {
            //for(i=0;i<=n;i++)
            //printf("%d ",pi[i]);
            mn=50000000;
            min_path(2);

            minus_path(2);

        }
        //print();
        memset(visit,0,sizeof(visit));
        memset(visit2,0,sizeof(visit2));

        dfs_dest(2);
        dfs_sorc(1);
        printf("\n");

    }
    return 0;
}
