#include<stdio.h>
#include<queue>
#include<string.h>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<sstream>
#include<iostream>
using namespace std;

vector<int> g[310];
int d[310],visit[310],pi[310],n;

void bfs(int s)
{
    queue<int>q;
    memset(visit,0,sizeof(visit));
    memset(pi,0,sizeof(pi));

    int u,v,i;

    q.push(s);

    visit[s]=1;
    pi[s]=s;

    while(!q.empty())
    {
        u=q.front();q.pop();
        for(v=0;v<g[u].size();v++)
        {

            if(g[u][v] && visit[g[u][v]]==0)
            {
                visit[g[u][v]]=1;
                pi[g[u][v]]=u;
                q.push(g[u][v]);
            }
        }
    }
}

void print_path(int s,int e)
{
    if(s==e)
    {
        printf("%d",s);
        return;
    }
    else
    {
        print_path(s,pi[e]);
        printf(" %d",e);
    }
}
int main()
{
    int i,j,x,m,s,e;
    string y;
    char ch;

    int tc;

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<=300;i++)
            g[i].clear();

        for(i=0;i<n;i++)
        {
            scanf("%d-",&x);
            getline(cin,y);
            stringstream ss(y);
            int z;
            while(ss>>z)
            {
                g[x].push_back(z);
                ss>>ch;
           }


        }
        /*
         for(i=1;i<=n;i++)
           {
               printf("%d-",i);
               for(j=0;j<g[i].size();j++)
                printf("%d ",g[i][j]);
               printf("\n");
           }
           */
        printf("-----\n");
        scanf("%d",&m);

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&s,&e);
            bfs(s);

            if(pi[e]==0)
                printf("connection impossible\n");
            else
            {
                print_path(s,e);
                printf("\n");
            }
        }
    }
    return 0;
}
