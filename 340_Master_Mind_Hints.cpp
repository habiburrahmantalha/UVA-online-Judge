#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int SC[1010],G[1010],fSC[10],fG[10],n;

int find_strong_match()
{
    int i,c=0;
    for(i=0;i<n;i++)
    if(SC[i]==G[i])
    c++;

    return c;
}
int find_match()
{
    int i,c=0;
    for(i=0;i<=9;i++)
    c+=min(fSC[i],fG[i]);

    return c;
}
int main()
{
    int t=1,i,a,b;
    while(scanf("%d",&n) && n)
    {
        memset(fSC,0,sizeof(fSC));
        for(i=0;i<n;i++)
        {
            scanf("%d",&SC[i]);
            fSC[SC[i]]++;
        }
        printf("Game %d:\n",t++);
        while(1)
        {
            memset(fG,0,sizeof(fG));
            for(i=0;i<n;i++)
            {
                scanf("%d",&G[i]);
                fG[G[i]]++;
            }
            if(fG[0]==n)
            break;

            a=find_strong_match();
            b=find_match();
            printf("    (%d,%d)\n",a,b-a);
        }
    }
    return 0;
}
