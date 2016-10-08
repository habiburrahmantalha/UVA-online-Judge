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

int N,K,M;
bool G[110][110];
int D[110];

void BFS()
{
    queue<int> q;
    int u,v;

    q.push(0);

    D[0]=1;

    while(!q.empty())
    {
        u=q.front();q.pop();

        for(v=0;v<N;v++)
        {
            if(G[u][v] && u!=v && D[u]+1<=20)
            {
                D[v]=D[u]+1;
                q.push(v);

                if(D[N-1]>=K)
                return;

            }
        }
    }
}

int main()
{
    int i,a,b;
    while(scanf("%d %d %d",&N,&M,&K) && N+M+K)
    {
        memset(G,false,sizeof(G));
        memset(D,false,sizeof(D));
        for(i=0;i<M;i++)
        {
            scanf("%d %d",&a,&b);
            G[a][b]=true;
        }


        BFS();
        if(D[N-1]>=K)
        printf("%d\n",D[N-1]);
        else
        printf("LOSER\n");

    }
    return 0;
}
