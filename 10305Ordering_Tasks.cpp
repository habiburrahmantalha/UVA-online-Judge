//have to try next

#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

int taken[101],n,m,take[101][101],list[101],indegree[101];

int main()
{
    int i,j,k,a,b;
    while(scanf("%d %d",&n,&m) && n && m)
    {
        memset(taken,0,sizeof(taken));
        memset(indegree,0,sizeof(indegree));
        memset(list,0,sizeof(list));
        memset(take,0,sizeof(take));

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            take[a][b]=1;
            indegree[b]++;
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            if(indegree[j]==0 && taken[j]==0){
                taken[j]=1;
                list[i]=j;

            for(k=1;k<=n;k++)
            if(!taken[k] && take[j][k])
            --indegree[k];
            break;
            }

        }
        for(i=1;i<=n;i++)
        printf("%d ",list[i]);
        printf("\n");
    }

}

/*
vector<int>ans,depend[101];
int n,m;
int taken[101];

void take(int p)
{
    int i;
    if(!taken[p])
    {
        for(i=0;i<depend[p].size();i++)
        take(depend[p][i]);
        ans.push_back(p);
        taken[p]=1;
    }
}

int main()
{
    int i,a,b;
    while(scanf("%d %d",&n,&m) && n && m)
    {
        memset(taken,0,sizeof(taken));
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            depend[b].push_back(a);
        }
        for(i=1;i<=n;i++)
        take(i);
        for(i=0;i<n-1;i++)
        printf("%d ",ans[i]);
        printf("%d\n",ans[n-1]);
    }
    return 0;

}
*/
