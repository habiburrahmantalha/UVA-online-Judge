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

vector<int> g[10010],cost[10010];
int d[10010][610],n;
bool H[10010];

void dijkstra()
{
    queue<int> q;
    int u,t,c,v,tt,i;
    memset(d,63,sizeof(d));
    //printf("%d\n",d[0][0]);
    q.push(1);
    q.push(600);
    d[1][600]=0;

    while(!q.empty())
    {
        u=q.front();q.pop();
        t=q.front();q.pop();

        //printf("%d %d %d\n",u,t,h);
        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            c=cost[u][i];
            if(t>=c)
            {
                tt=t-c;
                if(d[v][tt]>d[u][t])
                {
                    d[v][tt]=d[u][t];
                    q.push(v);
                    q.push(tt);

                }
                if(H[v])
                {
                    if(d[v][600]>d[u][t]+1)
                    {
                        d[v][600]=d[u][t]+1;
                        q.push(v);
                        q.push(600);
                    }
                }
            }

        }

    }
}

int main()
{
    int h,i,x,m,a,b,c,mn;
    while(scanf("%d",&n)==1 && n)
    {
        memset(H,false,sizeof(H));
        scanf("%d",&h);
        for(i=0;i<h;i++)
        {
            scanf("%d",&x);
            H[x]=true;
        }

        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[a].push_back(b);
            g[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        dijkstra();

        mn=d[n][0];
        for(i=0;i<=600;i++)
        if(mn>d[n][i])
        mn=d[n][i];

        if(mn==1061109567)
        mn=-1;
        printf("%d\n",mn);

        //for(i=1;i<=n;i++)
        //printf("%d %d %d\n",i,d[i][0],d[i][1]);

        for(i=0;i<=n;i++)
        {
            g[i].clear();
            cost[i].clear();
        }


    }

    return 0;
}
