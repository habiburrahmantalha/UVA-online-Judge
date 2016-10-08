#include<stdio.h>
#include<string.h>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int N,M,n,visit[110][110],d[110][110],P[110],cost;
char B[110][110];
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
vector<pair<int,pair<int,int> > > graph;
pair<int,int>u,v;
map<pair<int,int>,int>mp;

void reset()
{
    for(int i=0;i<n;i++)
    P[i]=i;
}
int find(int x)
{
    if(P[x]!=x)
    P[x]=find(P[x]);
    return P[x];
}
void krushkal()
{
    int i,m,pu,pv,mst=0;
    int edge=graph.size();
    cost=0;
    for(i=0;i<edge;i++)
    {
        pu=find(graph[i].second.first);
        pv=find(graph[i].second.second);
        if(pu!=pv)
        {
            P[pu]=P[pv];
            mst++;
            cost+=graph[i].first;
            if(mst==n-1)
            break;
        }
    }
}
void MST()
{
    reset();
    sort(graph.begin(),graph.end());
    krushkal();
    printf("%d\n",cost);
    graph.clear();
    mp.clear();
}
void bfs(int i,int j)
{
    queue<int>q;
    int x,y,k;

    memset(visit,0,sizeof(visit));
    memset(d,0,sizeof(d));
    q.push(i);
    q.push(j);
    visit[i][j]=1;
    d[i][j]=0;
    while(!q.empty())
    {
        i=q.front();q.pop();
        j=q.front();q.pop();
        for(k=0;k<4;k++)
        {
            x=i+X[k];
            y=j+Y[k];
            if((B[x][y]==' ' || B[x][y]=='A' )&& visit[x][y]==0 )
            {
                d[x][y]=d[i][j]+1;
                visit[x][y]=1;
                if(B[x][y]=='A')
                {
                    v.first=x;
                    v.second=y;
                    graph.push_back(make_pair(d[x][y],make_pair(mp[u],mp[v])));
                }
                q.push(x);
                q.push(y);
            }
        }
    }
}
int main()
{
    int tc,i,j;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&M,&N);
        gets(B[0]);
        for(i=0;i<N;i++)
        gets(B[i]);

        n=0;
        for(i=0;i<N;i++)
        for(j=0;j<M;j++)
        if(B[i][j]=='S' || B[i][j]=='A')
        {
            u.first=i;
            u.second=j;
            mp[u]=n++;
        }

        for(i=0;i<N;i++)
        for(j=0;j<M;j++)
        {
            if(B[i][j]=='S' || B[i][j]=='A')
            {
                u.first=i;
                u.second=j;
                bfs(i,j);
            }
        }
        MST();


    }
    return 0;
}
