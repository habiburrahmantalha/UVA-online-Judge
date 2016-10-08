#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int>g[110];
int mx,s,e;
int d[110];

void backtracking(int x,int k)
{
    if(d[x]>k)
    return;
    d[x]=k;
    int i;
    for(i=0;i<g[x].size();i++)
            backtracking(g[x][i],k+1);

}
int main()
{
    int s,a,b,i,n,t=1;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&s);
        while(scanf("%d %d",&a,&b) && a && b)
            g[a].push_back(b);

        mx=0;
        memset(d,0,sizeof(d));
        backtracking(s,0);
        for(i=1;i<=n;i++)
        {
            if(mx<d[i])
            {
                mx=d[i];
                e=i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",t++,s,mx,e);
        for(i=1;i<=n;i++)
        g[i].clear();
    }
    return 0;
}
