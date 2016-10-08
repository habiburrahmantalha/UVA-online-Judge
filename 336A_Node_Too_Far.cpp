#include<cstdio>
#include<cstring>
#include<set>
#include<queue>

using namespace std;

set<int> node;
int g[]
int main()
{
    int a,b,i,n,ans,tc=1;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            g[a]][b]=1;
            node.insert(a);
            node.insert(b);
        }
        while(scanf("%d %d",&a,&b) && a && b)
        {
            ans=bfs(a,b);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tc++,ans,a,b);
        }
    }
    return 0;
}
