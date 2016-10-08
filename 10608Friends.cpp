//পারি না :P
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

int n,g[1001][1001],visit[1001],d[1001];

int bfs(int s)
{
	queue <int> q;

	int u,v,max=0;

	memset( visit, 0, sizeof(visit));
	memset( d, 0, sizeof(d));

	visit[s] = 1;
	d[s] = 0;
	q.push(s);

	while ( !q.empty() )
	{
		u = q.front();
		q.pop();
		for ( v = 0; v < n; v ++ )
		{
			if ( visit[v] == 0 && g[u][v] == 1 )
			{
				visit[v] = 1;
				d[v] = d[u] + 1;
				q.push(v);
				if(max<d[v])
                max=d[v];
			}

		}
	}
	return max;
}



int main()
{
	int m,i,a,b,tc,mx,max;
	scanf("%d",&tc);
	while(tc--)
	{
	    max=0;
	    memset(g,0,sizeof(g));
	    scanf("%d %d",&n,&m);
	    for(i=0;i<m;i++)
	    {
	        scanf("%d %d",&a,&b);
	        g[a-1][b-1]=1;
	    }
	    for(i=0;i<n;i++)
	    {
	        mx=bfs(i);
	        if(max<mx)
	        max=max;
	    }
	    printf("%d\n",max);
	    for(i=0;i<n;i++)
	    printf("%d ",d[i]);


	}
	return 0;
}
