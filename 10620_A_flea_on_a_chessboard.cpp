//Problem Type : grid,addhoc
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

int g[1010][1010];
int line;
void to_1(int x,int y,int s)
{
    int i,j;
    for(i=x+1;i<x+s && i<=1000;i++)
        for(j=y+1;j<y+s && j<=1000;j++)
            g[i][j]=1;

}
void make_grid(int s)
{
    memset(g,0,sizeof(g));
    int i,j;
    for(i=0;i<=1000;i+=(s*2))
        for(j=0;j<=1000;j+=(s*2))
            to_1(i,j,s);
    for(i=s;i<=1000;i+=(s*2))
        for(j=s;j<=1000;j+=(s*2))
            to_1(i,j,s);
}
void print()
{
    int i,j;
    for(i=0;i<50;i++)
    {for(j=0;j<50;j++)
        printf("%d",g[i][j]);
        printf("\n");
}
}
bool white(int x,int y,int s)
{
    int a=floor(x/s);
    int b=floor(y/s);
    //cout<<a<<" "<<b<<endl;
    if(x%s==0 || y%s==0)
    {
        line++;
        return false;
    }

    if(a&1 && b%2==0)
    return true;

    if(a%2==0 && b&1)
    return true;

    line++;
    return false;

}
int main()
{
    int s,x,y,dx,dy,c;
    bool f;
    while(scanf("%d %d %d %d %d",&s,&x,&y,&dx,&dy) && s+x+y+dx+dy)
    {
        //make_grid(s);
        //print();
        c=0;
        f=false;
        line=0;
        while(1)
        {
            //cout<<x<<" "<<y<<endl;
            //if(!g[x][y])
            if(white(x,y,s))
            {
                f=true;
                break;
            }
            x+=dx;
            y+=dy;
            c++;
            if(line>1005)
            break;
        }
        if(f)
        printf("After %d jumps the flea lands at (%d, %d).\n",c,x,y);
        else
        printf("The flea cannot escape from black squares.\n");
    }
    return 0;
}
