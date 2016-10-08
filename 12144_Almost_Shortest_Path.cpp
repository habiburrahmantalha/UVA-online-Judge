//almost shortest path
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int g[510][510],d[510];
vector<int>pi[510];
int n,m,INF;
void dijkstra(int u)
{
    int i,v,c;
    priority_queue<pair<int,pair<int,int> > >pq;
    memset(d,63,sizeof(d));
    for(i=0;i<n;i++)
    pi[i].clear();
    INF=d[0];
    pq.push(make_pair(-0,make_pair(u,u)));
    while(!pq.empty())
    {
        u=pq.top().second.first;
        v=pq.top().second.second;
        c=-pq.top().first;
        pq.pop();
        if(c>d[v])continue;
        d[v]=c;
        pi[v].push_back(u);
        for(i=0;i<n;i++)
            if(g[v][i] && d[v]+g[v][i]<=d[i])
                pq.push(make_pair(-(d[v]+g[v][i]),make_pair(v,i)));
    }
}
void remove(int t)
{
    if(pi[t].size()==0 || pi[t][0]==t)
    return;
    for(int i=0;i<pi[t].size();i++)
    {
        g[pi[t][i]][t]=0;
        remove(pi[t][i]);
    }
}
int main()
{
    int s,e,i,a,b,c,mn;
    while(scanf("%d %d",&n,&m)==2 && n+m)
    {
        scanf("%d %d",&s,&e);
        memset(g,0,sizeof(g));

        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[a][b]=c;
        }
        dijkstra(s);
        remove(e);
        dijkstra(s);
        if(d[e]<INF)
        printf("%d\n",d[e]);
        else
        printf("-1\n");
    }
    return 0;
}
