//Problem Type :    strongly connected component
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
#include<stack>
#include<sstream>
using namespace std;
#define PI 2 * acos (0.0)

map<string ,int> m;
bool G[110][110],Gr[110][110],V[110],S[110];
vector<string>word,res;
vector<int>sub_d[110];
stack<int>st;
vector<int>w;
int n;

void DFS(int u)
{
    V[u]=true;
    for(int v=1;v<=n;v++)
    {
        if(G[u][v] && !V[v] && u!=v)
            DFS(v);
    }
    st.push(u);
}

void DFSr(int u,int c)
{
    V[u]=false;
    sub_d[c].push_back(u);
    for(int v=1;v<=n;v++)
    {
        if(Gr[u][v] && V[v] && u!=v)
            DFSr(v,c);
    }

}
void DFSf(int u)
{
    V[u]=true;
    res.push_back(word[u-1]);
    for(int v=1;v<=n;v++)
    {
        if(G[u][v] && !V[v] && u!=v)
            DFSf(v);
    }
}

int main()
{
    int i,j,k,c;
    string a,b,line;

    while(scanf("%d",&n) && n)
    {
        getline(cin,line);
        k=1;
        memset(G,false,sizeof(G));
        memset(Gr,false,sizeof(Gr));
        memset(S,true,sizeof(S));
        for(i=0;i<n;i++)
        {
            getline(cin,line);
            stringstream sin(line);
            sin>>a;
            if(!m[a])
            {
                m[a]=k++;
                word.push_back(a);
            }
            while(sin>>b)
            {
                if(!m[b])
                {
                    m[b]=k++;
                    word.push_back(b);
                }
                G[m[a]][m[b]]=true;
                Gr[m[b]][m[a]]=true;
                S[m[a]]=false;
            }
        }
        //for(i=0;i<n;i++)
        //cout<<word[i]<<endl;
        memset(V,false,sizeof(V));
        for(i=1;i<=n;i++)
        {
            if(!V[i])
                DFS(i);
        }
        c=0;
        while(!st.empty())
        {
            i=st.top();st.pop();
            if(V[i])
                DFSr(i,++c);
        }
        for(i=1;i<=c;i++)
        {
            if(sub_d[i].size()>1)
            {
                for(j=0;j<sub_d[i].size();j++)
                w.push_back(sub_d[i][j]);
            }
        }
        for(i=1;i<=n;i++)
        {
            if(S[i])
                w.push_back(i);
        }
        memset(V,false,sizeof(V));
        for(i=0;i<w.size();i++)
        {
            if(!V[w[i]])
                DFSf(w[i]);
        }

        sort(res.begin(),res.end());
        printf("%d\n",res.size());
        for(i=0;i<res.size();i++)
        {
            if(i==0)
            cout<<res[i];
            else
            cout<<" "<<res[i];
        }
        cout<<endl;
        for(i=0;i<=c;i++)
        sub_d[i].clear();
        m.clear();
        word.clear();
        res.clear();
        w.clear();


    }
    return 0;
}
