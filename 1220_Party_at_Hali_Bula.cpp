//Problem Type : BFS,Tree;
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

bool g[210][210],visit[210];
int d[210],f[210],n;

void bfs(int u)
{
    queue<int>q;
    int v;
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));
    memset(visit,false,sizeof(visit));
    q.push(u);
    d[u]=0;
    f[0]++;
    visit[u]=true;

    while(!q.empty())
    {
        u=q.front();q.pop();
        for(v=1;v<=n;v++)
        {
            if(g[u][v] && !visit[v])
            {
                d[v]=d[u]+1;
                f[d[v]]++;
                visit[v]=true;
                q.push(v);
            }
        }
    }

}

int main()
{
    char a[110],b[110];
    int i,j,odd,even;
    map<string,int>mp;
    while(scanf("%d",&n) && n)
    {
        scanf("%s",a);
        mp[a]=1;
        j=2;
        memset(g,false,sizeof(g));
        for(i=1;i<n;i++)
        {
            scanf("%s %s",a,b);
            if(!mp[a])
            mp[a]=j++;
            if(!mp[b])
            mp[b]=j++;

            g[mp[b]][mp[a]]=true;

        }
        bfs(1);
        even=0;
        for(i=0;i<=n;i+=2)
        even+=f[i];
        odd=0;
        for(i=1;i<=n;i+=2)
        odd+=f[i];

        int mx=max(odd,even);
        printf("%d ",mx);
        if(odd==even)
        printf("No\n");
        else
        printf("Yes\n");

        mp.clear();
    }

    return 0;
}
