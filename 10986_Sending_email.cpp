#include<cstdio>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

int n;
vector<int> g[50010];
vector<int> cost[50010];

int d[50010];


void dijktra(int s,int t)
{
	int a,b,c;
	priority_queue < pair < int,int> > pq;
	pair<int,int> u;

	d[s]=0;
	pq.push(make_pair(0,s));
	while( !pq.empty() )
	{
		u=pq.top();
		pq.pop();
		c=u.first;
		a=u.second;

		for(b=0;b<g[a].size();b++)
		{
				if(d[g[a][b]]>d[a]+cost[a][b])
				{

					d[g[a][b]]=d[a]+cost[a][b];
					pq.push(make_pair(-d[g[a][b]],g[a][b]));

				}
		}
	}
}


int main()
{
	int a,b,c,i,m,s,tc,t,tcase=1;
	scanf("%d",&tc);
	while(tc--)
    {
        scanf("%d %d %d %d",&n,&m,&s,&t);
        memset(d,0x7F,sizeof(d));



        for( i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[a].push_back(b);
            g[b].push_back(a);

            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        if(m>0)
        dijktra(s,t);
        if(d[t]==2139062143)
        {
            if(s==t)
                printf("Case #%d: 0\n",tcase++);
            else
            printf("Case #%d: unreachable\n",tcase++);
        }
        else
        printf("Case #%d: %d\n",tcase++,d[t]);
        for(i=0;i<=n;i++)
        {
            g[i].clear();
            cost[i].clear();
        }
    }
	return 0;
}
