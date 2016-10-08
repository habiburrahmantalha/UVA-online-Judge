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
int n,m;
bool result;

int column[N][N],row[N][N],squre[N][N][N];
char G[N][N];

struct Sudoku
{
    int i;
    int j;
    int c;
    Sudoku(int i,int j,int c): i(i),j(j),c(c) {}
    bool operator < (const Sudoku &that) const { return c < that.c; }
};
vector<Sudoku>next;
void reset()
{
    n=4;
    m=16;
    result=false;
    memset(column,0,sizeof(column));
    memset(row,0,sizeof(row));
    memset(squre,0,sizeof(squre));
    next.clear();
}
int sc(int i)
{
    if(i<=4)
    return 1;
    if(i<=8)
    return 2;
    if(i<=12)
    return 3;

    return 4;
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
            if(G[i][j]=='-')
                return false;
    return true;
}
void print()
{
    int i;
    for(i=1;i<=m;i++)
        printf("%s\n",G[i]+1);
}
void sudoku(int i,int j,int nxt)
{
    if(nxt==next.size())
        print();
    if(result)
    return;

    for(int k=1;k<=m;k++)
    {
        if(valid(i,j,k))
        {

            //printf("------------------\n");
            //printf("%d %d\n",i,j);

            column[j][k]=1;
            row[i][k]=1;
            squre[sc(i)][sc(j)][k]=1;
            G[i][j]=k-1+'A';

            if(complete())
            {
                print();
                result=true;
                return;
            }

            sudoku(next[nxt].i,next[nxt].j,nxt+1);
            if(result)
            return;

            column[j][k]=0;
            row[i][k]=0;
            squre[sc(i)][sc(j)][k]=0;
            G[i][j]='-';
        }
    }


}
int one(int p)
{
    int i,j,k,c,d;
    i=next[p].i;
    j=next[p].j;
    c=0;
    d=0;
    for(k=1;k<=m;k++)
    {
        if(valid(i,j,k))
        {
            c++;
            //d=k;
        }
    }
    return c;
    cout<<c<<endl;
    if(c==1)
    {
        column[j][d]=1;
        row[i][d]=1;
        squre[sc(i)][sc(j)][d]=1;
        G[i][j]=d-1+'A';
        return true;

    }
    return false;

}
int main()
{
    int i,j;
    reset();
    for(i=1;i<=m;i++)
    {
        scanf("%s",G[i]+1);
        for(j=1;j<=m;j++)
        {
            if(G[i][j]!='-')
            {
                column[j][G[i][j]-'A'+1]=1;
                row[i][G[i][j]-'A'+1]=1;
                squre[sc(i)][sc(j)][G[i][j]-'A'+1]=1;
            }
            else
            next.push_back(Sudoku(i,j,0));
        }
    }
    //bool f=true;
    //while(f)
    {
        //f=false;
        for(i=0;i<next.size();i++)
        {
            next[i].c+=one(i);
        }
    }
    sort(next.begin(),next.end());
    for(i=0;i<next.size();i++)
        cout<<next[i].c<<endl;
    //print();
    sudoku(next[0].i,next[0].j,1);
    return 0;
}
