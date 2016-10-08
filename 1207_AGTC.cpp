#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

char a[1010],b[1010];
int T[1010][1010],n,m;

void LCS()
{
    int i,j;
    for(i=0;i<=n;i++)
    T[i][0]=i;
    for(i=0;i<=m;i++)
    T[0][i]=i;

    //memset(T,0,sizeof(T));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        if(a[i]==b[j])
        T[i][j]=T[i-1][j-1];
        else
        T[i][j]=min(T[i-1][j-1],min(T[i-1][j],T[i][j-1]))+1;
    }
    /*
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        printf("%2d ",T[i][j]);
        printf("\n");
    }
    //*/
    printf("%d\n",T[n][m]);
}
int main()
{
    while(scanf("%d %s",&n,a+1)==2)
    {
        scanf("%d %s",&m,b+1);
        LCS();
    }
    return 0;
}
