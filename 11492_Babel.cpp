//Problem Type :    Dijkstra
//Time :    0.424
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
#define inf 1139062143
vector<int> G[4010];
vector<int> C[4010];
vector<int> W[4010];

int D[4010][30],n;

int dijkstra(int s,int d)
{
    priority_queue<pair<int,pair<int,int> > >pq;
    int u,v,chu,chv,c,i,j;

    for(i=0;i<=n;i++)
    for(j=0;j<=26;j++)
    D[i][j]=inf;

    for(i=0;i<G[s].size();i++)
    {
        D[s][W[s][i]]=0;
        pq.push(make_pair(0,make_pair(s,-1)));
    }




    while(!pq.empty())
    {
        u=pq.top().second.first;
        chu=pq.top().second.second;
        pq.pop();

        for(i=0;i<G[u].size();i++)
        {
            v=G[u][i];
            chv=W[u][i];
            c=C[u][i];

            if(D[v][chv]>D[u][chu]+c && chu!=chv)
            {
                D[v][chv]=D[u][chu]+c;
                pq.push(make_pair(-D[v][chv],make_pair(v,chv)));
            }
        }
    }
    int mn=inf;
    for(i=0;i<=26;i++)
    mn=min(mn,D[d][i]);

    if(mn==inf)
        return -1;
    else
        return mn;
}

int main()
{
    int m,cost,i,x,y;
    string a,b,c,d,s;
    while(scanf("%d",&m) && m)
    {
        map<string,int>M;


        n=1;
        cin>>s>>d;
        if(!M[s])
            M[s]=n++;
        if(!M[d])
            M[d]=n++;

        for(i=0;i<m;i++)
        {
            cin>>a>>b>>c;

            if(!M[a])
                M[a]=n++;
            if(!M[b])
                M[b]=n++;

            x=M[a];
            y=M[b];

            G[x].push_back(y);
            G[y].push_back(x);

            C[x].push_back(c.size());
            C[y].push_back(c.size());

            W[x].push_back(c[0]-'a');
            W[y].push_back(c[0]-'a');

        }
        cost=dijkstra(M[s],M[d]);
        if(cost==-1)
            printf("impossivel\n");
        else
            printf("%d\n",cost);

        for(i=0;i<=n;i++)
        {
            G[i].clear();
            C[i].clear();
            W[i].clear();
        }
    }
    return 0;
}
