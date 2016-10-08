#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>g[55];
int f[10010],u[55];
int n,c;

void check()
{
    int i,j;
    c=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<g[i].size();j++)
        if(f[g[i][j]]==1)
        {
            c++;
            u[i]++;
        }
    }
}
int main()
{
    int tc,t=1,i,j,m,x;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(f,0,sizeof(f));
        memset(u,0,sizeof(u));

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                if(g[i].end()==(find(g[i].begin(),g[i].end(),x)))
                {
                    f[x]++;
                    g[i].push_back(x);
                }
            }
        }
        check();
        printf("Case %d:",t++);
        if(c==0)
        for(i=0;i<n;i++)
        printf(" %.6lf%%",100*(double)u[i]);
        else
        for(i=0;i<n;i++)
        printf(" %.6lf%%",100*(double)u[i]/c);

        printf("\n");
        for(i=0;i<=n;i++)
        g[i].clear();
    }
    return 0;
}
