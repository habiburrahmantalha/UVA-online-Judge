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
bool G[110][110],V[110],C[110];
vector<int>black;
int n,m;

void color(int u)
{

    queue<int>q;
    int v,i,c;
    vector<int>node;

    node.push_back(u);
    c=0;
    q.push(u);
    V[u]=true;
    C[u]=true;
    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(v=1;v<=n;v++)
        {
            if(G[u][v])
            {
                if(!V[v])
                {
                    node.push_back(v);
                    if(!C[u])
                    {
                        C[v]=true;
                        c++;
                    }
                    V[v]=true;
                    q.push(v);
                }

            }
        }
    }
    cout<<node.size()<<c<<endl;
    if(c>=node.size()-c)
    {
        for(i=0;i<node.size();i++)
        {
            if(C[node[i]])
                black.push_back(node[i]);
        }
    }
    else
    {
        for(i=0;i<node.size();i++)
        {
            if(!C[node[i]])
                black.push_back(node[i]);
        }

    }

}
int main()
{
    int tc,i,a,b;
    scanf("%d",&tc);

    while(tc--)
    {
        memset(G,false,sizeof(G));
        memset(V,false,sizeof(V));
        memset(C,false,sizeof(C));

        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            G[a][b]=G[b][a]=true;
        }
        for(i=1;i<=n;i++)
            if(!V[i])
                color(i);
        printf("%d\n",black.size());
        sort(black.begin(),black.end());
        for(i=0;i<black.size();i++)
        {
            if(i==0)
            printf("%d",black[i]);
            else
            printf(" %d",black[i]);
        }
        printf("\n");

        black.clear();
    }
    return 0;
}
