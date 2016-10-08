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
    int n,i,j,Start[30],End[30],f[30],cnt;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&Start[i]);
            f[Start[i]]=i;
        }

        for(i=0;i<n;i++)
        scanf("%d",&End[i]);

        cnt=0;
        for(i=0;i<n;i++)
        {
            if(f[End[i]]>i)
            {
                for(j=f[End[i]];j>i;j--)
                {
                    f[Start[j]]=j-1;
                    f[Start[j-1]]=j;
                    swap(Start[j],Start[j-1]);
                    cnt++;



                }
            }

        }
        printf("%d\n",cnt);
    }
    return 0;
}
