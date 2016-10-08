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

bool f[30][10];
int n;
bool common(int i,int j)
{
    for(int k=0;k<=9;k++)
        if(f[i][k] && f[j][k])
            return true;
    return false;
}
bool check(int a[30])
{
    for(int i=0;i<n*n-n;i++)
    {
        if((i+1)%n!=0)
        {
            if(!common(a[i],a[i+1]))
                return false;
        }
        if(!common(a[i],a[i+n]))
                return false;

    }
    return true;
}
int main()
{
    int i,j,a[30],t=1,x;
    bool possible;

    while(scanf("%d",&n) &&  n)
    {
        if(t>1)
            printf("\n");
        memset(f,false,sizeof(f));

        for(i=0;i<n*n;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&x);
                f[i][x]=true;
            }
        }
        for(i=0;i<n*n;i++)
            a[i]=i;
        possible=false;
        do
        {
            if(check(a))
            {
                possible=true;
                break;
            }

        }while(next_permutation(a,a+n));

        if(possible)
            printf("Game %d: Possible\n",t++);
        else
            printf("Game %d: Impossible\n",t++);

    }
    return 0;
}
