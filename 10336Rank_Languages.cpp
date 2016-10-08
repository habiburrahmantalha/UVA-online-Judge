#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include<algorithm>
using namespace std;

int n,m,visit[1001][1001];
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
char g[1001][1001];

bool valid(int x,int y)
{
    if(x<0 || x>n || y<0 || y>m)
    return false;
    return true;
}
void bfs(char ch, int x,int y )
{
	queue <int> q;

	int u,v,i;

	visit[x][y] = 1;

	q.push(x);
	q.push(y);

	while ( !q.empty() )
	{

		u = q.front();
		q.pop();
		v = q.front();
		q.pop();

		for ( i = 0; i < 4; i ++ )
		{
		    x=u+X[i];
		    y=v+Y[i];
			if ( valid(x,y) && g[x][y] == ch && visit[x][y]==0 )
			{
				visit[x][y] = 1;
				q.push(x);
				q.push(y);
			}
		}
	}
}



int main()
{
	int tc,i,j,k,W[26];
	char x[]={"abcdefghijklmnopqrstuvwxyz"};
	scanf("%d",&tc);
	for(k=1;k<=tc;k++)
	{

	    scanf("%d %d",&n, &m);
		memset(g, 0, sizeof(g) );
		memset(W, 0, sizeof(W) );
		char x[]={"abcdefghijklmnopqrstuvwxyz"};
		memset( visit, 0, sizeof(visit));
		for ( i = 0; i < n; i ++ )
		{
			scanf("%s",g[i]);
		}
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
		    if(visit[i][j]==0)
		    {
		        bfs(g[i][j],i,j);
		        W[g[i][j]-'a']++;
		    }
		}
		for(int i=0;i<26;i++)
        for(int j=0;j<26-1;j++)
        {
            if(W[j+1]>W[j])
            {
                swap(W[j+1],W[j]);
                swap(x[j+1],x[j]);
            }
        }
		printf("World #%d\n",k);
		for(i=0;i<26;i++)
		if(W[i])
		printf("%c: %d\n",x[i],W[i]);
	}
	return 0;
}
