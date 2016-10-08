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

int g[255][255],d[255],s[255],N,M,C,K;

void dijkstra()
{
    priority_queue<pair<int,int> > pq;
    int u,v,i;


    d[K]=0;
    pq.push(make_pair(0,K));

    while(!pq.empty())
    {
        u=pq.top().second;pq.pop();
        if(u<C)
        continue;
        for(v=0;v<N;v++)
        {
            if(g[u][v]>=0 && d[v]>d[u]+g[u][v])
            {
                d[v]=d[u]+g[u][v];
                pq.push(make_pair(-d[v],v));
            }

        }
    }

}


int main()
{
    int i,j,a,b,p,mn;
    while(scanf("%d %d %d %d",&N,&M,&C,&K) && N+M+C+K)
    {
        memset(g,-1,sizeof(g));
        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&a,&b,&p);
            g[a][b]=g[b][a]=p;
        }
        memset(s,0,sizeof(s));
        for(i=C-2;i>=0;i--)
            s[i]=s[i+1]+g[i][i+1];

        memset(d,63,sizeof(d));
        mn=d[0];
        dijkstra();
        for(i=0;i<C;i++)
        mn=min(mn,s[i]+d[i]);
        printf("%d\n",mn);
    }
    return 0;
}
