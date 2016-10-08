#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

vector<int> g[2510];
int n;
int visit[2510],d[2510];
void bfs(int s)
{
    queue<int>q;
    int u,v,i,x,y;
    memset(visit,0,sizeof(visit));
    memset(d,0,sizeof(d));
    visit[s]=1;
    d[s]=0;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();q.pop();

        for(v=0;v<g[u].size();v++)
        {
            if(visit[g[u][v]]==0)
            {
                visit[g[u][v]]=1;
                d[g[u][v]]=d[u]+1;
                q.push(g[u][v]);

            }
        }


    }
    int f[2510];
    memset(f,0,sizeof(f));
    for(i=0;i<2500;i++)
    if(visit[i])
        f[d[i]]++;

    int mx=0,day=0;
    for(i=0;i<2500;i++)
    if(f[i]>mx)
    {
        mx=f[i];
        day=i;
    }

    if(g[s].size()==0)
        printf("0\n");
    else
        printf("%d %d\n",mx,day);
}

int main()
{
    int i,j,x,m,q;

    scanf("%d",&n);
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                g[i].push_back(x);
            }
        }
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d",&x);
            bfs(x);
        }
        for(i=0;i<n;i++)
            g[i].clear();
    }
    return 0;
}
