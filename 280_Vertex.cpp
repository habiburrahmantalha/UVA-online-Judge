#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

int g[101][101],visit[101],n;
void bfs(int s)
{
    int u,v,i;
    queue<int> q;

    q.push(s);

    while(!q.empty())
    {
        u=q.front();q.pop();
        for(v=1;v<=n;v++)
        {
            if(g[u][v] && visit[v]==0)
            {
                visit[v]=1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int m,x,y,i,j,k,v,in,count,out[101];
    while(scanf("%d",&n) && n)
    {
        memset(g,0,sizeof(g));
        while(scanf("%d",&m) && m)
        {
            while(scanf("%d",&x) && x)
            {
                g[m][x]=1;
            }
        }
        scanf("%d",&y);
        for(k=0;k<y;k++)
        {
            scanf("%d",&v);
            memset(visit,0,sizeof(visit));
            bfs(v);

            in=0;
            count=0;
            for(i=1;i<=n;i++)
            {
                if(visit[i]==0)
                {
                    count++;
                    out[in++]=i;
                }
            }
            printf("%d",count);
            if(count!=0)
            {
                for(j=0;j<in-1;j++)
                    printf(" %d",out[j]);
                printf(" %d\n",out[j]);
            }
            else
                printf("\n");
        }
    }
    return 0;
}
