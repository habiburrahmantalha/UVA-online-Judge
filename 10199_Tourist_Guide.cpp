//Problem Type : Articulation Points
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

bool G[110][110],A[110];
int V[110],L[110],P[110],N;
int n,m,root,child;
char place[110][110];
vector<string>articulation_point;

void dfs(int u)
{
    int v,i;
    L[u]=V[u]=N++;
    for(v=1;v<=n;v++)
    {
        if(G[u][v] && !V[v])
        {
            P[v]=u;
            dfs(v);
            if(u==root)
                child++;
            if(L[v]>=V[u])
                A[u]=true;
            L[u]=min(L[v],L[u]);

        }
        else if(G[u][v] && v!=P[u])
            L[u]=min(V[v],L[u]);
    }
}

int main()
{
    int t=1,i;
    char a[110],b[110];
    map<string,int>M;
    bool f=false;

    while(scanf("%d",&n) && n)
    {
        if(f)
        printf("\n");
        f=true;
        memset(G,false,sizeof(G));
        for(i=1;i<=n;i++)
        {
            scanf("%s",place[i]);
            if(!M[place[i]])
                M[place[i]]=i;
        }
        N=1;
        memset(L,0,sizeof(L));
        memset(V,0,sizeof(V));
        memset(A,false,sizeof(A));
        scanf("%d",&m);

        for(i=0;i<m;i++)
        {
            scanf("%s %s",a,b);
            G[M[a]][M[b]]=G[M[b]][M[a]]=true;
        }
        for(i=1;i<=n;i++)
        {
            if(!V[i])
            {
                root=i;
                child=0;
                dfs(i);
                if(child<=1)
                A[i]=false;

            }
        }

        for(i=1;i<=n;i++)
        if(A[i])articulation_point.push_back(place[i]);
        sort(articulation_point.begin(),articulation_point.end());

        printf("City map #%d: %d camera(s) found\n",t++,articulation_point.size());
        for(i=0;i<articulation_point.size();i++)
        cout<<articulation_point[i]<<endl;

        articulation_point.clear();
        M.clear();
    }
    return 0;
}
