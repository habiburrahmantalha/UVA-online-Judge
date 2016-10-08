#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
    queue<int> q;
    int n,in,x,res[100],i;
    while(scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++)
            q.push(i);
        in=0;
        while(q.size()>1)
        {
            res[in++]=q.front(); q.pop();
            x=q.front();q.pop();
            q.push(x);
        }

        if(n>1)
        {
            printf("Discarded cards: ");
            for(i=0;i<in-1;i++)
                printf("%d, ",res[i]);
            printf("%d\n",res[i]);
        }
        else
            printf("Discarded cards:\n");
        x=q.front();q.pop();
        printf("Remaining card: %d\n",x);
    }
    return 0;
}
