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

int G[5][5];

bool solvable()
{
    int i,j,k,a,b,c=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            k=j;
            for(a=i;a<4;a++)
            {
                for(b=k;b<4;b++)
                    if(G[i][j]>G[a][b] && G[a][b])
                        c++;
                k=0;
            }
        }
    }
    cout<<c<<endl;
    if(c&1)
        return false;
    return true;
}
int main()
{
    int tc,i,j;
    scanf("%d",&tc);
    while(tc--)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&G[i][j]);
            }
        }
        if(!solvable())
            printf("This puzzle is not solvable.\n");
        else
        {

        }
    }
    return 0;
}
