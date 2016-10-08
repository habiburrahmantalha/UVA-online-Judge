#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int n,v[10010],h[10010],c;
vector<int> g[10010];
void dfs(int x)
{
    c++;
    int i;
    v[x]=1;
    for(i=0;i<g[x].size();i++)
    {
        if(v[g[x][i]]==0)
        {
            dfs(g[x][i]);
        }
    }
}

int main()
{
    int tc,m,l,a,b,i;
    scanf("%d",&tc);
    while(tc--)
    {

        memset(v,0,sizeof(v));
        memset(h,0,sizeof(h));
        scanf("%d %d %d",&n,&m,&l);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
        }
        c=0;
        for(i=0;i<l;i++)
        {
            scanf("%d",&a);
            h[a]=1;
            if(v[a]==0)
            dfs(a);

        }


        printf("%d\n",c);
        for(i=0;i<=n;i++)
        g[i].clear();
    }
    return 0;
}
