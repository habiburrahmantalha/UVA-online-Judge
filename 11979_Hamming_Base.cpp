#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

int N,M,H[2010][12],count,F[2010];

void step_count()
{
    queue<int> q;
    int i,j,p;
    for(i=0;i<N;i++)
    {
        if(F[i]==0)
            q.push(i);
        else if(F[i]>1)
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
                    if(F[j]==0)
                    {
                        F[j]++;
                        count+=j-i;
                        break;
                    }
                }
            }
            F[i]--;
            i--;
        }
    }
}


int main()
{
    int tc,t=1,i,j;
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        scanf("%d %d",&N,&M);
        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                scanf("%d",&H[i][j]);
        count=0;
        for(i=0;i<M;i++)
        {
            memset(F,0,sizeof(F));
            for(j=0;j<N;j++)
                F[H[j][i]]++;
            step_count();
        }
        printf("Case %d: %d\n",t,count);

    }
    return 0;
}
