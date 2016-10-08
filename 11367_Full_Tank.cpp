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

vector<int> g[1010],cost[1010];
int dist[1010][110],n,m;
int INF,C,S,E,fuel[1010];

void bfs()
{
    priority_queue<pair<int,pair<int,int> > >pq;
    int u,v,ff,f,c,d,i,j;
    memset(dist,63,sizeof(dist));
    INF=dist[0][0];

    dist[S][0]=0;
    pq.push(make_pair(0,make_pair(S,0)));

    while(!pq.empty())
    {

        u=pq.top().second.first;
        f=pq.top().second.second;
        pq.pop();

        if(u==E)
        return;

        //op 1 : get 1 fuel and stay
        if(f+1<=C && dist[u][f+1]>dist[u][f]+fuel[u])
        {
            dist[u][f+1]=dist[u][f]+fuel[u];
            pq.push(make_pair(-dist[u][f+1],make_pair(u,f+1)));
        }

        //op 2 :    next city
        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            d=cost[u][i];
            if(f>=d)
            {
                ff=f-d;
                if(dist[v][ff]>dist[u][f])
                {
                    dist[v][ff]=dist[u][f];
                    pq.push(make_pair(-dist[v][ff],make_pair(v,ff)));
                }
            }


        /*
        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            d=cost[u][i];

            //op 1: still have fuel to go on
            if(f>=d)
            {
                ff=f-d;
                if(dist[v][ff]>dist[u][f])
                {
                    dist[v][ff]=dist[u][f];
                    pq.push(make_pair(-dist[v][ff],make_pair(v,ff)));
                }
            }

            //op 2: to full tank
            for(j=C;j>=d && j>=f ;j--)
            {
                c=fuel[u]*(j-f);
                ff=j-d;
                if(dist[v][ff]>dist[u][f]+c)
                {
                    dist[v][ff]=dist[u][f]+c;
                    pq.push(make_pair(-dist[v][ff],make_pair(v,ff)));
                }
            }

        */
        }
    }
}
void distance()
{
    //int i,mn=INF;
    //for(i=0;i<=C;i++)
        //mn=min(mn,dist[E][i]);
    if(dist[E][0]==INF)
        printf("impossible\n");
    else
        printf("%d\n",dist[E][0]);
}

int main()
{
    int i,a,b,c,q;
    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0;i<n;i++)
        scanf("%d",&fuel[i]);

        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[a].push_back(b);
            g[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d %d",&C,&S,&E);
            bfs();
            distance();
        }
        for(i=0;i<n;i++)
        {
            g[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
