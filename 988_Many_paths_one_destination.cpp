#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int> g[35];
int n;
long long c;
int visit[35];

void count_path(int x)
{
    int i,y;
    bool death=true;
    for(i=0;i<g[x].size();i++)
    {
        y=g[x][i];
        if(visit[y]==0)
        {
            death=false;
            visit[y]=1;
            count_path(y);
            visit[y]=0;
        }
    }
    if(death)
        c++;
}
int fr[35],D[35];
int main()
{
    //freopen("in.txt","r",stdin);
    bool f=false;
    int i,j,m,x;
    while(scanf("%d",&n)==1)
    {
        if(f)
            printf("\n");
        f=true;
        memset(visit,0,sizeof(visit));
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                g[i].push_back(x);
            }
        }
        c=0;
        count_path(0);
        printf("%lld\n",c);

        for(i=0;i<n;i++)
            g[i].clear();
    }
    return 0;
}
