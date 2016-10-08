#include<stdio.h>
#include<string>
#include<queue>
#include<string.h>
using namespace std;
int n,m,g[1001][1001],d[1001];


void bfs()
{
    queue<int>q;
    int u,v;
    q.push(0);
    memset(d,-1,sizeof(d));
    d[0]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(v=0;v<n;v++)
        {
            if(g[u][v] && d[v]==-1)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int tc,i,a,b,c;
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)
            printf("\n");
        memset(g,0,sizeof(g));
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a][b]=g[b][a]=1;
        }
        bfs();
        for(i=1;i<n;i++)
        {

            printf("%d\n",d[i]);
        }
        f=true;
    }
    return 0;
}
