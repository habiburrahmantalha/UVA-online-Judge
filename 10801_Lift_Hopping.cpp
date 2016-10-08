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

vector<int>g[10],h[110];
int n,k,T[110],d[110][10];

struct lift
{
    int floor,elivator,time;

    bool operator <(const lift &p)const
    {
        return time<p.time;
    }
};

void dijkstra()
{
    priority_queue<lift>pq;
    lift l;
    int INF,mn;
    int u,v,e,f,c,i;
    memset(d,63,sizeof(d));
    INF=d[0][0];

    l.floor=0;
    l.time=0;
    for(i=0;i<h[0].size();i++)
    {
        l.elivator=h[0][i];
        d[0][l.elivator]=0;
        pq.push(l);
    }


    while(!pq.empty())
    {
        l=pq.top();
        pq.pop();

        u=l.floor;
        e=l.elivator;
        //cout<<u<<" "<<e<<endl;

        //same elivator
        for(i=0;i<g[e].size();i++)
        {
            v=g[e][i];

            c=(abs(v-u))*T[e];
            if(d[v][e]>d[u][e]+c)
            {
                d[v][e]=d[u][e]+c;
                l.floor=v;
                l.elivator=e;
                l.time=d[v][e];
                pq.push(l);
            }
        }
        //elivator change
        for(i=0;i<h[u].size();i++)
        {
            f=h[u][i];
            c=60;
            if(d[u][f]>d[u][e]+c)
            {
                d[u][f]=d[u][e]+c;
                l.floor=u;
                l.elivator=f;
                l.time=d[u][f];
                pq.push(l);

            }
        }
    }
    /*
    for(i=0;i<n;i++)
    {
        cout<<i<<"-";
        for(int j=0;j<=k;j++)
        if(d[j][i]!=INF)
        cout<<" "<<d[j][i];
        cout<<endl;
    }
    */
    mn=INF;
    for(i=0;i<n;i++)
    mn=min(mn,d[k][i]);

    if(mn==INF)
    printf("IMPOSSIBLE\n");
    else
    printf("%d\n",mn);

}
int main()
{
    int i,x;
    char ch;
    while(scanf("%d %d",&n,&k)==2)
    {
        for(i=0;i<n;i++)
        scanf("%d",&T[i]);

        for(i=0;i<n;i++)
        {
            while(scanf("%d%c",&x,&ch) && ch!=10)
            {
                g[i].push_back(x);
                h[x].push_back(i);
            }
            g[i].push_back(x);
            h[x].push_back(i);

        }
        dijkstra();

        for(i=0;i<n;i++)
        g[i].clear();
        for(i=0;i<k;i++)
        h[i].clear();
    }
    return 0;
}
