#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

#define N 11

int n=3,m=9,cnt,Count;

int column[N][N],row[N][N],squre[N][N][N];

int solved[N][N];
int g[N][N];
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

bool complete()
{
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        if(g[i][j]==0)
        return false;
    return true;
}
bool completeS()
{
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        if(solved[i][j]==0)
        return false;
    return true;
}
void print(int h[N][N])
{
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<m;j++)
        printf("%d ",h[i][j]);
        printf("%d\n",h[i][j]);
    }
}

void print_solved(int h[N][N])
{
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        if(h[i][j]==0)
        printf(".");
        else
        printf("%d",h[i][j]);

        printf("\n");

    }
}
void SP()
{
    printf(".........\n");
}

void copy_solved()
{
    int i,j;
    for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
    solved[i][j]=g[i][j];
}

void new_sudoku(int i,int j,int nxt)
{
    for(int k=1;k<=m;k++)
    {
        //if(k!=p[i][j])
        if(valid(i,j,k))
        {
            column[j][k]=1;
            row[i][k]=1;
            squre[sc(i)][sc(j)][k]=1;
            solved[i][j]=k;


            if(completeS())
            {
                column[j][k]=0;
                row[i][k]=0;
                squre[sc(i)][sc(j)][k]=0;
                solved[i][j]=0;

                Count++;
                return;
            }
            new_sudoku(new_next[nxt].first,new_next[nxt].second,nxt+1);
            //new_sudoku(next[nxt].first,next[nxt].second,nxt+1);

            column[j][k]=0;
            row[i][k]=0;
            squre[sc(i)][sc(j)][k]=0;
            solved[i][j]=0;

            if(Count>1)
            return;
        }
    }
}

void sudoku(int i,int j,int nxt)
{
    for(int k=1;k<=m;k++)
    {
        if(valid(i,j,k))
        {
            column[j][k]=1;
            row[i][k]=1;
            squre[sc(i)][sc(j)][k]=1;
            g[i][j]=k;

            if(complete())
            {
                if(cnt==0)
                    copy_solved();

                column[j][k]=0;
                row[i][k]=0;
                squre[sc(i)][sc(j)][k]=0;
                g[i][j]=0;
                cnt++;
                return;
            }

            sudoku(next[nxt].first,next[nxt].second,nxt+1);

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
    cnt=0;
    memset(g,0,sizeof(g));
    memset(solved,0,sizeof(solved));
    memset(column,0,sizeof(column));
    memset(row,0,sizeof(row));
    memset(squre,0,sizeof(squre));
    next.clear();
    new_next.clear();

}
void mark_next()
{
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

void make_unique()
{

    int i,j,k,l,x,y;
    sudoku(next[0].first,next[0].second,1);

    //print_solved(g);
    //print_solved(solved);

    if(cnt==1)
    print_solved(g);
    else
    {
        //print_solved(solved);
        for(k=0;k<next.size();k++)
        {
            i=next[k].first;
            j=next[k].second;
            x=solved[i][j];
            column[j][x]=0;
            row[i][x]=0;
            squre[sc(i)][sc(j)][x]=0;
            solved[i][j]=0;
            new_next.push_back(make_pair(i,j));

            Count=0;
            new_sudoku(new_next[0].first,new_next[0].second,1);
            //new_sudoku(next[k+1].first,next[k+1].second,k+1);

            if(Count>1 || Count ==0)
            {
                i=next[k].first;
                j=next[k].second;

                solved[i][j]=x;
                column[j][x]=1;
                row[i][x]=1;
                squre[sc(i)][sc(j)][x]=1;
                new_next.pop_back();
            }
        }
        //printf("%d ",new_next.size());
        print_solved(solved);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    bool NL=false;

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
        //print();
        mark_next();
        make_unique();
        //print_solved();
    }
    return 0;
}
