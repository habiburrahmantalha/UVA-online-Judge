#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

int visit[101][101],n,count;
char g[101][101];

void alive_ship()
{
    int i,j,k;
    bool f;
    count=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            f=false;
            if((g[i][j]=='x' || g[i][j]=='@' ) && visit[i][j]==0)
            {
                if(g[i][j]=='x')
                        f=true;

                k=1;
                if((g[i][j+k]=='x' || g[i][j+k]=='@' ))
                while((g[i][j+k]=='x' || g[i][j+k]=='@' ))
                {
                    //visit[i][j+k]=1;
                    if(g[i][j+k]=='x')
                        f=true;
                    k++;
                    j++;
                }
                k=1;
                if((g[i+k][j]=='x' || g[i+k][j]=='@' ))
                while((g[i+k][j]=='x' || g[i+k][j]=='@' ))
                {
                    visit[i+k][j]=1;
                    if(g[i+k][j]=='x')
                        f=true;
                    k++;
                }
                if(f)
                    count++;
            }
        }
}

int main()
{
    int tc,t,i,j;

    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        memset(g,0,sizeof(g));
        memset(visit,0,sizeof(visit));
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",g[i]);

        alive_ship();
        printf("Case %d: %d\n",t,count);
    }
    return 0;
}
