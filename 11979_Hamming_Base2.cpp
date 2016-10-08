#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

int N,M,count,F[2010][12];

void step_count(int x)
{
    queue<int> q;
    int i,j,p;
    for(i=0;i<N;i++)
    {
        if(F[i][x]==0)
            q.push(i);
        else if(F[i][x]>1)
        {
            if(!q.empty())
            {
                p=q.front();
                q.pop();
                count+=i-p;
            }
            else
            {
                for(j=i+1;j<N;j++)
                {
                    if(F[j][x]==0)
                    {
                        F[j][x]++;
                        count+=j-i;
                        break;
                    }
                }
            }
            F[i][x]--;
            i--;
        }
    }
}


int main()
{
    int tc,t=1,i,j,x;
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        memset(F,0,sizeof(F));
        scanf("%d %d",&N,&M);

        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
            {
                scanf("%d",&x);
                F[x][j]++;
            }
        count=0;
        for(i=0;i<M;i++)
        {
            step_count(i);
        }
        printf("Case %d: %d\n",t,count);

    }
    return 0;
}
