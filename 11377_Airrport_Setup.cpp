#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
#define inf 20000000
int d[2010],n;
bool airport[2010];
vector<int> g[2010];

void dijkstra(int s)
{
    priority_queue<pair<int,int> > pq;
    int u,v,i,c;

    for(i=0;i<=n;i++)
    d[i]=inf;

    pq.push(make_pair(0,s));
    if(airport[s])
    d[s]=0;
    else
    d[s]=1;

    while(!pq.empty())
    {
        u=pq.top().second;
        pq.pop();

        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(airport[v])
            c=d[u];
            else
            c=d[u]+1;
            if(d[v]>c)
            {
                d[v]=c;
                pq.push(make_pair(-d[v],v));
            }
        }
    }
}

int main()
{
    int tc,t=1,a,b,m,k,q,i,x;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d\n",&n,&m,&k);
        memset(airport,false,sizeof(airport));
        for(i=0;i<k;i++)
        {
            scanf("%d",&x);
            airport[x]=true;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        scanf("%d",&q);
        printf("Case %d:\n",t++);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            if(a==b)
            printf("0\n");
            else
            {
                dijkstra(a);
                if(d[b]==inf)
                printf("-1\n");
                else
                printf("%d\n",d[b]);
            }
        }
        printf("\n");

        for(i=0;i<=n;i++)
        g[i].clear();
    }
    return 0;
}
