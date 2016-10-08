#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int R,C,M,N,g[110][110],vi[110][110];

map<pair<int,int>,int>d;
map<pair<int,int>,int> :: iterator it;
map<pair<pair<int,int>,pair<int,int> >,int>visit;
pair<int,int>p;
pair<pair<int,int>,pair<int,int> > q;
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

    vi[u][v]++;
    q.first.first=u;
    q.first.second=v;
    for(i=0;i<8;i++)
    {
        x=u+X[i];
        y=v+Y[i];

        if(valid(x,y) && g[x][y] && vi[x][y]<5)
        {
            printf("%d %d\n",x,y);
            p.first=q.second.first=x;
            p.first=q.second.second=y;
            if(visit[q]==0)
            {
                d[p]++;
                visit[q]=1;
            }
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
        //memset(d,0,sizeof(d));
        memset(vi,0,sizeof(vi));
        //memset(visit,0,sizeof(visit));
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
            p.first=i;
            p.second=j;
            if(vi[i][j])
            {
                if(d[p]&1)
                odd++;
                else
                even++;
            }
        }
        for(it=d.begin();it!=d.end();it++)
        printf("%d ",it->second);
        printf("Case %d: %d %d\n",t++,even,odd);
        visit.clear();
        d.clear();
    }
    return 0;
}
