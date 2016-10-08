//Problem Type :
//Time :    1.432
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


vector<int>gl[3010];
bool visit[3010],g[3010][3010];
int cnt,n;
int main()
{
    int tc,i,j,k,a,b,m;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        memset(g,false,sizeof(g));
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a][b]=g[b][a]=true;
            gl[a].push_back(b);
            gl[b].push_back(a);
        }
        memset(visit,false,sizeof(visit));
        cnt=0;
        for(i=1;i<=n;i++)
        {
            visit[i]=true;
            for(j=0;j<gl[i].size();j++)
            {
                for(k=j+1;k<gl[i].size();k++)
                {
                    if(g[gl[i][j]][gl[i][k]] && !visit[gl[i][j]] && !visit[gl[i][k]])
                    {
                        cnt++;
                    }
                }

            }
        }
        printf("%d\n",cnt);
        for(i=0;i<=n;i++)
        gl[i].clear();
    }
    return 0;
}
