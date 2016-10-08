#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;


int main()
{
    int x[710],y[710],a,b,i,j,k,n,mx,c,tc;
    char str[20];
    scanf("%d",&tc);
    gets(str);
    gets(str);
    while(tc--)
    {
        n=0;
        while(gets(str) && strlen(str)!=0)
        {
            sscanf(str,"%d %d",&x[n],&y[n]);
            n++;

        }

        mx=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                a=x[j]-x[i];
                b=y[j]-y[i];
                c=0;
                for(k=0;k<n;k++)
                if(y[k]*a-x[k]*b==y[i]*a-x[i]*b)
                c++;
                mx=max(c,mx);
            }
        }
        printf("%d\n",mx);
        if(tc)
        printf("\n");
    }
    return 0;
}
