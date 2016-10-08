//Problem Type : vertex cover
//Time :    .416
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

int visit[1010],v[1010];
int f[1010][2],g[1010][1010];
int n;

int v_cover(int x,int k)
{
    v[x]=1;
    if(f[x][k]!=-1)
        return f[x][k];
    int sum;
    if(k==1)
    sum=1;
    else
    sum=0;

    for(int i=1;i<=n;i++)
    {

        if(!visit[i] && g[x][i])
        {
            visit[x]=1;
            if(k==1)
            sum+=min(v_cover(i,1),v_cover(i,0));
            else
            sum+=v_cover(i,1);
            visit[x]=0;
        }
    }

    return f[x][k]=sum;

}
int main()
{
    int i,m,x,res;
    while(scanf("%d",&n) && n)
    {
        memset(g,0,sizeof(g));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&x);
                g[i][x]=g[x][i]=1;

            }
        }

        memset(f,-1,sizeof(f));
        memset(v,0,sizeof(v));
        res=0;
        i=1;
        for(i=1;i<=n;i++)
        {
            if(!v[i])
            {
                //visit[i]=1;
                memset(visit,0,sizeof(visit));
                v_cover(i,0);
                //memset(visit,0,sizeof(visit));
                v_cover(i,1);
                //visit[i]=0;
                res+=max(min(f[i][0],f[i][1]),1);

            }

        }
        //for(i=1;i<=n;i++)
        {
            //printf("%d %d %d\n",i,f[i][0],f[i][1]);
        }
        printf("%d\n",res);
    }
    return 0;
}
