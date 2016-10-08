#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)


#define N 20
int n,m,cnt;
char g[N][N];
int column[N][N],row[N][N],squre[N][N][N];
struct Sudoku
{
    int i;
    int j;
    int c;
    Sudoku(int i,int j,int c): i(i),j(j),c(c) {}
    bool operator < (const Sudoku &that) const { return c < that.c; }
};
vector<Sudoku>next,next_ext[30];


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
            if(g[i][j]=='0' || isalpha(g[i][j]))
                return false;
    return true;
}


void print()
{
    int i,j;
    for(i=1;i<=m;i++)
        printf("%s\n",g[i]+1);

}
void SP()
{
    printf(".........\n");
}
void sudoku(int i,int j,int nxt)
{
    int k,l;
    if(g[i][j]=='o')
    {
        k=1;
        l=2;
    }
    else if(g[i][j]=='e')
    {
        k=2;
        l=2;
    }
    else
    {
        k=1;
        l=1;
    }
    for(;k<=m;k+=l)
    {
        if(valid(i,j,k))
        {
            column[j][k]=1;
            row[i][k]=1;
            squre[sc(i)][sc(j)][k]=1;
            char ch = g[i][j];
            g[i][j]=k+'0';

            if(complete())
            {
                cnt++;
                //return;
            }

            sudoku(next[nxt].i,next[nxt].j,nxt+1);

            column[j][k]=0;
            row[i][k]=0;
            squre[sc(i)][sc(j)][k]=0;
            g[i][j]=ch;
        }
    }
}
void reset()
{
    n=3;
    m=9;

    memset(column,0,sizeof(column));
    memset(row,0,sizeof(row));
    memset(squre,0,sizeof(squre));
    next.clear();
    for(int i=0;i<30;i++)
    next_ext[i].clear();
}
bool valid_ext(int i,int k)
{
    int j,a,b;
    for(j=0;j<next_ext[i].size();j++)
    {
        a=next_ext[i][j].i;
        b=next_ext[i][j].j;
        if(!valid(a,b,k))
            return false;

    }
    return true;

}
void sudoku_ext(int i)
{
    int k,a,b,j;
    for(k=1;k<=m;k++)
    {
        if(valid_ext(i,k))
        {
            for(j=0;j<next_ext[i].size();j++)
            {
                a=next_ext[i][j].i;
                b=next_ext[i][j].j;

                column[b][k]=1;
                row[a][k]=1;
                squre[sc(a)][sc(b)][k]=1;

                g[a][b]=k+'0';
            }
            for(;i<30;i++)
            if(next_ext[i].size())
            {
                sudoku_ext(i);
                break;
            }
            if(i==30)
            {
                if(next.size())
                    sudoku(next[0].i,next[0].j,1);
                else
                {
                    cnt++;


                }

            }
            for(j=0;j<next_ext[i].size();j++)
            {
                a=next_ext[i][j].i;
                b=next_ext[i][j].j;
                column[b][k]=0;
                row[a][k]=0;
                squre[sc(a)][sc(b)][k]=0;
                g[a][b]=i+'a';
            }


        }
    }
}
int one(int p)
{
    int i,j,k,c;
    i=next[p].i;
    j=next[p].j;
    c=0;
    for(k=1;k<=m;k++)
    {
        if(valid(i,j,k))
        {
            c++;
        }
    }
    return c;
}
int one_ext(int p,int q)
{
    int i,j,k,c;
    i=next_ext[p][q].i;
    j=next_ext[p][q].j;
    c=0;
    for(k=1;k<=m;k++)
    {
        if(valid(i,j,k))
        {
            c++;
        }
    }
    return c;
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        reset();

        for(i=1;i<=m;i++)
        {
            scanf("%s",g[i]+1);
            for(j=1;j<=m;j++)
            {
                if(g[i][j]=='0')
                    next.push_back(Sudoku(i,j,0));
                else if(isdigit(g[i][j]))
                {
                    column[j][g[i][j]-'0']=1;
                    row[i][g[i][j]-'0']=1;
                    squre[sc(i)][sc(j)][g[i][j]-'0']=1;
                }
                else if(g[i][j]=='e' || g[i][j]=='o')
                    next.push_back(Sudoku(i,j,0));
                else
                    next_ext[g[i][j]-'a'].push_back(Sudoku(i,j,0));
            }
        }
        for(i=0;i<next.size();i++)
        {
            next[i].c+=one(i);
        }
        sort(next.begin(),next.end());
        //for(i=0;i<next.size();i++)
        {
            //cout<<next[i].c<<endl;
        }
        for(i=0;i<30;i++)
        {
            if(next_ext[i].size())
            {
                for(j=0;j<next_ext[i].size();j++)
                {
                    next_ext[i][j].c+=one_ext(i,j);

                }
                sort(next_ext[i].begin(),next_ext[i].end());
            }
        }
        //continue;
        cnt=0;
        for(i=0;i<30;i++)
        if(next_ext[i].size())
        {
            sudoku_ext(i);
            break;
        }
        if(i==30)
        {
            if(next.size())
                sudoku(next[0].i,next[0].j,1);

        }
        printf("%d\n",cnt);



    }
    return 0;
}
