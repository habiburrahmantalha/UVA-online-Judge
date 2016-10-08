//Problem Type : LCA,bfs
//Time :
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

bool visit[5010];
int l[5010],n,pi[5010];
vector<int>g[5010];

void bfs(int u)
{
    queue<int>q;
    memset(visit,0,sizeof(visit));
    int i,v;

    l[u]=0;
    pi[u]=u;
    visit[u]=1;
    q.push(u);

    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(visit[v]==0)
            {
                l[v]=l[u]+1;
                visit[v]=1;
                pi[v]=u;
                q.push(v);
            }
        }
    }
}
bool FIND(int a,vector<int> x,vector<int> y)
{
    int i;
    for(i=0;i<x.size();i++)
    if(x[i]==a)
    return true;
    for(i=0;i<y.size();i++)
    if(y[i]==a)
    return true;

    return false;
}
int main()
{
    int i,a,b,q,ca,cb;
    while(scanf("%d",&n) && n)
    {
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bfs(1);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&a,&b);


            vector<int>temp,path;
            while(a!=b)
            {
                if(l[a]==l[b])
                {
                    path.push_back(a);
                    temp.push_back(b);
                    a=pi[a];
                    b=pi[b];
                }
                else if(l[a]>l[b])
                {
                    path.push_back(a);
                    a=pi[a];

                }
                else
                {
                    temp.push_back(b);
                    b=pi[b];

                }
            }
            if(!FIND(a,path,temp))
            path.push_back(a);
            for(i=temp.size()-1;i>=0;i--)
            path.push_back(temp[i]);

            //for(i=0;i<path.size();i++)
            //cout<<path[i]<<" ";
            //cout<<endl;

            if(path.size()&1)
            printf("The fleas meet at %d.\n",path[(path.size()-1)/2]);
            else
            {
                a=min(path[(path.size()/2)-1],path[path.size()/2]);
                b=max(path[(path.size()/2)-1],path[path.size()/2]);
                printf("The fleas jump forever between %d and %d.\n",a,b);
            }

            for(i=0;i<=n;i++)
            g[i].clear();
        }
    }
    return 0;
}
