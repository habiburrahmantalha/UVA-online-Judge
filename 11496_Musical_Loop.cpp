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


int main()
{
    int n,i,c,a[10010],f;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);

        if(a[0]>a[1])
        f=1;
        else
        f=2;

        c=0;
        for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                c++;
                while(a[i]>a[i+1])
                i++;

            }
            else
            {
                c++;
                while(a[i]<a[i+1])
                i++;

            }
            i--;
        }
        if(f==1)
        {
            if(a[n-2]>a[n-1])
            c++;
        }
        if(f==2)
        {
            if(a[n-2]<a[n-1])
            c++;
        }
        printf("%d\n",c);
    }
    return 0;
}
