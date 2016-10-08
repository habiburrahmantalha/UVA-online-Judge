#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

int n,m;
char g[101][101],h[101][101];

int X[]={-1,-1,-1,0,0,1,1,1};
int Y[]={-1,0,1,-1,1,-1,0,1};

bool valid(int x,int y)
{
    if(x>=0 && x<m && y>=0 && y<n)
    return true;
    else
    return false;
}

int bfs(int x,int y)
{
    int i,u,v,count=0;


        for(i=0;i<8;i++)
        {

            u=x+X[i];
            v=y+Y[i];

            if(valid(u,v)  && g[u][v]=='*')
            {
                    count++;
            }

        }

    return count;
}



int main()
{
	int i,j,tc=1;
	bool f=false;
	while ( scanf("%d %d",&m, &n) == 2 && n && m)
	{
	    if(f==true)
	    printf("\n");
		memset(g, 0, sizeof(g) );
		memset(h, 0, sizeof(h) );

		for ( i = 0; i < m; i ++ )
		    scanf("%s",g[i]);

		for(i=0;i<m;i++)
		{
		    for(j=0;j<n;j++)
		    {
		        if(g[i][j]=='.')
                    h[i][j]=bfs(i,j)+'0';
		        else
                    h[i][j]=g[i][j];
		    }
		}
		printf("Field #%d:\n",tc++);
		for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            printf("%c",h[i][j]);
            printf("\n");
        }
        f=true;

	}
	return 0;
}
