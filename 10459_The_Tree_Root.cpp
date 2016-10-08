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

vector<int>g[5010];
int visit[5010],d[5010],N;

void bfs(int s)
{
    queue<int>q;
    int u,v,i;

    memset(visit,0,sizeof(visit));
    memset(d,0,sizeof(d));

    visit[s]=1;
    d[s]=0;
    q.push(s);

    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(visit[v]==0)
            {
                visit[v]=1;
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
int max_dist(int i)
{
    bfs(i);
    int dist=0;
    for(i=1;i<=N;i++)
    if(dist<d[i])
        dist=d[i];
    return dist;
}
void diameter()
{
    vector<int>best;
    set<int>worst;
    set<int>::iterator it;
    int dx[5010],dy[5010];
    int i,j,dist,x,y,z;

    bfs(1);
    dist=0;
    for(i=1;i<=N;i++)
    if(dist<d[i])
    {
        dist=d[i];
        x=i;
    }

    bfs(x);
    dist=0;
    for(i=1;i<=N;i++)
    if(dist<d[i])
    {
        dist=d[i];
        y=i;
    }
    for(i=1;i<=N;i++)
    dx[i]=d[i];

    bfs(y);
    for(i=1;i<=N;i++)
    dy[i]=d[i];

    if(dist&1)
    z=(dist+1)/2;
    else
    z=dist/2;

    for(i=1;i<=N;i++)
    {
        if((z==dx[i] || z==dy[i] ) && z==max_dist(i))
        {
            best.push_back(i);

        }
    }
    for(i=0;i<best.size();i++)
    {
        bfs(best[i]);
        for(j=1;j<=N;j++)
        {
            if(z==d[j])
            {
                worst.insert(j);

            }
        }
    }
    printf("Best Roots  :");
    for(i=0;i<best.size();i++)
    printf(" %d",best[i]);
    printf("\n");

    printf("Worst Roots :");
    for(it=worst.begin();it!=worst.end();it++)
    printf(" %d",*it);
    printf("\n");

}

int main()
{
    int i,m,x;
    while(scanf("%d",&N)==1)
    {
        for(i=1;i<=N;i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&x);
                g[i].push_back(x);
            }
        }

        diameter();
        for(i=0;i<=N;i++)
        g[i].clear();

    }
    return 0;
}
