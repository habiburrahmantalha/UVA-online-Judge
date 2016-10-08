//need better way

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include<vector>
using namespace std;

//int n,g[111][111],pi[111],d[111];
int n;
vector<int>g[111];
int d[111],pi[111];

int bfs( int s )
{
	queue <int> q;

	int u,v,max=0,last;

	d[s] = 0;
	pi[s] = s;
	q.push(s);

	while ( !q.empty() )
	{
		u = q.front();
		q.pop();
		for ( v = 0; v <g[u].size(); v ++ )
		{
			//if ( g[u][v] == 1 )
			{
				d[v]+= d[u] + 1;
				pi[v] = v;
				q.push(v);
				if(max<d[v])
				{
				    max=d[v];
				    last=v;
				}
			}
		}
	}
	return last;
}



int main()
{
	int a,b,tc=1,s;
	while(scanf("%d",&n) && n)
	{
	    scanf("%d",&s);

		memset(g, 0, sizeof(g) );
        memset( pi, 0, sizeof(pi));
        memset( d, 0, sizeof(d));

		while(scanf("%d %d",&a, &b) && a && b)
			g[a].push_back(b);

		int last = bfs(s);

		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",tc++,s,d[last],pi[last]);
	}
	return 0;
}
/*
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <iostream>
typedef long long ll;
using namespace std;
struct node { int u,cost; };
queue <node> q;
int inde[1000];
int graph[1000][101];
int n,s,max1,res; int Cost[101];
void bfs()
{
    node t,d;
    int i,v;
    t.u=s;
    t.cost=max1=res=0;
    q.push(t);
    while(!q.empty())
        {
            t=q.front();
            q.pop();
            for(i=0;i<inde[t.u];i++)
                { v=graph[t.u][i];
            if(Cost[v]<(t.cost+1))
                { Cost[v]=t.cost+1;
            d.u=v; d.cost=Cost[v];
            q.push(d);
            if(max1==d.cost&&v<res)
                res=v; if(max1<d.cost)
                { max1=d.cost; res=v; }
            } } }
printf("The longest path from %d has length %d, finishing at %d.\n",s,max1,res);
} int main()
{
    int p,q,i,Case=1;
    while(1)
        {
            scanf("%d",&n);
    if(!n) break;
    scanf("%d",&s);
    memset(inde,0,sizeof(inde));
    memset(graph,0,sizeof(graph));
    while(1) { scanf("%d %d",&p,&q); if(!p&&!q) break;
    graph[p][inde[p]++]=q; } printf("Case %d: ",Case++);
    if(n==1)
        printf("The longest path from 1 has length 0, finishing at 1.\n");
    else bfs();
    memset(Cost,0,sizeof(Cost));
    printf("\n"); }
    return 0;
    }

*/
