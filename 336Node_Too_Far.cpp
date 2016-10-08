#include<stdio.h>
#include<string.h>


void bfs(int s,int n)
{
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        u=q.front();q.pop();

        for(v=0;v<)
    }
}

int main()
{
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            g[a][b]=1;

        }
        while(scanf("%d %d",&a,&b) && a &&b)
        {
            bfs(a,b);
        }
    }
}
