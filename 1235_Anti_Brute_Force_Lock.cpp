#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int,pair<int,int> > > graph;

int n,m,cost;
char x[510][10];
int d[11][11],P[510];

int find(int x)
{
    if(P[x]!=x)
    P[x]=find(P[x]);
    return P[x];
}

void krushkal()
{
    int u,v,i;

    for(i=0;i<=n;i++)
    P[i]=i;

    for(i=0;i<graph.size();i++)
    {
        u=find(graph[i].second.first);
        v=find(graph[i].second.second);
        if(u!=v)
        {
            //printf("->%d %d %d\n",graph[i].second.first,graph[i].second.second,graph[i].first);
            P[u]=P[v];
            cost+=graph[i].first;
            m++;
            if(m==n)
            break;
        }
    }
}

void dist()
{
    int k,i,j;

    for(i=0;i<10;i++)
    d[0][i]=min(0+i,10-i);

    for(i=1;i<10;i++)
        for(j=0;j<10;j++)
            d[i][j]=d[i-1][(j+9)%10];
/*
    for(i=0;i<10;i++)
    {
        printf("%d->",i);
        for(j=0;j<10;j++)
        printf("%d ",d[i][j]);
        printf("\n");
    }
*/
}
int getdist(int i,int j)
{
    int k,a,b,c;
    c=0;
    for(k=0;k<4;k++)
    {
        a=x[i][k]-'0';
        b=x[j][k]-'0';
        c+=d[a][b];
    }
    return c;
}
int main()
{
    dist();
    int tc,i,j;

    scanf("%d",&tc);

    while(tc--)
    {
        strcpy(x[0],"0000");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%s",x[i]);

        cost=2000000;
        for(i=1;i<=n;i++)
        cost=min(cost,getdist(0,i));

        for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        graph.push_back(make_pair(getdist(i,j),make_pair(i,j)));

        //m=graph.size();
        sort(graph.begin(),graph.end());

        krushkal();

        printf("%d\n",cost);

        //for(i=0;i<graph.size();i++)
        //printf("%d %d %d\n",graph[i].first,graph[i].second.first,graph[i].second.second);

        graph.clear();
    }
    return 0;
}
