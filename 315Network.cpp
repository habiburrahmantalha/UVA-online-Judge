#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

int visit[101],g[101][101],n;

void bfs(int s)
{
    int u,v;
    queue<int>q;
    q.push(s);

    visit[s]=1;
    while(!q.empty())
    {
        u=q.front(); q.pop();

        for(v=0;v<n;v++)
        {
            if(g[u][v] && visit[v]==0)
            {
                visit[v]=1;
                q.push(v);
            }
        }
    }
}


bool disconnected()
{
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0)
        return true;
    }
    return false;
}

void artipoint()
{
    int count=0,i;
    for(i=0;i<n;i++)
    {
        memset(visit,0,sizeof(visit));
        visit[i]=1;
        bfs((i+1)%n);
        if(disconnected())
        count++;

    }
    printf("%d\n",count);
}

int main()
{
    int a,b;
    char ch;
    while(scanf("%d",&n) && n)
    {
        memset(g, 0,sizeof(g));

        while(scanf("%d",&a) && a)
        {
            a--;
            while(1)
            {
                scanf("%d%c",&b,&ch);
                b--;
                g[a][b]=g[b][a]=1;

                if(ch==10)
                break;
            }
        }
        artipoint();
    }
    return 0;
}
