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

struct table
{
    int c,i;
};
table T[1010][1010];
int n,m,a[1010],b[1010];

void LCS_LIS()
{
    memset(T,0,sizeof(T));

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[i])
            {
                T[i][j].c=T[i-1][j-1].c+1;
                for(k=0)
            }

        }
    }

}
int main()
{
    int tc,i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

        scanf("%d",&m);
        for(i=1;i<=m;i++)
        scanf("%d",&b[i]);

        LCS_LIS();

    }
    return 0;
}
