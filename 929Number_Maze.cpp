#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

int g[1000][1000],d[1000][1000],visit[1000][1000];
int m,n;
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};

bool valid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
    return true;
    else
    return false;

}

void dijkstra(int x,int y)
{

	int a,b,c,i;
	priority_queue < pair < int,pair <int,int> > > pq;
	pair < int,pair <int,int> > u;
	pair<int,int> v;
	pair<int,int> exis;
	memset(d,0x7F,sizeof(d));
	memset(visit,0,sizeof(visit));

	d[x][y]=g[x][y];
	visit[x][y]=1;

	pq.push(make_pair(-g[x][y],make_pair(x,y)));
	while( !pq.empty() )
	{
		u=pq.top();
		pq.pop();
		c=u.first;
		v=u.second;
		x=v.first;
		y=v.second;

		for(i=0;i<4;i++)
		{
		    a=x+X[i];
		    b=y+Y[i];

			if(valid(a,b) && visit[a][b]==0)
			{
				if(d[a][b]>d[x][y]+g[a][b])
				{
				    visit[a][b]=1;
					d[a][b]=d[x][y]+g[a][b];
					pq.push(make_pair(-d[a][b],make_pair(a,b)));
				}

			}
		}
	}
}

int main()
{
    int tc,i,j;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&g[i][j]);
            }
        }
        dijkstra(0,0);
        printf("%d\n",d[n-1][m-1]);
    }
    return 0;
}
