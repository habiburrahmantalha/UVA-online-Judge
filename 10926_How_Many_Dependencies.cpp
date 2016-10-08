#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
using namespace std;

vector<int>g[110];
int d[110],cnt;
bool v[110];

void dfs(int u)
{
    v[u]=true;
    cnt++;
    for(int i=0;i<g[u].size();i++)
        dfs(g[u][i]);



}
int main()
{
    int i,j,m,x,mn,k,n;
    while(scanf("%d",&n) && n)
    {

        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                g[i].push_back(x);
            }
        }

        for(i=1;i<=n;i++)
        {
            cnt=0;
            memset(v,false,sizeof(v));
            dfs(i);
            d[i]=cnt;
        }
        //for(i=1;i<=n;i++)
        //printf("%d ",d[i].size());

        mn=-1;
        for(i=1;i<=n;i++)
        {
            if(mn<d[i])
            {
                mn=d[i];
                k=i;
            }
        }
        printf("%d\n",k);

        for(i=0;i<=n;i++)
        {
            g[i].clear();

        }
    }
    return 0;
}
