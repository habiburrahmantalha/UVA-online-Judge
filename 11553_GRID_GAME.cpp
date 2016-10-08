//Problem Type : permutation
//Time :    .012
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


int main()
{
    int tc,i,j,x[10],g[10][10],mx,sum,n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&g[i][j]);
        for(i=0;i<n;i++)
            x[i]=i;
        mx=20000000;
        do
        {
            sum=0;
            for(i=0;i<n;i++)
            sum+=g[i][x[i]];
            if(sum<mx)
                mx=sum;
        }while(next_permutation(x,x+n));

        printf("%d\n",mx);

    }
    return 0;
}
