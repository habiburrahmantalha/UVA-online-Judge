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

char g[10][10];
bool T[10][10];

int X[]={-1,-1,-1,0,1,1,1,0};
int Y[]={-1,0,1,1,1,0,-1,-1};
int Xk[]={-1,-2,-2,-1,1,2,2,1};
int Yk[]={-2,-1,1,2,2,1,-1,-2};


void print()
{
    int i,j;
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
            printf("%c",g[i][j]);
        printf("\n");
    }
}
bool valid(int x,int y)
{
    if(x<1 || y<1 || x>8 || y>8)
    return false;
    return true;
}
void king(int x,int y)
{
    int i,j,xx,yy;
    T[x][y]=true;
    for(i=0;i<8;i++)
    {
        xx=x+X[i];
        yy=y+Y[i];
        if(valid(xx,yy))
        T[xx][yy]=true;
    }
}
void queen(int x,int y)
{
    int i,j,xx,yy;
    T[x][y]=true;
    for(i=0;i<8;i++)
    for(j=1;j<=8;j++)
    {
        xx=x+X[i]*j;
        yy=y+Y[i]*j;
        if(valid(xx,yy))
        {
            T[xx][yy]=true;
            if(g[xx][yy]!=0)
            break;
        }
        else
        break;
    }
}
void knight(int x,int y)
{
    int i,j,xx,yy;
    T[x][y]=true;
    for(i=0;i<8;i++)
    {
        xx=x+Xk[i];
        yy=y+Yk[i];
        if(valid(xx,yy))
        T[xx][yy]=true;
    }

}
void bishop(int x,int y)
{
    int i,j,xx,yy;
    T[x][y]=true;
    for(i=0;i<8;i+=2)
    for(j=1;j<=8;j++)
    {
        xx=x+X[i]*j;
        yy=y+Y[i]*j;
        if(valid(xx,yy))
        {
            T[xx][yy]=true;
            if(g[xx][yy]!=0)
            break;
        }
        else
        break;
    }
}
void rock(int x,int y)
{
    int i,j,xx,yy;
    T[x][y]=true;
    for(i=1;i<8;i+=2)
    for(j=1;j<=8;j++)
    {
        xx=x+X[i]*j;
        yy=y+Y[i]*j;
        if(valid(xx,yy))
        {
            T[xx][yy]=true;
            if(g[xx][yy]!=0)
            break;
        }
        else
        break;
    }
}
void pown(int x,int y,int z)
{
    T[x][y]=true;
    if(z==1)
        T[x+1][y-1]=T[x+1][y+1]=true;
    if(z==2)
        T[x-1][y-1]=T[x-1][y+1]=true;
}
void attacked_place()
{
    int i,j;
    memset(T,false,sizeof(T));

    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            if(g[i][j]=='K' || g[i][j]=='k')
            king(i,j);
            if(g[i][j]=='Q' || g[i][j]=='q')
            queen(i,j);
            if(g[i][j]=='N' || g[i][j]=='n')
            knight(i,j);
            if(g[i][j]=='B' || g[i][j]=='b')
            bishop(i,j);
            if(g[i][j]=='R' || g[i][j]=='r')
            rock(i,j);
            if(g[i][j]=='P')
            pown(i,j,2);
            if(g[i][j]=='p')
            pown(i,j,1);
        }
    }
    int c=0;
    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++)
        if(T[i][j])
        c++;
    printf("%d\n",64-c);
}
int main()
{
    char EFN[70],i,j,k;
    while(scanf("%s",&EFN)==1)
    {
        i=j=1;
        memset(g,0,sizeof(g));
        for(k=0;EFN[k];k++)
        {
            if(EFN[k]=='/')
            {
                i++;
                j=1;
                continue;
            }
            if(isdigit(EFN[k]))
            {
                j+=EFN[k]-'0';

                continue;
            }
            g[i][j]=EFN[k];
            j++;
        }
        //print();

        attacked_place();
    }
    return 0;
}
