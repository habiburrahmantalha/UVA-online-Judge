#include<set>
#include<vector>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

vector<int> vs[30001];
int n,m,visit[30001];

int bfs(int s)
{
    queue<int> q;
    int u,v,c=1;
    visit[s]=1;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(v=0;v<vs[u].size();v++)
        {
            if(vs[u][v] && visit[vs[u][v]]==0)
            {
                c++;
                visit[vs[u][v]]=1;
                q.push(vs[u][v]);
            }
        }
    }
    return c;
}
int main()
{
    int tc,a,b,i,mx;
    scanf("%d",&tc);

    while(tc--)
    {
        memset(visit,0,sizeof(visit));
        mx=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            vs[a].push_back(b);
            vs[b].push_back(a);
        }
        for(i=1;i<=n;i++)
        {
            mx=max(mx,bfs(i));
        }
        printf("%d\n",mx);
        for(i=0;i<30001;i++)
        vs[i].clear();
    }
    return 0;
}
