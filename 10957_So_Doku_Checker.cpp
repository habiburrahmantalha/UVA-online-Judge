#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

#define N 11
int n,m,cnt;

int column[N][N],row[N][N],squre[N][N][N];
vector<pair<int,int> >next;

int sc(int i)
{
    if(i<=3)
    return 1;
    else if(i<=6)
    return 2;
    else
    return 3;

}
bool valid(int i,int j,int k)
{
    if(column[j][k])
    return false;
    if(row[i][k])
    return false;
    if(squre[sc(i)][sc(j)][k])
    return false;

    return true;
}

bool complete(int g[N][N])
{
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        if(g[i][j]==0)
        return false;
    return true;
}
void print(int g[N][N])
{
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<m;j++)
        printf("%d ",g[i][j]);
        printf("%d\n",g[i][j]);
    }
}
void SP()
{
    printf(".........\n");
}
void sudoku(int i,int j,int g[N][N],int nxt)
{

    for(int k=1;k<=m;k++)
    {
        if(valid(i,j,k))
        {
            //print(g);
            //SP();
            //printf("%d %d\n",i,j);

            column[j][k]=1;
            row[i][k]=1;
            squre[sc(i)][sc(j)][k]=1;
            g[i][j]=k;

            if(complete(g))
            {
                //print(g);
                cnt++;
                return;
            }

            sudoku(next[nxt].first,next[nxt].second,g,nxt+1);

            if(cnt>1)
            return;

            column[j][k]=0;
            row[i][k]=0;
            squre[sc(i)][sc(j)][k]=0;
            g[i][j]=0;
        }
    }


}
void reset()
{
    n=3;
    m=9;
    cnt=0;
    memset(column,0,sizeof(column));
    memset(row,0,sizeof(row));
    memset(squre,0,sizeof(squre));
    next.clear();
}
int main()
{
    //freopen("in.txt","r",stdin);
    int g[N][N];
    int i,j,x,t=1;
    bool illegal,f;
    while(scanf("%d",&x)!=EOF)
    {
        reset();

        illegal=false;
        g[1][1]=x;
        f=true;

        for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        {
            if(!f)
            scanf("%d",&g[i][j]);
            f=false;

            if(g[i][j])
            {
                if(column[j][g[i][j]])
                illegal=true;
                column[j][g[i][j]]=1;

                if(row[i][g[i][j]])
                illegal=true;
                row[i][g[i][j]]=1;

                if(squre[sc(i)][sc(j)][g[i][j]])
                illegal=true;
                squre[sc(i)][sc(j)][g[i][j]]=1;

            }
            else
            {
                //if(corner_case(i,j))
                //f=true;
                next.push_back(make_pair(i,j));
            }
        }
        if(illegal)
        printf("Case %d: Illegal.\n",t++);
        else
        {
            if(next.size()==0)
            {
                cnt=1;
                //print(g);
            }
            else
            sudoku(next[0].first,next[0].second,g,1);

            if(cnt==0)
            printf("Case %d: Impossible.\n",t++);
            else if(cnt==1)
            printf("Case %d: Unique.\n",t++);
            else if(cnt>1)
            printf("Case %d: Ambiguous.\n",t++);
        }
    }
    return 0;
}

