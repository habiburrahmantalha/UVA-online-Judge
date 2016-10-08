#include<cstdio>
#include<queue>
#include<string.h>
#include<math.h>
using namespace std;
#define LL long long
LL m,n,visit[755];
LL g[755][755],d[755],pi[755];
struct xy
{
    LL x,y;
};

void prim()
{

	LL a,b,i;
	priority_queue < pair <LL,LL> >pq;
	pair<LL,LL> p;
	memset(d,0x7F,sizeof(d));
	memset(visit,0,sizeof(visit));
	memset(pi,0,sizeof(pi));

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
/*
    for(i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%5lld",g[i][j]);
            printf("\n");
        }*/

	while( !pq.empty() )
	{
		p=pq.top();
		pq.pop();
		a=p.second;

		visit[a]=1;
		for(b=0;b<n;b++)
		{
			if(a!=b && visit[b]==0)
			{
				if(d[b]>g[a][b])
				{
					d[b]=g[a][b];
					pi[b]=a;
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

	LL i,j,tc;
	bool f=false,res;
	xy p[755];
	scanf("%lld",&tc);
	while(tc--)
	{
	    if(f)
	    printf("\n");
	    scanf("%lld",&n);
	    memset(g,-1,sizeof(g));

        for( i=0; i<n; i++)
            scanf("%lld %lld",&p[i].x,&p[i].y);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                    g[i][j]=g[j][i]=dist(p[i],p[j]);
            }
        }


        prim();
        res=false;
        for( i=0; i<n; i++)
            if(g[i][pi[i]]!=0)
            {
                printf("%lld %lld\n",i+1,pi[i]+1);
                res=true;
            }
        if(!res)
            printf("No new highways need\n");
        f=true;
	}
	return 0;
}
