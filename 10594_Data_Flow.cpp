#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

long long t[110][110],g[110][110],visit[110],pi[110],n,m,d[110];

bool bfs()
{

    priority_queue<pair<long long ,long long> > q;
    long long u,v,i;
    memset(visit,0,sizeof(visit));
    memset(d,0x7F,sizeof(d));
    //visit[1]=1;
    d[1]=0;
    pi[1]=1;
    q.push(make_pair(0,1));

    while(!q.empty())
    {
        u=q.top().second;q.pop();
        visit[u]=1;
        for(v=1;v<=n;v++)
        {
            if(d[v]>t[u][v]+d[u] && g[u][v] && visit[v]==0)
            {
                //printf("%d ",v);
                d[v]=d[u]+t[u][v];

                pi[v]=u;
                q.push(make_pair(-d[v],v));

            }
        }

    }
    if(visit[n])
        return true;
    return false;
}
int main()
{
    long long i,a,b,c,data,link,res,time,mn,u,v;
    while(scanf("%lld %lld",&n,&m)==2)
    {
        memset(g,0,sizeof(g));
        for(i=0;i<m;i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            t[a][b]=c;
            t[b][a]=-c;
            g[a][b]=g[b][a]=1;
        }
        scanf("%lld %lld",&data,&link);
        res=0;
        while(bfs() && data>0)
        {
            time=0;
            for(v=n;v!=1;v=pi[v])
            {
                u=pi[v];
                //printf("%d %d\n",u,v);
                //time+=t[u][v];
                //g[v][u]=0;
                g[u][v]=0;
            }
            res+=d[n]*min(data,link);
            data-=link;

        }
        if(data<=0)
        printf("%lld\n",res);
        else
        printf("Impossible.\n");
    }
    return 0;
}
