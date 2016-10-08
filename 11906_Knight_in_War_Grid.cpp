#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int R,C,M,N,g[110][110],visit[110][110][10],d[110][110];


bool f;
bool valid(int x,int y)
{
    if(x<0 || x>=R || y<0 || y>=C)
    return false;

    return true;
}

void dfs(int u,int v)
{
    int x,y,i;

    int X[]={-N,-M,-M,-N,N,M,M,N};
    int Y[]={-M,-N,N,M,M,N,-N,-M};


    for(i=0;i<8;i++)
    {
        x=u+X[i];
        y=v+Y[i];

        if(valid(x,y) && g[x][y] && visit[x][y][i]==0)
        {
            //printf("%d %d\n",x,y);
            d[x][y]++;
            visit[x][y][i]=1;
            dfs(x,y);
        }
    }
}
int main()
{
    int tc,t=1,a,b,w;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d %d %d %d",&R,&C,&M,&N);
        scanf("%d",&w);
        memset(g,1,sizeof(g));
        memset(d,0,sizeof(d));
        memset(visit,0,sizeof(visit));

        while(w--)
        {
            scanf("%d %d",&a,&b);
            g[a][b]=0;
        }

        dfs(0,0);

        int i,j,odd=0,even=0;


        for(i=0;i<R;i++)
        for(j=0;j<C;j++)
        {

            if(d[i][j])
            {
                if(d[i][i]&1)
                odd++;
                else
                even++;
            }
        }

        printf("Case %d: %d %d\n",t++,even,odd);

    }
    return 0;
}
