//Problem Type :
//Time :
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

int T[10245][1025];

void kill(int x,int y,int d,int k)
{
    int i,j;
    for(i=x-d;i<=x+d;i++)
    {
        for(j=y-d;j<=y+d;j++)
        if(i>=0 && j>=0 && i<=1024 && j<=1024)
        T[i][j]+=k;
    }

}

int main()
{
    int tc,i,j,x,y,n,d,k,mx;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(T,0,sizeof(T));
        scanf("%d",&d);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&x,&y,&k);
            kill(x,y,d,k);

        }
        mx=0;
        for(i=0;i<1024;i++)
        for(j=0;j<1024;j++)
        {
            if(T[i][j]>mx)
            {
                mx=T[i][j];
                x=i;
                y=j;
            }
        }
        printf("%d %d %d\n",x,y,T[x][y]);

    }
    return 0;
}
