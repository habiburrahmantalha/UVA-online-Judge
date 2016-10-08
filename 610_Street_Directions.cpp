//Problem Type : Bridge,critical link
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

vector<int>G[1010];
int L[1010],V[1010],P[1010],N;
vector<pair<int,int> > E;
int n,m;
bool find_E(int a,int b)
{
    for(int i=0;i<E.size();i++)
        if(E[i].first==a && E[i].second==b)
            return true;
    return false;
}
void dfs(int u)
{
    int i,v;
    L[u]=V[u]=N++;

    for(i=0;i<G[u].size();i++)
    {
        v=G[u][i];

        if(!V[v])
        {
            P[v]=u;


            dfs(v);
            if(L[v]>V[u])
            {
                bool uv=false,vu=false;
                if(find_E(u,v))
                uv=true;
                if(find_E(v,u))
                vu=true;
                if(uv && !vu)
                E.push_back(make_pair(v,u));
                if(vu && !uv)
                E.push_back(make_pair(u,v));

            }
            L[u]=min(L[u],L[v]);
        }
        else if(v!=P[u])
            L[u]=min(L[u],V[v]);

    }
}
int main()
{
    int i,a,b,t=1;
    while(scanf("%d %d",&n,&m) && n && m)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
            E.push_back(make_pair(a,b));
        }
        memset(V,0,sizeof(V));
        memset(L,0,sizeof(L));
        N=1;
        for(i=1;i<=n;i++)
        {
            if(!V[i])
                dfs(i);
        }
        //sort(E.begin(),E.end());
        printf("%d\n\n",t++);
        for(i=0;i<E.size();i++)
        printf("%d %d\n",E[i].first,E[i].second);
        printf("#\n");

        E.clear();
        for(i=0;i<=n;i++)
        G[i].clear();
    }
    return 0;
}
