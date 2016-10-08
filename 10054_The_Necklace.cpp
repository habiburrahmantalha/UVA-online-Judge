#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
set<int>g[55];
set<int> :: iterator it;
//vector<int> g[55];
int beads[1010][3];
int n,s1,s2;
int visit[55][55];
bool f;
void find_beads(int x,int y,int k)
{
    int i;
    beads[k][0]=x;
    beads[k][1]=y;
    if(k==n && y==s1)
    {
        f=true;
        return;
    }

    for(it=g[y].begin();it!=g[y].end();it++)
    {
        if(visit[y][*it]>0)
        {
            visit[y][*it]-=1;
            visit[*it][y]-=1;
            find_beads(y,*it,k+1);
            if(f)
            break;
            visit[y][*it]+=1;
            visit[*it][y]+=1;
        }

    }
}
void print_necklece()
{
    int i;


    for(i=1;i<=n;i++)
        printf("%d %d\n",beads[i][0],beads[i][1]);
}
int main()
{
    int tc,i,a,b,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        scanf("%d %d",&s1,&s2);
        a=s1;
        b=s2;
        memset(visit,0,sizeof(visit));
        g[a].insert(b);
        g[b].insert(a);
        visit[a][b]++;
        visit[b][a]++;
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].insert(b);
            g[b].insert(a);

            visit[a][b]++;
            visit[b][a]++;


        }


        f=false;
        visit[s1][s2]=1;
        find_beads(s1,s2,1);
        printf("Case #%d\n",t++);
        if(!f)
            printf("some beads may be lost\n");
        else
            print_necklece();
        for(i=0;i<=n;i++)
            g[i].clear();
    }
    return 0;
}
