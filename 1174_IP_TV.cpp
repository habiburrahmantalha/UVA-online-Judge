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

int N,M,mst;

struct E
{
    int u,v,c;
    E(int u, int v, int c) : u(u), v(v), c(c) {}
    bool operator < (const E &that) const { return c < that.c; }
};
vector<E>edge;
int p[2010];
map<string,int>mp;

void reset()
{
    for(int i=0;i<=N;i++)
    p[i]=i;
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
int main()
{
    int tc,i,c,n;
    string a,b;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&N,&M);
        n=1;
        for(i=0;i<M;i++)
        {
            cin>>a>>b>>c;
            if(!mp[a])
            mp[a]=n++;
            if(!mp[b])
            mp[b]=n++;

            edge.push_back(E(mp[a],mp[b],c));
        }
        sort(edge.begin(),edge.end());

        krushkal();
        printf("%d\n",mst);

        if(tc)
        printf("\n");

        edge.clear();
        mp.clear();

    }
    return 0;
}
