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

int a[100010],b[100010];
int main()
{
    int tc,n,i,mx;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        mx=-150000000;
        for(i=0;i<n-1;i++)
        {
            b[i]=a[i]-a[i+1];
            if(b[i]+mx>b[i])
            b[i]=b[i]+mx;
            mx=max(b[i],mx);
        }
        printf("*%d\n",mx);



    }
    return 0;
}
