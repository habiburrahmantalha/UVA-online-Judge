#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int g[35][35];
int n;
long long d[35];

void count_path()
{
    queue<int> q;
    for(i=0;i<=n;i++)
        if(g[0][i])
        {
            d[i]=1;
            q.push(i);
        }
    while(!q.empty())
    {

    }


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
            if(m==0)
                g[i][n]=1;
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                g[i][x]=1;
            }
        }

        count_path(0);
        printf("%lld\n",c);

        for(i=0;i<n;i++)
            g[i].clear();
    }
    return 0;
}
