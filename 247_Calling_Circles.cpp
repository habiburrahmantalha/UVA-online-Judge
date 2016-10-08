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

int visit[1010],n,m;
vector<int>g[1010],gr[1010];
map<int,vector<string> >circle;
map<string,int>mp;
map<int,string>mps;
stack<int>st;

void dfsf(int u)
{
    visit[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(visit[v]==0)
            dfsf(v);
    }
    st.push(u);
}
void dfsr(int u,int x)
{
    visit[u]=0;
    circle[x].push_back(mps[u]);
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(visit[v])
            dfsr(v,x);
    }
}
int main()
{
    string a,b;

    int i,j,group,t=1;

    while(scanf("%d %d",&n,&m) && n+m)
    {
        if(t>1)
        printf("\n");
        j=1;
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            if(mp[a]==0)
            {
                mp[a]=j;
                mps[j]=a;
                j++;
            }

            if(mp[b]==0)
            {
                mp[b]=j;
                mps[j]=b;
                j++;
            }

            g[mp[a]].push_back(mp[b]);
            gr[mp[b]].push_back(mp[a]);

        }
        memset(visit,0,sizeof(visit));
        for(i=1;i<=n;i++)
            if(visit[i]==0)
                dfsf(i);

        group=0;
        while(!st.empty())
        {
            i=st.top();st.pop();
            //cout<<i<<" ";
            if(visit[i])
            {
                //cout<<i<<endl;
                dfsr(i,++group);

            }
        }
        //printf("%d\n",group);
        printf("Calling circles for data set %d:\n",t++);
        for(i=1;i<=group;i++)
        {
            for(j=0;j<circle[i].size()-1;j++)
            cout<<circle[i][j]<<", ";
            cout<<circle[i][j]<<endl;
        }
        for(i=0;i<=n;i++)
        {
            g[i].clear();
            gr[i].clear();
        }

        mp.clear();
        mps.clear();
        circle.clear();


    }
    return 0;
}
