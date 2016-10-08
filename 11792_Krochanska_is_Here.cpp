#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

vector<int>g[10000+5];
int cost[10000+5],n,f[10000+5];

int bfs(int s)
{
    memset(cost,0x7F,sizeof(cost));

    queue<int>q;
    int u,v,res=0,i;

    q.push(s);
    cost[s]=0;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(v=0;v<g[u].size();v++)
        {
            if(cost[g[u][v]]==2139062143)
            {
                cost[g[u][v]]=cost[u]+1;
                q.push(g[u][v]);
            }
        }
    }
    for(i=1;i<=n;i++)
        if(f[i]>=2)
        res+=cost[i];
    //printf("%d %d\n",s,res);
    return res;
}
int main()
{
    int tc,line,i,j,x,y,c,min,res;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(f,0,sizeof(f));
        scanf("%d %d",&n,&line);
        for(i=0;i<=n;i++)
            g[i].clear();

        for(i=0;i<line;i++)
        {
            scanf("%d",&x);
            f[x]++;
            while(scanf("%d",&y) && y)
            {
                f[y]++;
                g[x].push_back(y);
                g[y].push_back(x);
                x=y;
            }
        }
        min=2139062143;
        for(i=1;i<=n;i++)
        {
            if(f[i]>=2)
                c=bfs(i);
            if(min>c)
            {
                min=c;
                res=i;
            }
        }
        printf("Krochanska is in: %d\n",res);

    }
    return 0;
}
