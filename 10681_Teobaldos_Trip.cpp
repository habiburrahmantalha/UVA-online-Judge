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

int S,T,C,E;
bool G[110][110];
bool D[110][110];

void BFS()
{
    queue<int> q;
    int u,v,c,t;

    q.push(S);
    q.push(S);
    q.push(0);
    D[S][0]=true;

    while(!q.empty())
    {
        u=q.front();q.pop();
        c=q.front();q.pop();
        t=q.front();q.pop();

        for(v=1;v<=C;v++)
        {
            if(G[c][v] && u!=v && t+1<=T && !D[v][t])
            {
                D[v][t+1]=true;
                q.push(c);
                q.push(v);
                q.push(t+1);
                if(D[E][T])
                return;

            }
        }
    }
}

int main()
{
    int i,a,b,L;
    while(scanf("%d %d",&C,&L) && C+L)
    {
        memset(G,false,sizeof(G));
        memset(D,false,sizeof(D));
        for(i=0;i<L;i++)
        {
            scanf("%d %d",&a,&b);
            G[a][b]=G[b][a]=true;
        }
        scanf("%d %d %d",&S,&E,&T);

        BFS();
        if(D[E][T])
        printf("Yes, Teobaldo can travel.\n");
        else
        printf("No, Teobaldo can not travel.\n");

    }
    return 0;
}
