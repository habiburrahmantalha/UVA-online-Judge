//Problem Type : sorting
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
int c;
bool cmp(int a,int b)
{
    if(a>b)
    {
        c++;
        return false;
    }
    else
    {

        return true;
    }

}
int a[1000010];

int main()
{
    int n,i,j,temp;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        c=0;
        sort(a,a+n,cmp);

        printf("%d\n",c);
    }
    return 0;
}
