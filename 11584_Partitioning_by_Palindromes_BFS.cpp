#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

char str[1010];
int d[1010],visit[1010],len;

bool palindrom(int i,int j)
{
    int m,n;
    for(m=i,n=j;m<=n;m++,n--)
    if(str[m]!=str[n])
    return false;

    return true;
}
void bfs()
{
    queue<int>q;
    int i,u;
    memset(d,0,sizeof(d));
    memset(visit,0,sizeof(visit));

    for(i=len-1;i>=0;i--)
    if(palindrom(0,i))
    {
        q.push(i);
        d[i]=1;
        visit[i]=1;
        if(visit[len-1])
        return;

    }
    while(!q.empty())
    {
        u=q.front();q.pop();

        for(i=len;i>u;i--)
        if(visit[i]==0 && palindrom(u+1,i))
        {
            q.push(i);
            d[i]=d[u]+1;
            visit[i]=1;
            if(visit[len-1])
            return;

        }
    }
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",&str);
        len=strlen(str);
        bfs();
        printf("%d\n",d[len-1]);
    }
    return 0;
}
