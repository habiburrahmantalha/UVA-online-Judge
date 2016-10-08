//Problem Type :    Articulation point
//Time :    0.016
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
#include<sstream>
using namespace std;
#define PI 2 * acos (0.0)

bool G[110][110],A[110];
int L[110],V[110],P[110],N;
int n,root,child;

void dfs(int u)
{
    L[u]=V[u]=N++;
    for(int v=1;v<=n;v++)
    {
        if(G[u][v])
        {
            if(!V[v])
            {
                P[v]=u;
                dfs(v);
                if(u==root)
                    child++;
                if(L[v]>=V[u])
                    A[u]=true;
                L[u]=min(L[u],L[v]);
            }
            else if(v!=P[u])
                L[u]=min(L[u],V[v]);
        }
    }
}

int main()
{
    int i,a,b,artipoint;
    char ch;
    while(scanf("%d",&n) && n)
    {
        memset(G,false,sizeof(G));

        while(scanf("%d",&a) && a)
        {

            while(1)
            {
                scanf("%d%c",&b,&ch);

                G[a][b]=G[b][a]=true;

                if(ch==10)
                break;
            }
        }
        memset(V,0,sizeof(V));
        memset(L,0,sizeof(L));
        memset(A,false,sizeof(A));
        N=1;

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
        artipoint=0;
        for(i=1;i<=n;i++)
            if(A[i])
                artipoint++;
        printf("%d\n",artipoint);
    }
    return 0;
}
