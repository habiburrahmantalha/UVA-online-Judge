//Problem Type :
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
int n;
bool g[210][210],visit[210],invite[210],impossible;
int bfs(int u,bool f)
{
    int v,c=0;
    queue<int>q;
    impossible=false;
    q.push(u);
    visit[u]=true;
    invite[u]=f;
    if(f)
    c=1;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(v=1;v<=n;v++)
        {
            if(g[u][v] && !visit[v])
            {
                visit[v]=1;
                q.push(v);
                if(invite[u])
                    invite[v]=false;
                else
                {
                    invite[v]=true;
                    c++;
                }

            }
            else if(g[u][v] && visit[v] && u!=v)
            {
                if(invite[u]==invite[v])
                {
                    impossible=true;

                }

            }
        }
    }
    if(impossible)
    return 0;
    else
    return c;
}

int main()
{
    int m,tc,i,j,res;
    vector<int>v1,v2;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(g,0,sizeof(g));
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&j);
                g[i][j]=g[j][i]=true;
            }
        }

        memset(visit,0,sizeof(visit));
        memset(invite,false,sizeof(invite));
        for(i=1;i<=n;i++)
        {
            if(!visit[i])
                v1.push_back(bfs(i,true));
        }

        memset(visit,0,sizeof(visit));
        memset(invite,false,sizeof(invite));
        for(i=1;i<=n;i++)
        {
            if(!visit[i])
                v2.push_back(bfs(i,false));
        }
        res=0;
        for(i=0;i<v1.size();i++)
        //cout<<v1[i]<<"*"<<v2[i]<<endl;
        res+=max(v1[i],v2[i]);

        printf("%d\n",res);

        v1.clear(),v2.clear();

    }
    return 0;
}
