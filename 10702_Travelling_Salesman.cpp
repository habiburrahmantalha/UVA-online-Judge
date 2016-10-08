//Problem Type :    DP,TSP
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

int C;
int D[110][1010],G[110][110];
bool V[110][1010],E[110];
int travel(int u,int n)
{
    int v,MX=0;
    if(!V[u][n])
    {
        V[u][n]=true;
        if(n==1)
        {
            for(v=1;v<=C;v++)
                if(E[v])
                    MX=max(MX,G[u][v]);
            return D[u][n]=MX;
        }
        else
        {
            for(v=1;v<=C;v++)
                MX=max(MX,G[u][v]+travel(v,n-1));
            return D[u][n]=MX;

        }
    }
    else
        return D[u][n];
}

int main()
{
    int S,e,T,i,j,x;
    while(scanf("%d %d %d %d",&C,&S,&e,&T) && C+S+e+T)
    {
        memset(G,0,sizeof(G));
        memset(D,0,sizeof(D));
        memset(E,false,sizeof(E));
        memset(V,false,sizeof(V));

        for(i=1;i<=C;i++)
        {
            for(j=1;j<=C;j++)
            {
                scanf("%d",&x);
                G[i][j]=x;
            }
        }
        for(i=0;i<e;i++)
        {
            scanf("%d",&x);
            E[x]=true;
        }
        printf("%d\n",travel(S,T));
    }
    return 0;
}
