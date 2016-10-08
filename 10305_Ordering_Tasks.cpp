#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

vector<int>g[110];
vector<int>res;
int n;
int visit[110];

void top_sort(int x)
{
    int i;
    visit[x]=1;
    for(i=0;i<g[x].size();i++)
    {
        if(visit[g[x][i]]==0)
        top_sort(g[x][i]);
    }
    res.push_back(x);
}

int main()
{
    int m,i,a,b;
    while(scanf("%d %d",&n,&m) && n+m)
    {

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
        }
        memset(visit,0,sizeof(visit));
        for(i=1;i<=n;i++)
        if(visit[i]==0)
        top_sort(i);

        for(i=res.size()-1;i>=1;i--)
        printf("%d ",res[i]);
        printf("%d\n",res[i]);

        for(i=0;i<=n;i++)
        g[i].clear();
        res.clear();
    }
    return 0;
}
