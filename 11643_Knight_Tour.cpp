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

struct edge
{
    int a,b,c;
    edge(){}
    edge(int a,int b,int c):a(a),b(b),c(c){};
    bool operator < (const edge &p)const{return c<p.c;}
};

vector<edge>G;
int D[1010][1010],N,K,P[100010];

void reset();
{
    for(i=0;i<G.size();i++)
    P[i]=i;
}
int find(int x)
{
    if(p[x]!=x)
        p[x]=find(p[x]);
    return p[x];
}
void krushkal()
{
    int i,u,v,e=0;
    mst=0;
    reset();
    for(i=0;i<M;i++)
    {
        u=find(edge[i].u);
        v=find(edge[i].v);
        if(u!=v)
        {
            p[u]=p[v];
            mst+=edge[i].c;
            e++;
            if(e==N-1)
            return;
        }
    }
}
void BFS(int u,int v)
{
    queue<int>q;
    memset(D,-1,sizeof(D));

    q.push(u);
    q.push(v);
    D[u][v]=0;

    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();

        for(i=0;i<8;i++)
        {
            x=u+X[i];
            y=v+Y[i];
            if(valid(x,y) && D[x][y]==-1)
            {
                D[x][y]=D[u][v]+1;
                q.push(x);
                q.push(y);
            }
        }
    }

}
void make_graph()
{
    for(i=0;i<K;i++)
    {
        BFS(x[i],y[i]);

        for(j=i+1;j<K;j++)
            if(D[x[j]][y[j]])
                G(edge(i,j,D[x[j]][y[j]]));
    }
    sort(G.begin(),G.end());
}
int main()
{
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&N,&K);
        for(i=0;i<K;i++)
            scanf("%d %d",&x[i],&y[i]);
        make_graph();

    }
    return 0;
}
