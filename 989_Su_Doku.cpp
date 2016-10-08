#include<stdio.h>//sudoku
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

#define N 20
int n,m;
bool result;

int column[N][N],row[N][N],squre[N][N][N];
vector<pair<int,int> >next;

int sc(int i)
{
    if(n==1)
    return 1;
    if(n==2)
    {
        if(i<=2)
        return 1;
        else
        return 2;
    }
    if(n==3)
    {
        if(i<=3)
        return 1;
        else if(i<=6)
        return 2;
        else
        return 3;
    }
    if(n==4)
    {
        if(i<=4)
        return 1;
        else if(i<=8)
        return 2;
        if(i<=12)
        return 3;
        else
        return 4;
    }
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

    if(result)
    return;

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
                print(g);
                result=true;
                return;
            }

            sudoku(next[nxt].first,next[nxt].second,g,nxt+1);
            if(result)
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
    result=false;
    memset(column,0,sizeof(column));
    memset(row,0,sizeof(row));
    memset(squre,0,sizeof(squre));
    next.clear();
}





//page 3
int main()
{
    int g[N][N];
    int i,j;
    bool nl=false,f;
    while(scanf("%d",&n)==1)
    {
        if(nl)
        printf("\n");
        nl=true;

        f=false;

        m=n*n;
        reset();

        for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        {
            scanf("%d",&g[i][j]);
            if(g[i][j])
            {
                if(column[j][g[i][j]])
                f=true;
                column[j][g[i][j]]=1;

                if(row[i][g[i][j]])
                f=true;
                row[i][g[i][j]]=1;

                if(squre[sc(i)][sc(j)][g[i][j]])
                f=true;
                squre[sc(i)][sc(j)][g[i][j]]=1;
            }
            else
            next.push_back(make_pair(i,j));
        }
        if(!f)
        {
            if(next.size()==0)
            {
                result=true;
                print(g);
            }
            else
            sudoku(next[0].first,next[0].second,g,1);
        }
        if(!result)
        printf("NO SOLUTION\n");
    }
    return 0;
}
