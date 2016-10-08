#include<stdio.h>
#include<queue>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;

bool g[31][31];
int d[31],node;

void bfs(int s)
{
    int u,v;
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(v=0;v<node;v++)
        {
            if(g[u][v] && d[v]==-1)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}


int main()
{
    int n,i,a,b,qn,ttl,count,tcase=1;

    while(scanf("%d",&n) && n)
    {
        memset(g,false,sizeof(g));

        map < int, int > index;

        node =1;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            if(!index[a])
            index[a]=node++;
            if(!index[b])
            index[b]=node++;
            g[index[a]][index[b]]=g[index[b]][index[a]]=true;
        }

        while(scanf("%d %d",&qn,&ttl))
        {
            if(qn==0 && ttl==0)
            break;
            memset  (d, -1, sizeof (d));
            bfs(index[qn]);

            count=0;
            for(i=1;i<node;i++)
            {
                if(d[i]==-1 || d[i] > ttl)
                count++;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tcase++,count,qn,ttl);
        }
    }

}
