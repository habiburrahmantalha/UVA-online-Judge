#include<cstdio>
#include<queue>
#include<string.h>

using namespace std;

int n,m;
char g[20][20];
int visit[20][20],d[20][20];
bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
    return false;
    return true;
}


void bfs(int x,int y)
{
    queue < int > q;
    int u, v, count=0 ;
    char ch;
    memset(visit,0,sizeof(visit));
    memset(d,0,sizeof(d));
    visit[x][y]=1;
    d[x][y]=1;
    q.push(x);
    q.push(y);

    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();

        u=x;
        v=y;
        ch=g[x][y];
        if(ch=='N')
        u--;
        else if(ch=='S')
        u++;
        else if(ch=='E')
        v++;
        else if(ch=='W')
        v--;

        count++;

        if(valid(u,v) )
        {
            if(visit[u][v]==0)
            {
                q.push(u);
                q.push(v);
                visit[u][v]=1;
                d[u][v]=d[x][y]+1;
            }
            else if(visit[u][v])
            {
                printf("%d step(s) before a loop of %d step(s)\n",d[u][v]-1,count-d[u][v]+1);
                return;
            }

        }
        else
        {
            printf("%d step(s) to exit\n",count);
            return;
        }
    }

}

int main()
{
    int s,i;
    while(scanf("%d %d %d",&n,&m,&s) && n && m&& s)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",g[i]);

        }
        bfs(0,s-1);
    }
}
