#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

int n,visit[30][30];
char g[30][30];

int X[]={-1,-1,-1,0,0,1,1,1};
int Y[]={-1,0,1,-1,1,-1,0,1};

bool valid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n)
    return true;
    else
    return false;
}



void bfs(int x,int y)
{
    int i,u,v;
    queue<int>q;


    q.push(x);
    q.push(y);

    visit[x][y]=1;

    while(!q.empty())
    {

        x=q.front();
        q.pop();
        y=q.front();
        q.pop();

        for(i=0;i<8;i++)
        {
            //printf("%d %d %d",x,y,z);
            u=x+X[i];
            v=y+Y[i];



            if(valid(u,v)  && g[u][v]=='1' && visit[u][v]==0)
            {

                    visit[u][v]=1;
                    q.push(u);
                    q.push(v);

            }

        }
    }
}



int main()
{
	int i,j,a,b,count,t=1;
	while ( scanf("%d",&n) == 1)
	{
	    count=0;
		memset(g, 0, sizeof(g) );
		memset(visit,0,sizeof(visit));
		for ( i = 0; i < n; i ++ )

		{
		    scanf("%s",&g[i]);

		}

		for(i=0;i<n;i++)
		{
		    for(j=0;j<n;j++)
		    {
		        if(g[i][j]=='1' && visit[i][j]==0)
		        {
		            bfs(i,j);
		            count++;
		        }

		    }
		}
		printf("Image number %d contains %d war eagles.\n",t++,count);
	}
	return 0;
}
