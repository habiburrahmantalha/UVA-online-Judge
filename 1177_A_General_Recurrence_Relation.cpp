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
int f[100010];

int f0,f1,n,a,b;

int recurrence(int n)
{
    if(n==0)
        return f0;
    else if(n==1)
        return f1;
    else if(n<100010)
    {
        if(f[n])
            return f[n];
        else
            return f[n]=a*recurrence(n-1)+b*recurrence(n-2);
    }
    else
        return a*recurrence(n-1)+b*recurrence(n-2);



}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d %d %d",&f0,&f1,&a,&b,&n);
        memset(f,0,sizeof(f));
        printf("%d\n",recurrence(n));
    }
    return 0;
}
