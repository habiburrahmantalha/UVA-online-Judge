#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)
#define LL long long
int n,m;
vector<int>g[510];
vector<LL>cost[510];
int visit[510],cnt;
LL mx;

void dfs(int s)
{
    visit[s]=1;
    cnt++;
    for(int i=0;i<g[s].size();i++)
    {
        if(visit[g[s][i]]==0 && cost[s][i]==mx)
            dfs(g[s][i]);
    }
}
int main()
{
    int i,a,b,city,j;
    LL c;
    while(scanf("%d %d",&n,&m) && n+m)
    {
        mx=-(1<<31);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %lld",&a,&b,&c);
            g[a].push_back(b);
            g[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);

            mx=max(c,mx);
        }

        city=0;
        memset(visit,0,sizeof(visit));
        for(i=1;i<=n;i++)
        {
            if(visit[i]==0)
            {
                //memset(visit,0,sizeof(visit));
                cnt=0;
                dfs(i);
                city=max(cnt,city);

            }
        }
        printf("%d\n",city);
        for(i=0;i<=n;i++)
        {
            g[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
