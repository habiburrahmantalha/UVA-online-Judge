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
vector<int>g[30010];
int visit[30010],n,m,cnt;

void dfs(int s)
{
    visit[s]=1;
    cnt++;
    for(int i=0;i<g[s].size();i++)
    {
        if(visit[g[s][i]]==0)
            dfs(g[s][i]);
    }
}


int main()
{
    int i,j,k,a,b,x[30010];
    while(scanf("%d %d",&n,&m) && n+m)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d",&k);
            for(j=0;j<k;j++)
                scanf("%d",&x[j]);
            for(a=0;a<k;a++)
            {
                for(b=a+1;b<k;b++)
                {
                    g[x[a]].push_back(x[b]);
                    g[x[b]].push_back(x[a]);
                }
            }
        }
        cnt=0;
        memset(visit,0,sizeof(visit));
        dfs(0);
        printf("%d\n",cnt);
        for(i=0;i<=n;i++)
        g[i].clear();
    }
    return 0;
}
