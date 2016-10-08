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
#define inf 20000000

int main()
{
    int i,j,k,l,mn,m,n,x;
    int g[125][20][20];
    char name[20];
    while(scanf("%s",name)==1)
    {
        memset(g,0,sizeof(g));
        scanf("%d %d",&n,&m);
        for(i=1;i<n;i++)
        {
            for(j=1;j<=m;j++)
            {
                for(k=1;k<=m;k++)
                {
                    scanf("%d",&x);
                    g[i][j][k]=x+2;
                }
            }
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<=m;j++)
            {
                for(k=1;k<=m;k++)
                {
                    mn=inf;
                    for(l=1;l<=m;l++)
                    {
                        if(mn>g[i-1][l][j])
                        mn=g[i-1][l][j];
                        //mn=min(mn,g[i-1][l][j]);
                    }
                    g[i][j][k]+=mn;
                }
            }
        }
        /*
        for(i=1;i<n;i++)
        {
            printf("%d\n",i);
            for(j=1;j<=m;j++)
            {
                printf("%d\n",j);
                for(k=1;k<=m;k++)
                printf("%d ",g[i][j][k]);
                printf("\n");
            }

        }
        */
        mn=inf;
        for(i=1;i<=m;i++)
            for(j=1;j<=m;j++)
                mn=min(g[n-1][i][j],mn);
        printf("%s\n",name);
        printf("%d\n",mn);


    }
    return 0;
}
