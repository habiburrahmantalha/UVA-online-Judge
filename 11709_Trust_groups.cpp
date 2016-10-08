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
void dfsr(int u)
{
    visit[u]=0;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(visit[v])
            dfsr(v);
    }
}
int main()
{
    string a,b,c,d;
    map<string,int>mp;
    int i,group;

    while(scanf("%d %d",&n,&m) && n+m)
    {
        for(i=0;i<n;i++)
        {
            cin>>a>>b;
            a+=b;
            mp[a]=i+1;
        }

        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            a+=b;
            cin>>c>>d;
            c+=d;
            g[mp[a]].push_back(mp[c]);
            gr[mp[c]].push_back(mp[a]);

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
                dfsr(i);
                group++;
            }
        }
        printf("%d\n",group);
        for(i=0;i<=n;i++)
        {
            g[i].clear();
            gr[i].clear();
        }
        mp.clear();

    }
    return 0;
}
