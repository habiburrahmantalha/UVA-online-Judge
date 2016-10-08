#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int g[1010][1010],d[1010],pi[1010],vi[1010];
int n;
void dijkstra(int s)
{
    int u,v;
    priority_queue<pair<int,int> > pq;
    memset(d,0x7F,sizeof(d));
    memset(vi,0,sizeof(vi));
    for(v=0;v<=n;v++)
    pi[v]=v;
    pq.push(make_pair(0,s));
    d[s]=0;

    while(!pq.empty())
    {
        u=pq.top().second;
        pq.pop();
        vi[u]=1;
        for(v=1;v<=n;v++)
        {
            if(g[u][v] && vi[v]==0 && d[u]+g[u][v]<d[v])
            {
                d[v]=d[u]+g[u][v];
                pi[v]=u;
                pq.push(make_pair(-d[v],v));
            }
        }
    }
}

void path(int s,int e)
{
    if(s==e)
    {
        printf(" %d",s);
        return;
    }
    path(s,pi[e]);
    printf(" %d",e);
}
int main()
{
    int i,j,b,c,s,e,t=1,m;
    while(scanf("%d",&n)==1 && n)
    {
        memset(g,0,sizeof(g));

        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d %d",&b,&c);
                g[i][b]=c;
            }
        }

        scanf("%d %d",&s,&e);
        dijkstra(s);
        printf("Case %d: Path =",t++);
        path(s,e);
        printf("; %d second delay\n",d[e]);
    }
    return 0;
}
