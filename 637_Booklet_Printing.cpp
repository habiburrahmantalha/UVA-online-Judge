//Problem Type : addhoc
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
    int n,m,i,j,a[220][2];
    while(scanf("%d",&n) && n)
    {
        memset(a,0,sizeof(a));
        m=ceil((double)n/4);
        j=0;
        for(i=1;i<=m*2;i+=2)
        {
            a[j++][1]=i;
            if(i+1>n)
            break;
            a[j++][0]=i+1;
        }
        j--;
        for(i=m*2+1;i<=n;i+=2)
        {
            a[j--][1]=i;
            if(i+1>n)
            break;
            a[j--][0]=i+1;
        }
        j=1;
        printf("Printing order for %d pages:\n",n);
        for(i=0;i<m*2;i++)
        {
            if(a[i][0]==0 && a[i][1]==0)
            continue;
            else if(a[i][0]==0)
            printf("Sheet %d, front: Blank, %d\n",j,a[i][1]);
            else if(a[i][1]==0)
            printf("Sheet %d, front: %d, Blank\n",j,a[i][0]);
            else
            printf("Sheet %d, front: %d, %d\n",j,a[i][0],a[i][1]);

            i++;
            if(a[i][0]==0 && a[i][1]==0)
            continue;
            else if(a[i][0]==0)
            printf("Sheet %d, back : Blank, %d\n",j,a[i][1]);
            else if(a[i][1]==0)
            printf("Sheet %d, back : %d, Blank\n",j,a[i][0]);
            else
            printf("Sheet %d, back : %d, %d\n",j,a[i][0],a[i][1]);
            j++;
        }

    }
    return 0;
}
