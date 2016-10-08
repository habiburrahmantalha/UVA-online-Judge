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

bool f[5010];
void repeated()
{
    int g[11];
    memset(f,true,sizeof(f));
    int y,i,x;
    for(i=1;i<5001;i++)
    {
        memset(g,false,sizeof(g));
        x=i;
        while(x)
        {
            y=x%10;
            if(g[y])
            {
                f[i]=false;
                break;
            }
            else
            g[y]=true;

            x/=10;
        }
    }
}

int main()
{
    int m,n,i,c;
    repeated();
    while(scanf("%d %d",&n,&m)==2)
    {
        c=0;
        for(i=n;i<=m;i++)
        {
            if(f[i])
            c++;
        }
        printf("%d\n",c);
    }
    return 0;
}
