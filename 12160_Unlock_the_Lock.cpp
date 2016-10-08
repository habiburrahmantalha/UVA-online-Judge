#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

int d[10001];
int U,V,R,B[1001];

void BFS()
{
    int u,v,i;
    queue<int>q;
    memset(d,-1,sizeof(d));
    q.push(U);
    d[U]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<R;i++)
        {
            v=(u+B[i])%10000;
            if(d[v]==-1)
            {
                d[v]=d[u]+1;
                q.push(v);
            }

        }
    }
}


int main()
{
    int i,t=1;
    while(scanf("%d %d %d",&U,&V,&R) && U+V+R)
    {
        for(i=0;i<R;i++)
        scanf("%d",&B[i]);

        BFS();
        if(d[V]==-1)
        printf("Case %d: Permanently Locked\n",t++);
        else
        printf("Case %d: %d\n",t++,d[V]);
    }
    return 0;
}
