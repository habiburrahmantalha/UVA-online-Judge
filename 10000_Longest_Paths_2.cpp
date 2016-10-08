#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define FOR(i,x,y) for(i=x;i<=y;i++)
int g[110][110];
int mx,s,e,n;

void warshal()
{
    int i,j,k;
    FOR(k,1,n)
    FOR(i,1,n)
    FOR(j,1,n)
    g[i][j]=max(g[i][k]+g[k][j] , g[i][j]);

    FOR(i,1,n)
 {

    //FOR(j,1,n)
    printf("%d ",g[s][i]);
    printf("\n");
}
    mx=0;
    FOR(i,1,n)
    {
        if(g[s][i]>mx)
        {
            mx=g[s][i];
            e=i;
        }
    }
}
int main()
{
    int a,b,i,t=1;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&s);
        memset(g,0,sizeof(g));
        while(scanf("%d %d",&a,&b) && a && b)
            g[a][b]=1;;

        warshal();

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",t++,s,mx-1,e);

    }
    return 0;
}
