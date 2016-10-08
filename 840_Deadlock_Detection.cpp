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
#include<stack>
using namespace std;
#define PI 2 * acos (0.0)

bool G[130][130],Gr[130][130],V[130],F[130],cycle;
int color[130];
vector<int>D[130];
vector<vector<int> > R;
stack<int>S;
int N,M,E,C;
void DFS(int u)
{
    V[u]=true;
    color[u]=2;
    for(int v=0;v<130;v++)
    {
        if(F[v] && G[u][v] && !V[v] && color[v]==0)
            DFS(v);
        else if(F[v] && G[u][v] && color[v]==2)
            cycle=true;
    }
    S.push(u);
    color[u]=1;
}
void DFSr(int u,int c)
{
    V[u]=false;
    D[c].push_back(u);
    for(int v=0;v<130;v++)
    {
        if(F[v] && Gr[u][v] && V[v])
            DFSr(v,c);
    }

}
int main()
{
    int tc,i,j;
    char a,b;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&N,&M,&E);

        memset(G,false,sizeof(G));
        memset(Gr,false,sizeof(Gr));
        memset(F,false,sizeof(F));
        for(i=0;i<E;i++)
        {
            cin>>a>>b>>b;
            G[a][b]=true;
            Gr[b][a]=true;
            F[a]=F[b]=true;
            //cout<<a<<b<<endl;
        }
        memset(V,false,sizeof(V));
        memset(color,0,sizeof(color));
        cycle=false;
        for(i=0;i<130;i++)
        {
            if(F[i] && !V[i])
                DFS(i);
        }
        C=0;
        while(!S.empty())
        {
            i=S.top();S.pop();
            if(V[i])
            {
                DFSr(i,++C);
                D[C].push_back(i);
                reverse(D[C].begin(),D[C].end());
                R.push_back(D[C]);
            }

        }
        ///*

        if(!cycle)
            printf("NO\n");
        else
        {
            sort(R.begin(),R.end());
            printf("YES\n");
            for(i=0;i<R.size();i++)
            {
                if(R[i].size()<=1)
                continue;
                printf("%c",R[i][0]);

                for(j=1;j<R[i].size();j++)
                    printf("-%c",R[i][j]);

                printf("\n");
            }
        }
        for(i=0;i<=C;i++)
        D[i].clear();
        R.clear();
        //*/
        if(tc)
        printf("\n");
    }
    return 0;
}
