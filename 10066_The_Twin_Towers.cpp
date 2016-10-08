#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int m,n,N1[110],N2[110];

int LCS()
{
    int T[110][110],i,j;
    memset(T,0,sizeof(T));
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(N1[i]==N2[j])
                T[i+1][j+1]=T[i][j]+1;
            else
                T[i+1][j+1]=max(T[i][j+1],T[i+1][j]);
        }
    }
    return T[m][n];
}



int main()
{
    int i,tiles,t=1;
    while(scanf("%d %d",&m,&n) &&m && n)
    {
        for(i=0;i<m;i++)
            scanf("%d",&N1[i]);
        for(i=0;i<n;i++)
            scanf("%d",&N2[i]);
        tiles=LCS();
        printf("Twin Towers #%d\n",t++);
        printf("Number of Tiles : %d\n\n",tiles);
    }
    return 0;
}
