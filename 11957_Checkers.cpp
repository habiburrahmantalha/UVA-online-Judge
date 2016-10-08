#include<stdio.h>
#include<string.h>

int main()
{
    int tc,i,j,t=1,res,cost[110][110],n;
    char g[110][110];

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%s",g[i]);
        memset(cost,0,sizeof(cost));
        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]=='W')
                cost[i][j]=1;
                if(g[i][j]=='.')
                {
                    if(j>0)
                    {
                        if(j>1 && g[i+1][j-1]=='B')
                        cost[i][j]=(cost[i][j]+cost[i+2][j-2])%1000007;
                        else
                        cost[i][j]=(cost[i][j]+cost[i+1][j-1])%1000007;
                    }

                    if(g[i+1][j+1]=='B')
                    cost[i][j]=(cost[i][j]+cost[i+2][j+2])%1000007;
                    else
                    cost[i][j]=(cost[i][j]+cost[i+1][j+1])%1000007;
                }
            }
        }
        res=0;
        for(i=0;i<n;i++)
        res=(res+cost[0][i])%1000007;
        printf("Case %d: %d\n",t++,res);
    }
    return 0;
}
