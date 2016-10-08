//Problem Type :    Bicoloring
//Time :    0.020
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

bool g[310][310],visit[310],color[310];

int n;

bool bicolor(int u)
{
    queue<int>q;
    int v;

    q.push(u);
    visit[u]=true;
    color[u]=true;
    while(!q.empty())
    {
        u=q.front();q.pop();

        for(v=1;v<=n;v++)
        {
            if(g[u][v] && !visit[v])
            {
                visit[v]=true;
                if(!color[u])
                    color[v]=true;
                q.push(v);
            }
            else if(g[u][v] && visit[v] && u!=v)
            {
                if(color[u]==color[v])
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    bool decomposed_into_claws;
    int a,b,i;
    while(scanf("%d",&n) && n)
    {
        memset(g,false,sizeof(g));
        memset(visit,false,sizeof(visit));
        memset(color,false,sizeof(color));

        while(scanf("%d %d",&a,&b) && a+b)
        {
            g[a][b]=true;
            g[b][a]=true;
        }
        decomposed_into_claws=true;
        for(i=1;i<=n;i++)
            if(!visit[i])
                if(!bicolor(i))
                {
                    decomposed_into_claws=false;
                    break;
                }
        if(decomposed_into_claws)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
