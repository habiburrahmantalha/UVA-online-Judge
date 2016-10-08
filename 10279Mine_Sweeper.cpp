#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

int n;

char g[11][11],h[11][11],p[11][11];

int X[]={-1,-1,-1,0,0,1,1,1};
int Y[]={-1,0,1,-1,1,-1,0,1};

bool valid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n)
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
	int i,j,k,l,tc,u,v;
	bool f=false;
	//scanf("%d",&tc);
	//while (tc--)
	{
	    scanf("%d",&n);
	    if(f==true)
	    printf("\n");

		memset(g, 0, sizeof(g) );
		memset(h, 0, sizeof(h) );
		memset(p,'.', sizeof(p) );

		for ( i = 0; i < n; i ++ )
		    scanf("%s",g[i]);
        for ( i = 0; i < n; i ++ )
		    scanf("%s",h[i]);

		for(i=0;i<n;i++)
		{
		    for(j=0;j<n;j++)
		    {
		        if(h[i][j]=='x' && g[i][j]=='*')
                {
                    for(k=0;k<n;k++)
                        for(l=0;l<n;l++)
                        if(g[k][l]=='*')
                            p[k][l]='*';


                }
		        else if(h[i][j]=='x' && p[i][j]=='.' )
		        p[i][j]=bfs(i,j)+'0';

		    }
		}

		for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            printf("%c",p[i][j]);
            printf("\n");
        }
        f=true;

	}
	return 0;
}
