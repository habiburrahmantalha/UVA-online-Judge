//Problem Type : LCA,prims,bfs
//Time : 820
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

int pi[100010],l[100010];
long long d[100010];
bool visit[100010];
int n;
vector<int>g[100010],cost[100010];

void bfs(int s)
{
    queue<int> q;
    int u,v,i,c;
    memset(pi,0,sizeof(pi));
    memset(d,0,sizeof(d));
    memset(l,0,sizeof(l));
    memset(visit,0,sizeof(visit));

    visit[s]=1;
    d[s]=l[s]=0;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            c=cost[u][i];
            if(visit[v]==0)
            {
                pi[v]=u;
                d[v]=d[u]+c;
                l[v]=l[u]+1;
                visit[v]=1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int i,a,b,q;
    long long c;
    while(scanf("%d",&n) && n)
    {
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&a,&c);
            g[i].push_back(a);
            g[a].push_back(i);
            cost[i].push_back(c);
            cost[a].push_back(c);
        }
        bfs(0);
        //for(i=0;i<n;i++)
        //printf("%d %d\n",i,d[i]);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            c=d[a]+d[b];
            while(a!=b)
            {
                if(l[a]==l[b])
                {
                    a=pi[a];
                    b=pi[b];
                }
                else if(l[a]>l[b])
                {
                    a=pi[a];
                }
                else
                {
                    b=pi[b];
                }
            }
            //printf("%d %d %d %d\n",pi[a],pi[b],a,b);
            if(q)
            printf("%lld ",c-d[a]-d[b]);
            else
            printf("%lld\n",c-d[a]-d[b]);

        }
        for(i=0;i<n;i++)
        {
            g[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
