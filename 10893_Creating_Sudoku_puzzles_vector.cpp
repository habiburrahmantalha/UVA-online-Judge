#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

#define N 11
#define V2 vector<vector<int> >
int n,m,cnt,Count;

int column[N][N],row[N][N],squre[N][N][N];
int new_column[N][N],new_row[N][N],new_squre[N][N][N];
V2 solved;
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

bool complete(V2 g)
{
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        if(g[i][j]==0)
        return false;
    return true;
}
void print(V2 g)
{
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<m;j++)
        printf("%d ",g[i][j]);
        printf("%d\n",g[i][j]);
    }
}

void print_solved(V2 g)
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



void new_sudoku(int i,int j,V2 g,int nxt)
{

    for(int k=1;k<=m;k++)
    {
        if(valid(i,j,k))
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

                Count++;
                return;
            }

            new_sudoku(new_next[nxt].first,new_next[nxt].second,g,nxt+1);

            if(Count==2)
            return;

            new_column[j][k]=0;
            new_row[i][k]=0;
            new_squre[sc(i)][sc(j)][k]=0;
            g[i][j]=0;
        }
    }


}

void sudoku(int i,int j,V2 g,int nxt)
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
                if(cnt==0)
                solved=g;
                cnt++;
                return;
            }

            sudoku(next[nxt].first,next[nxt].second,g,nxt+1);

            //if(cnt==2)
            //return;

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
    solved.clear();

    memset(column,0,sizeof(column));
    memset(row,0,sizeof(row));
    memset(squre,0,sizeof(squre));
    next.clear();


    memset(new_column,1,sizeof(new_column));
    memset(new_row,1,sizeof(new_row));
    memset(new_squre,1,sizeof(new_squre));
    new_next.clear();

}
void mark_next(V2 g)
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
        g[i][j]=0;
    }
}

void make_unique(V2 g)
{

    int i,j,k,l,x;
    sudoku(next[0].first,next[0].second,g,1);
    printf("%d\n",cnt);
    if(cnt==1)
    print_solved(g);
    /*
    else
    {
        for(k=0;k<next.size();k++)
        {
            new_next.push_back(make_pair(i,j));

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
            Count=0;

            sudoku(new_next[0].first,new_next[0].second,solved,1);
            if(Count>1)
            {
                i=next[k].first;
                j=next[k].second;

                solved[i][j]=x;
                new_column[j][x]=1;
                new_row[i][x]=1;
                new_squre[sc(i)][sc(j)][x]=1;
                new_next.pop_back();
            }
        }
        print_solved(solved);
    }
    */
}
int main()
{
    freopen("in.txt","r",stdin);
    bool NL=false;
    V2 g;
    vector<int>gh;
    int i,j,k,t=1,tc;
    char x[20];

    scanf("%d",&tc);
    while(tc--)
    {
        if(NL)
        printf("\n");
        NL=true;

        reset();
        for(i=0;i<=9;i++)
        gh.push_back(0);
        g.push_back(gh);
        gh.clear();
        for(i=1;i<=9;i++)
        {
            scanf("%s",x);
            gh.push_back(0);
            for(j=0,k=1;k<=9;j++,k++)
            {
                if(x[j]=='.')
                gh.push_back(0);
                else
                gh.push_back(x[j]-'0');
            }
            g.push_back(gh);
            gh.clear();
        }

        mark_next(g);
        //solved=g;
        //print(solved);
        make_unique(g);

        g.clear();

    }
    return 0;
}


