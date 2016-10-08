//Problem Type :    Strongly Connected componet
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
using namespace std;
#define PI 2 * acos (0.0)

bool G[30][30],V[30],Gr[30][30];
stack<int>S;
vector<int>C[30];
int n;
void DFS(int u)
{
    V[u]=true;
    for(int v=1;v<n;v++)
    {
        if(G[u][v] && !V[v])
            DFS(v);
    }
    S.push(u);
}

void DFSr(int u,int c)
{
    C[c].push_back(u);
    V[u]=false;
    for(int v=1;v<n;v++)
    {
        if(Gr[u][v] && V[v])
            DFSr(v,c);
    }
}

int main()
{
    int q,i,j,c;
    map<char,int>m;
    vector<char>t;
    vector<vector<char> >res;
    char a[10];
    map<int,char>b;
    bool f=false;

    while(scanf("%d",&q)  && q)
    {
        if(f)
        printf("\n");
        f=true;

        n=1;
        memset(G,false,sizeof(G));
        memset(Gr,false,sizeof(Gr));
        for(i=0;i<q;i++)
        {
            for(j=0;j<6;j++)
            {
                cin>>a[j];
                if(!m[a[j]])
                {
                    b[n]=a[j];
                    m[a[j]]=n++;
                }
            }
            for(j=0;j<5;j++)
            {
                G[m[a[5]]][m[a[j]]]=true;
                Gr[m[a[j]]][m[a[5]]]=true;
            }
        }
        memset(V,false,sizeof(V));
        for(i=1;i<n;i++)
        {
            if(!V[i])
                DFS(i);
        }
        c=0;
        while(!S.empty())
        {
            i=S.top();S.pop();
            if(V[i])
                DFSr(i,++c);

        }
        for(i=1;i<=c;i++)
        {
            t.clear();
            for(j=0;j<C[i].size();j++)
                t.push_back(b[C[i][j]]);
            sort(t.begin(),t.end());
            res.push_back(t);
            //cout<<b[C[i][j]]<<" ";
            //cout<<endl;
        }
        sort(res.begin(),res.end());
        for(i=0;i<res.size();i++)
        {
            for(j=0;j<res[i].size();j++)
            {
                if(j==0)
                    cout<<res[i][j];
                else
                    cout<<" "<<res[i][j];
            }
            cout<<endl;
        }
        b.clear();
        res.clear();
        m.clear();
        for(i=0;i<=c;i++)
        C[i].clear();

    }
    return 0;
}
