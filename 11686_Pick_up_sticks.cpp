#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

vector<int>g[100010];
int res[100010],in;
int visit[100010],n;
bool f;
void top_sort(int x)
{
    int i;
    visit[x]=1;

    for(i=0;i<g[x].size();i++)
    {
        if(visit[g[x][i]]==1)
        {
            f=false;
            return;
        }
        if(visit[g[x][i]]==0 && f)
        top_sort(g[x][i]);

    }
    visit[x]=2;
    res[in--]=x;
}
int main()
{
    int a,b,i,m;
    while(scanf("%d %d",&n,&m) && n+m)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
        }
        f=true;
        memset(visit,0,sizeof(visit));
        in=n-1;
        for(i=1;i<=n;i++)
        if(visit[i]==0)
        {
            top_sort(i);
            if(!f)
            break;
        }

        if(f)
        for(i=0;i<n;i++)
        printf("%d\n",res[i]);
        else
        printf("IMPOSSIBLE\n");

        for(i=0;i<=n;i++)
        g[i].clear();

    }
    return 0;
}
