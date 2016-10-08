#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

vector<int> g[2510];
int n;
int visit[2510];
void bfs(int s)
{
    queue<int>q;
    int u,v,i,c,d,mx_b,mx_d,x,y;
    memset(visit,0,sizeof(visit));
    visit[s]=1;
    q.push(s);
    d=mx_b=c=0;
    y=1;
    while(!q.empty())
    {
        u=q.front();q.pop();

        for(v=0;v<g[u].size();v++)
        {
            if(visit[g[u][v]]==0)
            {
                visit[g[u][v]]=1;
                q.push(g[u][v]);
                c++;
            }
        }
        //printf("%d*",y);
        y--;
        if(y==0)
        {
            d++;
            if(mx_b<c)
            {
                mx_b=c;
                mx_d=d;
            }
        }
        if(y==0)
        {
            y=c;
            c=0;
        }


    }
    if(mx_b==0)
        printf("0\n");
    else
        printf("%d %d\n",mx_b,mx_d);
}

int main()
{
    int i,j,x,m,q;
    while(scanf("%d",&n)==1)
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
