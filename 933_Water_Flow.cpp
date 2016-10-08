#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    int n,i,t,d,end;
    bool f=false;
    char x[1100],y[100];
    int w[1100],p[1100];

    while(scanf("%[A-Z ]",y)==1)
    {
        if(f)
        printf("\n");
        f=true;

        scanf("%*[= ]");
        scanf("%[0-9]",y);
        n=atoi(y);
        gets(y);

        for(i=0;i<n;i++)
        {
            scanf("%[A-Z ]",y);
            x[i]=y[0];
            scanf("%*[= ]");
            scanf("%[0-9]",y);
            w[i]=atoi(y);
            scanf("%*[; ]");
        }
        gets(y);
        for(i=0;i<n-1;i++)
        {
            scanf("%[a-z ]",y);
            scanf("%*[= ]");
            scanf("%[0-9]",y);
            p[i]=atoi(y);
            scanf("%*[; ]");
        }
        gets(y);

        printf("  t");
        for(i=0;i<n;i++)
        printf("   %c",x[i]);
        printf("\n");
        for(i=0;i<n*4+3;i++)
        printf("-");
        printf("\n");
        end=w[0];
        t=0;
        while(1)
        {

            printf("%3d",t++);

            for(i=0;i<n;i++)
               printf(" %3d",w[i]);
            printf("\n");

            if(w[n-1]==end)
            break;

            for(i=n-1;i>0;i--)
            {
                d=min(w[i-1],p[i-1]);
                w[i]+=d;
                w[i-1]-=d;
            }
        }

    }

    return 0;
}
