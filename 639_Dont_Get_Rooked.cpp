//Problem Type :    backtrack
//Time :    .008
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

char g[5][5];
int n,cnt;

bool place(int x,int y)
{
    int a;
    a=x;
    while(a--)
    {
        if(g[a][y]=='R')
            return false;
        if(g[a][y]=='X')
            break;
    }
    a=x;
    while(a<n)
    {
        if(g[a][y]=='R')
            return false;
        if(g[a][y]=='X')
            break;
        a++;

    }
    a=y;
    while(a--)
    {
        if(g[x][a]=='R')
            return false;
        if(g[x][a]=='X')
            break;
    }
    a=y;
    while(a<n)
    {
        if(g[x][a]=='R')
            return false;
        if(g[x][a]=='X')
            break;
        a++;

    }
    return true;
}

void rook(int x,int y,int k)
{

    for(int i=x;i<n;i++)
    {
        for(int j=y;j<n;j++)
        {
            if(g[i][j]=='.' && place(i,j))
            {
                g[i][j]='R';
                rook(i,j,k+1);
                g[i][j]='.';
            }
        }

        y=0;

    }
    /*
    for(int i=0;i<n;i++)
    cout<<g[i]<<endl;
    cout<<"----"<<endl;
    */

    if(cnt<k)
        cnt=k;
}
int main()
{
    int i;
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        scanf("%s",&g[i]);

        cnt=0;
        rook(0,0,0);

        printf("%d\n",cnt);
    }
    return 0;
}
