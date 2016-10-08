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
int a[1000010];

int main()
{
    int n,i,c;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);

        for(i=1;i<n;i++)
        {
            if(a[i]+a[i-1]>a[i])
            a[i]=a[i]+a[i-1];
            else
            a[i]=a[i];
        }
        c=0;
        for(i=0;i<n;i++)
            if(a[i]>=0)
                c++;
        printf("%d\n",c);
    }
    return 0;
}
