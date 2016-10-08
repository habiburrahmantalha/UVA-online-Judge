#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;


struct holes
{
    char ch;
    int n;
};

char g[55][55],h;
int n,m,visit[55][55],c;
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
vector<holes> z;

bool comp(holes a,holes b)
{
    if(a.n==b.n)
        return a.ch<b.ch;
    return a.n >b.n;
}



bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
}
void visit_dfs(int x,int y)
{
    int i,u,v;
    visit[x][y]=1;
    for(i=0;i<4;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v) && g[u][v]==h && visit[u][v]==0)
        {
            c++;
            visit_dfs(u,v);
        }
    }
}

void dfs()
{
    int i,j;
    holes zz;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(g[i][j]!='.' && visit[i][j]==0)
            {
                h=g[i][j];
                c=1;
                visit_dfs(i,j);
                zz.ch=h;
                zz.n=c;
                z.push_back(zz);
            }

        }
    }
}

int main()
{
    int i,t=1;
    while(scanf("%d %d",&n,&m) &&n &&m )
    {
        memset(g,0,sizeof(g));
        memset(visit,0,sizeof(visit));
        z.clear();
        for(i=0;i<n;i++)
            scanf("%s",g[i]);
        dfs();
        sort(z.begin(),z.end(),comp);
        printf("Problem %d:\n",t++);
        for(i=0;i<z.size();i++)
            printf("%c %d\n",z[i].ch,z[i].n);

    }
    return 0;
}
