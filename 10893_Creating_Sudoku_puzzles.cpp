#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

#define N 11

int n,m,cnt,Count;

int column[N][N],row[N][N],squre[N][N][N];
int new_column[N][N],new_row[N][N],new_squre[N][N][N];
int solved[N][N];
vector<pair<int,int> >next,new_next;


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
bool new_valid(int i,int j,int k)
{
    if(new_column[j][k])
    return false;
    if(new_row[i][k])
    return false;
    if(new_squre[sc(i)][sc(j)][k])
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

void print_solved(int g[N][N])
{
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        if(g[i][j]==0)
        printf(".");
        else
        printf("%d",g[i][j]);

        printf("\n");

    }
}
void SP()
{
    printf(".........\n");
}

void copy_solved(int g[N][N])
{
    int i,j;
    for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
    solved[i][j]=g[i][j];
}


void new_sudoku(int i,int j,int g[N][N],int nxt)
{

    for(int k=1;k<=m;k++)
    {
        if(new_valid(i,j,k))
        {
            //print(g);
            //SP();
            //printf("%d %d\n",i,j);

            new_column[j][k]=1;
            new_row[i][k]=1;
            new_squre[sc(i)][sc(j)][k]=1;
            g[i][j]=k;

            if(complete(g))
            {
                new_column[j][k]=0;
                new_row[i][k]=0;
                new_squre[sc(i)][sc(j)][k]=0;
                g[i][j]=0;

                Count++;
                return;
            }

            new_sudoku(new_next[nxt].first,new_next[nxt].second,g,nxt+1);



            new_column[j][k]=0;
            new_row[i][k]=0;
            new_squre[sc(i)][sc(j)][k]=0;
            g[i][j]=0;

            if(Count>1)
            return;
        }
    }


}

void sudoku(int i,int j,int g[N][N],int nxt)
{

    for(int k=1;k<=m;k++)
    {
        if(valid(i,j,k))
        {
            //print(h);
            //SP();
            //printf("%d %d\n",i,j);

            column[j][k]=1;
            row[i][k]=1;
            squre[sc(i)][sc(j)][k]=1;
            g[i][j]=k;

            if(complete(g))
            {
                if(cnt==0)
                    copy_solved(g);

                column[j][k]=0;
                row[i][k]=0;
                squre[sc(i)][sc(j)][k]=0;
                g[i][j]=0;
                cnt++;
                return;
            }

            sudoku(next[nxt].first,next[nxt].second,g,nxt+1);

            column[j][k]=0;
            row[i][k]=0;
            squre[sc(i)][sc(j)][k]=0;
            g[i][j]=0;

            if(cnt>1)
            return;
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


    memset(new_column,1,sizeof(new_column));
    memset(new_row,1,sizeof(new_row));
    memset(new_squre,1,sizeof(new_squre));
    new_next.clear();

}
void mark_next(int g[N][N])
{
    //print_solved(g);
    //SP();
    int i,j;
    for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
    {
        if(g[i][j])
        {
            column[j][g[i][j]]=1;
            row[i][g[i][j]]=1;
            squre[sc(i)][sc(j)][g[i][j]]=1;
        }
        else
            next.push_back(make_pair(i,j));
    }
}

void make_unique(int g[N][N])
{
    //print_solved(g);
    //SP();

    int i,j,k,l,x,y;
    sudoku(next[0].first,next[0].second,g,1);
    if(cnt==1)
    print_solved(g);

    else
    {
        //print_solved(solved);
        for(k=0;k<next.size();k++)
        {
            i=next[k].first;
            j=next[k].second;
            y=solved[i][j];
            new_column[j][y]=0;
            new_row[i][y]=0;
            new_squre[sc(i)][sc(j)][y]=0;
            solved[i][j]=0;
            new_next.push_back(make_pair(i,j));
            //value.push_back()
            /*
            for(l=0;l<new_next.size();l++)
            {
                i=next[l].first;
                j=next[l].second;
                x=solved[i][j];
                new_column[j][x]=0;
                new_row[i][x]=0;
                new_squre[sc(i)][sc(j)][x]=0;
                solved[i][j]=0;
            }
            */
            Count=0;

            new_sudoku(new_next[0].first,new_next[0].second,solved,1);
            //printf("%d ",Count);
            if(Count>1)
            {
                i=next[k].first;
                j=next[k].second;

                solved[i][j]=y;
                new_column[j][y]=1;
                new_row[i][y]=1;
                new_squre[sc(i)][sc(j)][y]=1;
                new_next.pop_back();
            }
        }
        //printf("%d ",new_next.size());
        print_solved(solved);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    bool NL=false;
    int g[N][N];
    int i,j,k,t=1,tc;
    char x[20];

    scanf("%d",&tc);
    while(tc--)
    {
        if(NL)
        printf("\n");
        NL=true;

        reset();

        for(i=1;i<=9;i++)
        {
            scanf("%s",x);

            for(j=0,k=1;k<=9;j++,k++)
            {
                if(x[j]=='.')
                g[i][k]=0;
                else
                g[i][k]=x[j]-'0';
            }
        }
        //print(g);

        mark_next(g);

        make_unique(g);

        //SP();
        //copy_solved(g);
        //print_solved(g);

    }
    return 0;
}


