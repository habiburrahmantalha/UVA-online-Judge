#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair< int, int >
#define MAX 1000001

// ( w (u, v) ) format
vector< pair< int, edge > > GRAPH;
int parent[MAX],N, E,mx,mst;

int findset(int x, int *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

void kruskal()
{
    int i, pu, pv;
    mst=mx=0;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    for(i=0; i<E; i++)
    {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv)
        {
            //MST.push_back(GRAPH[i]); // add to tree
            if(mx<GRAPH[i].first)
                mx=GRAPH[i].first;
            parent[pu] = parent[pv]; // link
            mst++;
            if(mst==N-1)
                break;
        }
    }
}

void reset()
{
    // reset appropriate variables here
    // like MST.clear(), GRAPH.clear(); etc etc.
    for(int i=0; i<N; i++) parent[i] = i;
}



int main()
{
    int i, u, v, w;

    while(scanf("%d %d", &N, &E))
    {
        if(N==0 && E==0)
            break;
        reset();
        for(i=0; i<E; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            GRAPH.push_back(pair< int, edge >(w, edge(u, v)));
        }
        kruskal(); // runs kruskal and construct MST vector

        if(mst!=N-1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",mx);
        GRAPH.clear();
    }

    return 0;
}
