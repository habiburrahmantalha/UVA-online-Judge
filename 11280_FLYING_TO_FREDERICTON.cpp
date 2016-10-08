#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;
#define inf 1000000000

int g[105][105],n,d[105];

void check_bellmanford()
{
    int i,j;

    for(i=n;i>=1;i--)
        for(j=n;j>=1;j--){
            if(d[j]>d[i]+g[i][j])


                d[j]=d[i]+g[i][j];
            }

}

int main()
{
    int tc,m,c,i,j,q,t=1;
    bool f=false;
    map<string,int>mp;
    char s1[22],s2[22];
    scanf("%d",&tc);
    while(tc--)
    {

        if(f)
            printf("\n");

        scanf("%d",&n);

        for(i=0;i<=n;i++)
        {

            for(j=0;j<=n;j++)
                g[i][j]=inf;
        }
        //memset(g,0x7F,sizeof(g));
        for(i=1;i<=n;i++)
        {
            scanf("%s",s1);
            mp[s1]=i;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s %s %d",s1,s2,&c);
            g[mp[s1]][mp[s2]]=min(c,g[mp[s1]][mp[s2]]);

        }
        printf("Scenario #%d\n",t++);
        scanf("%d",&q);

        for(i=0;i<q;i++)
        {

            scanf("%d",&c);
            //memset(d,0x7F,sizeof(d));
            for(j=0;j<=n;j++)
                d[j]=inf;
            d[1]=0;
            for(j=0;j<=c;j++)
            {
                check_bellmanford();
            }

            if(d[n]!=inf)
            printf("Total cost of flight(s) is $%d\n",d[n]);
            else
                printf("No satisfactory flights\n");



        }
        mp.clear();
        f=true;

    }
    return 0;
}
