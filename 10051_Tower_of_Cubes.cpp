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

int g[510][10],n;
vector<int>DAG[3010];
char dir[6][10]={"front","back", "left", "right", "top", "bottom"};
void make_graph()
{
    int i,j,a,b;
    for(i=0;i<n;i++)
    {
        for(a=0;a<6;a++)
        {
            for(j=i+1;j<n;j++)
            {
                for(b=0;b<6;b++)
                {
                    if(g[i][a]==g[j][b])
                    DAG[(i*6)+a].push_back((j*6)+b);
                }
            }
        }
    }
}
int d[3010],pi[3010];
void bfs(int s)
{
    queue<int>q;
    int i,u,v;
    if(d[s]>1)
    return;
    d[s]=1;
    pi[s]=s;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();q.pop();
        //cout<<u<<" ";
        for(i=0;i<DAG[u].size();i++)
        {
            v=DAG[u][i];
            if(d[v]<d[u]+1)
            {
                d[v]=d[u]+1;
                pi[v]=u;
                q.push(v);
            }
        }
    }
}
void print()
{
    int i,j;
    for(i=0;i<n*6;i++)
    {
        for(j=0;j<DAG[i].size();j++)
        cout<<DAG[i][j]<<" ";
        cout<<endl;
    }
}
int get(int x)
{
    int i,j;
    for(i=0,j=5; ;i++,j+=6)
    if(j>=x)
    return i;
}
void get_dir(int s)
{
    int x=s%6;
    if(x==0)
    x=1;
    if(x==1)
    x=0;
    if(x==2)
    x=3;
    if(x==3)
    x=2;
    if(x==4)
    x=5;
    if(x==5)
    x=4;

    printf("%s\n",dir[x]);

}
void print_path(int s)
{
    if(s==pi[s])
    {
        printf("%d ",get(s)+1);
        get_dir(s);
        return;
    }
    print_path(pi[s]);
    printf("%d %s\n",get(s)+1,dir[s%6]);

}
int main()
{
    int i,j,s,mx;
    bool f=false;
    while(scanf("%d",&n) && n)
    {
        if(f)
        printf("\n");
        f=true;
        for(i=0;i<n;i++)
        {
            for(j=0;j<6;j++)
            scanf("%d",&g[i][j]);
        }
        make_graph();

        //print();
        memset(d,0,sizeof(d));
        for(i=0;i<n*6;i++)
            bfs(i);

        mx=0;
        for(i=0;i<n*6;i++)
            if(mx<d[i])
            {
                mx=d[i];
                s=i;
            }
            //cout<<s;
        print_path(s);
        //for(i=n*6;i>0;i--)
        //printf("%d ",d[i]);


        for(i=0;i<=n;i++)
        DAG[i].clear();
    }
    return 0;
}
