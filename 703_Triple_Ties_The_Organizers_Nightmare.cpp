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
int x[5],g[110][110],n;
vector<int>g_1[110],g_0[110];
bool v[110];
vector<vector<int> > cycle;
bool sorted(vector<int> t)
{
    if((t[0]> t[1] && t[1]>t[2]) || (t[0]< t[1] && t[1]<t[2]) )
    return true;
    return false;
}
void triple_ties(int s,int k,int u)
{
    x[k]=u;
    if(k==3 && g[u][s])
    {
        vector<int> t(x+1,x+4);
        while(!sorted(t))
        rotate(t.begin(),t.begin()+1,t.end());
        cycle.push_back(t);
        return;
    }
    else
    {
        for(int i=0;i<g_1[u].size();i++)
        {

            if(!v[g_1[u][i]])
            {
                v[g_1[u][i]]=true;
                triple_ties(s,k+1,g_1[u][i]);
                v[g_1[u][i]]=false;
            }
        }
    }
}
void triple_ties_0(int s,int k,int u)
{
    x[k]=u;
    if(k==3 && !g[u][s])
    {
        vector<int> t(x+1,x+4);
        cycle.push_back(t);
        return;
    }
    else
    {
        for(int i=0;i<g_0[u].size();i++)
        {
            if(!v[g_0[u][i]] && u<g_0[u][i])
            {
                v[g_0[u][i]]=true;
                triple_ties_0(s,k+1,g_0[u][i]);
                v[g_0[u][i]]=false;
            }
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&g[i][j]);
                if(i==j)
                    continue;
                if(g[i][j])
                    g_1[i].push_back(j);
                else
                    g_0[i].push_back(j);
            }
        }
        memset(v,false,sizeof(v));
        for(i=1;i<=n;i++)
        {
            v[i]=true;
            triple_ties(i,1,i);

            //v[i]=false;
        }
        memset(v,false,sizeof(v));
        if(cycle.size()==0)
        {
            for(i=1;i<=n;i++)
            {
                v[i]=true;
                triple_ties_0(i,1,i);

                //v[i]=false;
            }

        }
        sort(cycle.begin(),cycle.end());
        printf("%d\n",cycle.size());
        for(i=0;i<cycle.size();i++)
            printf("%d %d %d\n",cycle[i][0],cycle[i][1],cycle[i][2]);

        cycle.clear();
        for(i=0;i<=n;i++)
        {
            g_0[i].clear();
            g_1[i].clear();
        }
    }
    return 0;
}
