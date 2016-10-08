#include<algorithm>
#include<string.h>
#include<stdio.h>

using namespace std;
int V[1010],W[1010],n;

int knapsack(int w)
{
    int i,j,T[1010][35];

    for(i=0;i<=w;i++)
        T[0][i]=0;

    for(i=1;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(W[i-1]<=j)
                T[i][j]=max(T[i-1][j],V[i-1]+T[i-1][j-W[i-1]]);
            else
                T[i][j]=T[i-1][j];
        }
    }
    /*
    for(i=0;i<=n;i++){
        for(j=0;j<=w;j++)
        printf("%d ",T[i][j]);
    printf("\n");
    }
    */
    return T[n][w];
}
int main()
{
    int tc,m,x,res,i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d",&V[i],&W[i]);
        scanf("%d",&m);
        res=0;
        for(i=0;i<m;i++)
        {
            scanf("%d",&x);
            res+=knapsack(x);
        }
        printf("%d\n",res);
    }
    return 0;
}
