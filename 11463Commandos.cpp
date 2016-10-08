#include<stdio.h>
#include<string.h>

int g[101][101];

int n;
void warshall()
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
		    if(g[i][k]!=0 && i!=k)
			for(j=0;j<n;j++)
			{
			    if(g[k][j]!=0 && j!=k)
			    if(i!=j)
			    {
                    if(g[i][j]==0)
                    g[i][j]=g[i][k]+g[k][j];
                    else if(g[i][j]>g[i][k]+g[k][j])
					g[i][j]=g[i][k]+g[k][j];
			    }
			}
		}
	}
}

int main()
{
    int a,b,max,i,j,k,tc,m;
    scanf("%d",&tc);
    for(k=1;k<=tc;k++)
    {
        memset(g,0,sizeof(g));
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a][b]=g[b][a]=1;
        }
        scanf("%d %d",&a,&b);
        warshall();
        /*
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d ",g[i][j]);
            printf("\n");
        }
        */
        max=0;
        for(i=0;i<n;i++)
        {
            if(max<(g[a][i]+g[i][b]))
            max=(g[a][i]+g[i][b]);
        }
        printf("Case %d: %d\n",k,max);
    }
    return 0;
}
