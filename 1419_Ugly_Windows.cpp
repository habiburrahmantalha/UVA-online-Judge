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

char G[110][110];
bool V[110][110];
bool top_window(int i,int j,int c)
{

    for(;G[i][j]==c;j++)
    {
        V[i][j]=true;
    }
    for(;G[i][j]==c;i++)
    {
        V[i][j]=true;
    }
    for(;G[i][j]==c;j--)
    {
        V[i][j]=true;
    }
    for(;G[i][j]==c;i--)
    {
        V[i][j]=true;
    }
    return true;

}

int main()
{
    while(scanf("%d %d",&n,&m) && n+m)
    {
        memset(V,false,sizeof(V));
        for(i=0;i<n;i++)
            scanf("%s",G[i]);
        for(i=0i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!V[i][j] && G[i][j]!='.')
                    if(top_window(i,j,G[i][j]))
                        v.push_back(G[i][j]);
            }
        }
        sort(v.begin(),v.end());
        for(i=0;i<v.size();i++)
            printf("%c",v[i]);
        v.clear();
    }
    return 0;
}
