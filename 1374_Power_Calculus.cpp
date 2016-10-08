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

int d[4025];
vector<int> a[16];
bool V[4025][4025];
void bfs()
{
    priority_queue<pair<int,int> >q;
    int u,v,i,j,k;
    memset(d,0x7F,sizeof(d));
    memset(V,false,sizeof(V));
    d[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        u=q.top().second;
        q.pop();
        v=u-1;
        if(v>0 && v<4025 && d[v]>d[u]+1)
        {
            d[v]=d[u]+1;
            q.push(make_pair(-d[v],v));
        }
        v=u+1;
        if(v>0 && v<4025 && d[v]>d[u]+1)
        {
            d[v]=d[u]+1;
            q.push(make_pair(-d[v],v));
        }
        v=u*2;
        if(v>0 && v<4025 && d[v]>d[u]+1)
        {
            d[v]=d[u]+1;
            q.push(make_pair(-d[v],v));
        }
    }
}
void BFS()
{
    priority_queue<pair<int,pair<int,int> > >q;
    int u,v,i,j,k;
    memset(d,0x7F,sizeof(d));
    memset(V,false,sizeof(V));

    d[1]=0;
    a[0].push_back(1);
    V[0][1]=true;
    for(i=1;i<10;i++)
    {
        d[1<<i]=i;
        a[i]=a[i-1];
        a[i].push_back(1<<i);
        V[i][1<<i]=true;
        q.push(make_pair(-i,make_pair(i,1<<i)));
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<a[i].size();j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    while(!q.empty())
    {
        u=q.top().second.second;
        k=q.top().second.first;
        q.pop();
        for(i=0;i<a[k].size();i++)
        {

            for(j=0;j<2;j++)
            {

                if(j==0)
                    v=u+a[k][i];
                else
                    v=u-a[k][i];

                if(v>0 && v<1024 && d[v]>d[u]+1)
                {
                    d[v]=d[u]+1;
                    /*
                    if(!V[k][v])
                    {
                        a[i].push_back(v);
                        V[i][v]=true;
                    }
                    */
                    q.push(make_pair(-d[v],make_pair(k,v)));
                }
            }
        }
    }
}


int main()
{
    //BFS();
    bfs();
    int x;
    while(scanf("%d",&x)==1 && x)
    {
        printf("%d\n",d[x]);
    }
    return 0;
}
