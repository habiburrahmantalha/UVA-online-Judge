#include<cstdio>
#include<queue>
#include<string.h>
#include<math.h>
using namespace std;
#define LL long long
LL m,n,visit[755];
LL g[755][755],d[755];
struct xy
{
    LL x,y;
};

void prim()
{

	LL a,b,i;
	priority_queue < pair < LL,LL> > pq;
	pair<LL,LL> u;
	memset(d,0x7F,sizeof(d));
	memset(visit,0,sizeof(visit));

	scanf("%lld",&m);
	for(i=0;i<m;i++)
	{
	    scanf("%lld %lld",&a,&b);
	    a--;
	    b--;
	    g[a][b]=0;
	    g[b][a]=0;
	}

    d[0]=0;
    pq.push(make_pair(0,0));



	while( !pq.empty() )
	{
		u=pq.top();
		pq.pop();
		a=u.second;
		visit[a]=1;
		for(b=0;b<n;b++)
		{
			if(g[a][b]!=-1 && visit[b]==0)
			{
				if(d[b]>g[a][b])
				{
					d[b]=g[a][b];
					pq.push(make_pair(-d[b],b));
				}

			}
		}
	}
}
LL dist(xy a,xy b)
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	double cost;
	LL i,j;
	xy p[755];
	while(scanf("%lld",&n)==1)
	{
	    memset(g,-1,sizeof(g));

        for( i=0; i<n; i++)
            scanf("%lld %lld",&p[i].x,&p[i].y);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    g[i][j]=g[j][i]=dist(p[i],p[j]);
                }
            }
        }


        prim();
        cost=0;
        for( i=0; i<n; i++)
		cost=cost+sqrt(d[i]);

        printf("%.2lf\n",cost);
	}
	return 0;
}
