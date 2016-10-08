#include<stdio.h>
/*
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
*/

int main()
{
    int t=1,T[10],i,tc,h,m,s,H[10],M[10],S[10];
    for(i=0;i<=5;i++)
    {
        T[i]=1<<i;

    }
    scanf("%d",&tc);
    while(tc--)
    {
        for(i=0;i<=5;i++)
            H[i]=M[i]=S[i]=0;
        scanf("%d:%d:%d",&h,&m,&s);
        for(i=5;i>=0;i--)
        {
            if(h>=T[i])
            {
                H[i]=1;
                h-=T[i];
            }
        }
        for(i=5;i>=0;i--)
        {
            if(m>=T[i])
            {
                M[i]=1;
                m-=T[i];
            }
        }
        for(i=5;i>=0;i--)
        {
            if(s>=T[i])
            {
                S[i]=1;
                s-=T[i];
            }
        }
        printf("%d ",t++);
        for(i=5;i>=0;i--)
            printf("%d%d%d",H[i],M[i],S[i]);
        printf(" ");
        for(i=5;i>=0;i--)
            printf("%d",H[i]);
        for(i=5;i>=0;i--)
            printf("%d",M[i]);
        for(i=5;i>=0;i--)
            printf("%d",S[i]);
        printf("\n");

    }
    return 0;
}
