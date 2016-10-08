//Problem Type : tree,diameter,mst ?
//Time : ??
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)

int g[30][30],d[30],visit[30],pi[30];

int n,m;

void dijkstra(int u)
{
    priority_queue<pair<int,int> >pq;
    int v;
    memset(d,63,sizeof(d));

    pq.push(make_pair(0,u));
    d[u]=0;
    visit[u]=1;
    pi[0]=0;
    while(!pq.empty())
    {
        u=pq.top().second;pq.pop();

        for(v=0;v<n;v++)
        {
            if(g[u][v] && d[v]>d[u]+1 )
            {
                d[v]=d[u]+1;
                pi[v]=u;
                pq.push(make_pair(d[v],v));
            }
        }
    }
}

void bfs(int u)
{
    queue<int>q;
    int v;
    memset(visit,0,sizeof(visit));
    memset(d,0,sizeof(d));

    q.push(u);
    d[u]=0;
    visit[u]=1;
    while(!q.empty())
    {
        u=q.front();q.pop();

        for(v=0;v<n;v++)
        {
            if(g[u][v] && visit[v]==0)
            {
                d[v]=d[u]+1;
                visit[v]=1;
                q.push(v);
            }
        }
    }
}

void diameter()
{
    int i,mx,x;
    bfs(0);
    mx=0;
    for(i=0;i<n;i++)
    {
        if(d[i]>mx)
        {
            mx=d[i];
            x=i;
        }
    }
    bfs(x);
    mx=0;
    for(i=0;i<n;i++)
    {
        if(d[i]>mx)
        {
            mx=d[i];
            x=i;
        }
    }
    printf("%d\n",mx);
}

int main()
{
    int tc,a,b,i,t=1;;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a][b]=g[b][a]=1;
        }
        dijkstra(0);
        memset(g,0,sizeof(g));
        for(i=1;i<n;i++)
        g[i][pi[i]]=g[pi[i]][i]=1;
        diameter();
    }
    return 0;
}
