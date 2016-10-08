#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int g[110][110],R,C,N,h[110][110];
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};

bool valid(int x,int y)
{
    if(x<0 || x>=R || y<0 || y>=C)
        return false;
    return true;
}



void attack()
{


    int i,j,k,x,y,c,u,v;

    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            h[i][j]=g[i][j];


    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
    {

        for(k=0;k<4;k++)
        {
            x=i+X[k];
            y=j+Y[k];

            if(valid(x,y) && ((h[i][j]+1)%N==h[x][y]))
            {
                //printf("%d %d*\n",x,y);
                g[x][y]=h[i][j];
            }
        }
    }


}
int main()
{
    int K,i,j;
    while(scanf("%d %d %d %d",&N,&R,&C,&K))
    {
        if(N==0 && R==0 && C==0 && K==0)
            break;
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            scanf("%d",&g[i][j]);

        for(int k=0;k<K;k++)
            attack();

        for(i=0;i<R;i++)
        {
            for(j=0;j<C-1;j++)
                printf("%d ",g[i][j]);
            printf("%d\n",g[i][j]);
        }

    }
    return 0;
}
