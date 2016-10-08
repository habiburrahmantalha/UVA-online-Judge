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

int G[1010][1010],L[1010][1010],R[1010][1010];
int main()
{
    int n,m,tc,i,j,mx,x;
    char s[2];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&m,&n);
        for(i=0;i<m;i++)
            L[i][0]=R[i][n]=0;
        for(i=0;i<n;i++)
            G[0][i]=0;

        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%s",&s);
                if(s[0]=='R')
                    G[i][j]=0;
                else
                    G[i][j]=1;
            }
        }
        mx=0;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(G[i][j])
                    G[i][j]+=G[i-1][j];
            }
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(G[i][j-1]>=G[i][j])
                    L[i][j]=L[i][j-1]+1;
                else
                    L[i][j]=1;
            }
            for(j=n;j>0;j--)
            {
                if(G[i][j+1]>=G[i][j])
                    R[i][j]=R[i][j+1]+1;
                else
                    R[i][j]=1;

            }
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                x=G[i][j]*(L[i][j]+R[i][j]-1);
                if(mx<x)
                    mx=x;
            }
        }
        printf("%d\n",mx*3);
    }
    return 0;
}
